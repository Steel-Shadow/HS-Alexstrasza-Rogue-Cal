#include <iostream>
#include <filesystem>
#include <string>
#include "deck.h"
#include "auto.h"

#include <fstream>

int cid2secret(const std::string &s) {
    if (s == "REV_825") return 0;
    if (s == "LOOT_214") return 1;
    if (s == "LOOT_204") return 2;
    return -1;
}

cardname cid2cn(const std::string &s) {
    if (s.find("EX1_144") != -1) return shadowstep;
    if (s.find("CS2_072") != -1) return backstab;
    if (s == "SW_412") return extortion;
    if (s == "REV_939") return bonespike;
    if (s.find("COIN") != -1) return fakecoin;
    if (s == "GAME_005") return fakecoin;
    if (s == "CFM_630") return fakecoin;
    if (s.find("EX1_145") != -1) return preparation;
    if (s == "SCH_352") return illusionpotion;
    if (s == "TRL_092") return sharkspirit;
    if (s.find("LOE_077") != -1) return brann;
    if (s == "DMF_511") return foxyfraud;
    if (s == "SW_070") return mailboxdancer;
    if (s == "SCH_159") return invalid; //special: illucia must be set manually
    if (s == "BAR_552") return cutterbutter;
    if (s == "DMF_071") return redsmoke;
    if (s == "OG_291") return shadowcaster;
    if (s.find("LOOT_516") != -1) return zolag;
    if (s.find("ICC_910") != -1) return spectralpillager; //new fix: core version
    if (s == "LOOT_211") return elvensinger;
    if (s.find("REV_938") != -1) return anyspell;
    if (s == "TSC_916") return fishin;
    if (s == "ULD_715") return madnessplague;
    if (s == "DED_004") return anyweapon;
    if (s == "DMF_515") return swindle;
    if (s == "WC_016") return shroud;
    if (s == "REV_825") return anyspell;
    if (s == "LOOT_214") return evasion;
    if (s == "DMF_512") return anyspell;
    if (s == "LOOT_204") return anyspell;
    if (s == "RLK_567") return demise;

    if (s == "LEG_CS3_031") return alexstrasza;
    if (s == "ETC_080") return ETC;
    if (s == "ETC_079") return bounceAround;
    return invalid;
}

int cid2oc(const std::string &s) {
    // 简化原有冗余逻辑
    return originalcost_c(cid2cn(s));
}

std::string idhandle[4] = {
        " id=",
        " ID=",
        " Entity=",
        " EntityID="
};

std::string pidhandle = " PlayerID=";
std::string namehandle = " PlayerName=";

int mycid = -1;
int myid = -1;
int mypid = -1;
std::string myname;
int myhid = -1;

int yourcid = -1;
int yourid = -1;
int yourpid = -1;
std::string yourname;
int yourhid = -1;

const int Gid = 1;
const std::string Gname = "GameEntity";

std::map<int, std::map<std::string, std::pair<int, std::string>>> id2tag2stamp_value;
int stampcnt;

void updid(int x) {
    if (x == 0) {
        return;
    }

    if (mycid == -1 && id2tag2stamp_value[x]["ZONE"].second == "HAND" && !id2tag2stamp_value[x]["CardID"].second.empty()) {
        mycid = id2tag2stamp_value[x]["CONTROLLER"].second[0] - 48;

        rep(i, 2, 3) {
            if (mycid == id2tag2stamp_value[i]["CONTROLLER"].second[0] - 48) {
                myid = i;
                mypid = id2tag2stamp_value[i]["PlayerID"].second[0] - 48;
            }
        }

        assert(mycid == 1 || mycid == 2);
        assert(mycid + 1 == myid);
        assert(mycid == mypid);

        yourcid = 3 - mycid;
        yourid = yourcid + 1;
        yourpid = yourcid;
    }

    if (id2tag2stamp_value[x]["CARDTYPE"].second == "HERO") {
        if (mycid != -1 && mycid == id2tag2stamp_value[x]["CONTROLLER"].second[0] - 48) {
            myhid = x;
        }
        if (yourcid != -1 && yourcid == id2tag2stamp_value[x]["CONTROLLER"].second[0] - 48) {
            yourhid = x;
        }
    }
}

void updname(std::string s) {
    auto p = s.find(namehandle);
    if (p != -1) {
        p = p + namehandle.length();
        std::string t = s.substr(p);
        p = t.find(" ");
        if (p != -1) {
            t = t.substr(0, p - 1);
        }

        p = s.find(pidhandle);
        p = p + pidhandle.length();
        if (mypid == s[p] - 48) {
            myname = t;
        }
        if (yourpid == s[p] - 48) {
            yourname = t;
        }
    }
}

int updcurid(std::string s, int x) {
    rep(i, 0, 3) {
        if (s.find(idhandle[i] + Gname) != -1) {
            return Gid;
        }
        if (!myname.empty() && s.find(idhandle[i] + myname) != -1) {
            return myid;
        }
        if (!yourname.empty() && s.find(idhandle[i] + yourname) != -1) {
            return yourid;
        }

        auto p = s.find(idhandle[i]);
        if (p != -1) {
            x = 0;
            p = p + idhandle[i].length();
            while (p < s.length() && s[p] >= '0' && s[p] <= '9') {
                x = x * 10 + s[p] - '0';
                p = p + 1;
            }
            return x;
        }
    }
    return x;
}

std::map<int, int> id2initialController;
std::map<int, std::string> id2initialcardid;

std::map<int, int> id2handpos;

std::vector<std::string> valids;

fs::path findNewestDirectory(const std::string &installationPath) {
    fs::path newestDir;
    auto allLogsPath = installationPath / fs::path("Logs");

    // 检查路径是否存在并且是目录
    if (!fs::exists(allLogsPath) || !fs::is_directory(allLogsPath)) {
        std::cerr << "The provided path is not a valid directory." << std::endl;
        return "";
    }

    // 遍历目录中的每个文件和文件夹
    for (const auto &entry: fs::directory_iterator(allLogsPath)) {
        if (entry.is_directory()) {
            std::string dirName = entry.path().filename().string();

            // 更新最大字典序文件夹名
            if (dirName > newestDir.string()) {
                newestDir = dirName;
            }
        }
    }

    return fs::path(allLogsPath) / fs::path(newestDir);
}

void initId() {
    mycid = -1;
    myid = -1;
    mypid = -1;
    myname = "";
    myhid = -1;

    yourcid = -1;
    yourid = -1;
    yourpid = -1;
    yourname = "";
    yourhid = -1;

    id2tag2stamp_value.clear();
    stampcnt = 0;

    id2initialController.clear();
    id2initialcardid.clear();

    id2handpos.clear();
}

state autoRead(std::string _s, int &_tar, int &countsLimit) {
    fs::path logFilePath = findNewestDirectory(_s);
    std::ifstream logFile(logFilePath / "Power.log");

    std::string __s;

    valids.clear();

    int counts = 0;

    while (getline(logFile, __s)) {
        if (__s.find("GameState.DebugPrintOptions() - id") != -1) counts++;
        if (counts >= countsLimit) break;

        if (__s.find("- CREATE_GAME") != -1) {
            valids.clear();
        }
        valids.push_back(__s);
    }

    countsLimit = counts;

    //将唯一有效段存至valids，以下仅对这段进行读取

    int curid = 0;
    std::string tempStr, u, v, lu, lv;

    for (auto str: valids) {
        if (str.find("- CREATE_GAME") != -1) {
            curid = 0;
            initId();
        }
        updid(curid);
        updname(str);
        curid = updcurid(str, curid);

        while (!str.empty()) {
            auto p = std::min(std::min(str.find("["), str.find("]")), str.find(" "));
            if (p != -1) {
                tempStr = str.substr(0, p);
                str = str.substr(p + 1);
            } else {
                tempStr = str;
                str = "";
            }
            p = tempStr.find('=');
            if (p != -1) {
                u = tempStr.substr(0, p); // 等号左边
                v = tempStr.substr(p + 1); // 等号右边

                if (lu == "tag" && u == "value") {
                    u = lv;
                    lu = "";
                    lv = "";
                }

                id2tag2stamp_value[curid][u] = std::make_pair(stampcnt++, v);

                if (u == "CONTROLLER" && id2initialController[curid] == 0) {
                    id2initialController[curid] = atoi(v.c_str());
                }
                if (u == "CardID" && id2initialcardid[curid].empty()) {
                    id2initialcardid[curid] = v;
                }

                lu = u;
                lv = v;
            }
        }
    }

    valids.clear();

    //读取完毕，开始转化

    state autost = emptyst;

    stabable = 0;
    boneable = 0;
    spelldebuff = 0;
    miniondebuff = 0;
    battlecrydebuff = 0;
    iceblockif = 0;

    int nidn = 0;
    minionname notindeck[99] = {};

    int oppotaunt = 0;

    int handsecret[10] = {};

    const int secretmax = 4;
    int secretcheapest[secretmax] = {999, 999, 999, 999};

    int _demiseif = 0;
    int _demisepos = -1;
    int _demisepos2 = -1;

    for (auto &[id, tag2stamp_value]: id2tag2stamp_value) {

        if (tag2stamp_value["ZONE"].second == "SECRET" && tag2stamp_value["CONTROLLER"].second == std::to_string(mycid)) {
            std::string cid = tag2stamp_value["CardID"].second;
            int d = cid2secret(cid);
            if (d >= 0) {
                secretcheapest[d] = -999;
            }
        }

        // 加入手牌
        if (tag2stamp_value["ZONE"].second == "HAND"
            && tag2stamp_value["CONTROLLER"].second == std::to_string(mycid)) {
            std::string cid = tag2stamp_value["CardID"].second;
            cardname a = cid2cn(cid);
            int b = cid2oc(cid);
            int c = atoi(tag2stamp_value["HEALTH"].second.c_str());
            int p = atoi(tag2stamp_value["ZONE_POSITION"].second.c_str());

            id2handpos[id] = p;
            autost.hands[p - 1] = cardcons(a, b, c);
            autost.H++;

            int d = cid2secret(cid);
            handsecret[p - 1] = d;
        }

        // 本方打出随从
        if (tag2stamp_value["ZONE"].second == "PLAY"
            && tag2stamp_value["CARDTYPE"].second == "MINION"
            && tag2stamp_value["CONTROLLER"].second == std::to_string(mycid)) {
            minionname a = cn2mn(cid2cn(tag2stamp_value["CardID"].second));
            int b = atoi(tag2stamp_value["HEALTH"].second.c_str());
            int c = atoi(tag2stamp_value["DAMAGE"].second.c_str());
            int p = atoi(tag2stamp_value["ZONE_POSITION"].second.c_str());

            if (a == sharkspirit_m) {
                if (atoi(tag2stamp_value["SILENCED"].second.c_str()) == 1) {
                    a = sharkspirit_mx;
                }
            }

            autost.fields[p - 1] = minioncons(a, b, b - c);
            autost.F++;
        }

        // 对方打出随从
        if (tag2stamp_value["ZONE"].second == "PLAY"
            && tag2stamp_value["CARDTYPE"].second == "MINION"
            && tag2stamp_value["CONTROLLER"].second == std::to_string(yourcid)) {
            std::string cid = tag2stamp_value["CardID"].second;
            if (cid == "FP1_017") {
                battlecrydebuff += 2;
            }
            if (cid == "ICC_706") {
                spelldebuff += 2;
            }
            if (cid == "REV_837") {
                miniondebuff += 2;
            }
            if (atoi(tag2stamp_value["DAMAGE"].second.c_str()) == 0
                && atoi(tag2stamp_value["IMMUNE"].second.c_str()) == 0
                && atoi(tag2stamp_value["STEALTH"].second.c_str()) == 0
                && atoi(tag2stamp_value["CANT_BE_TARGETED_BY_SPELLS"].second.c_str()) == 0
            ) {
                stabable = 1;
            }
            if (atoi(tag2stamp_value["HEALTH"].second.c_str()) - atoi(tag2stamp_value["DAMAGE"].second.c_str()) <= 3
                && atoi(tag2stamp_value["DIVINE_SHIELD"].second.c_str()) == 0
                && atoi(tag2stamp_value["IMMUNE"].second.c_str()) == 0
                && atoi(tag2stamp_value["STEALTH"].second.c_str()) == 0
                && atoi(tag2stamp_value["CANT_BE_TARGETED_BY_SPELLS"].second.c_str()) == 0
            ) {
                boneable = 1;
            }
            if (atoi(tag2stamp_value["TAUNT"].second.c_str()) == 1
                && atoi(tag2stamp_value["IMMUNE"].second.c_str()) == 0
                && atoi(tag2stamp_value["STEALTH"].second.c_str()) == 0
            ) {
                oppotaunt = 1;
            }
        }

        // 对己方的增益效果
        if (tag2stamp_value["ZONE"].second == "PLAY"
            && tag2stamp_value["CARDTYPE"].second == "ENCHANTMENT") {
            std::string buff = tag2stamp_value["CardID"].second;
            if (tag2stamp_value["ATTACHED"].second == std::to_string(myid)) {
                if (buff == "EX1_145o") {
                    autost.auras[0] += 1;
                }
                if (buff == "AV_259e") {
                    autost.auras[0] -= 1;
                }
                if (buff == "DMF_511e") {
                    autost.auras[1] += 1;
                }
                if (buff == "REV_939e") {
                    autost.auras[2] += 2;
                }
                //TODO：舞动全场的enhance
                if (buff == "BAR_552o") {
                    int a = atoi(tag2stamp_value["TAG_SCRIPT_DATA_NUM_1"].second.c_str());
                    if (a == 0) {
                        autost.auras[2] += 3;
                        autost.auras[3] += 3;
                    }
                    if (a == 1) {
                        autost.auras[2] += 3;
                    }
                }
                if (buff == "FP1_030e") {
                    spelldebuff += 5;
                }
                if (buff == "SCH_713e") {
                    spelldebuff += 1;
                }
                if (buff == "REV_378e") {
                    miniondebuff += 1;
                }
                if (buff == "YOD_033e") {
                    battlecrydebuff += 5;
                }
            } else {
                int a = atoi(tag2stamp_value["ATTACHED"].second.c_str());
                int p = id2handpos[a] - 1;
                if (p >= 0 && p < hlim) {
                    if (buff == "GBL_002e") {
                        autost.hands[p].cost -= 2;
                    }
                    if (buff == "LOOT_204e") {
                        autost.hands[p].cost -= 2;
                    }
                    if (buff == "SCH_352e2") {
                        autost.hands[p].cost = 1;
                    }
                    if (buff == "OG_291e") {
                        autost.hands[p].cost = 1;
                    }
                    if (buff == "DMF_071e") {
                        autost.hands[p].cost = 1;
                    }
                    if (buff == "DED_004e") {
                        autost.hands[p].cost -= 1;
                    }
                    if (buff == "BAR_074e") {
                        autost.hands[p].cost += 1;
                    }
                    if (buff == "TID_744e") {
                        autost.hands[p].name = invalid;
                        autost.hands[p].cost = 0;
                    }
                    if (buff == "DRG_084e") {
                        int a = atoi(tag2stamp_value["TAG_SCRIPT_DATA_NUM_1"].second.c_str());
                        autost.hands[p].cost = a;
                    }
                    if (buff == "TSC_020e2") {
                        int a = atoi(tag2stamp_value["TAG_SCRIPT_DATA_NUM_1"].second.c_str());
                        autost.hands[p].cost = a;
                    }
                    if (buff == "AV_226e") {
                        autost.hands[p].cost += 1;
                    }
                    if (buff == "AV_113t9e") {
                        autost.hands[p].cost += 2;
                    }
                    if (buff == "RLK_567e2") {
                        _demiseif = 1;
                        if (_demisepos == -1) {
                            _demisepos = id2handpos[a] - 1;
                        } else if (_demisepos != id2handpos[a] - 1) {
                            _demisepos2 = id2handpos[a] - 1;
                        }
                    }
                }
            }
        }

        if (id <= myhid && id2initialController[id] == mycid && (tag2stamp_value["ZONE"].second != "DECK"
                                                                 || tag2stamp_value["CONTROLLER"].second != std::to_string(mycid))) {
            std::string cid = id2initialcardid[id];
            cardname c = cid2cn(cid);
            if (normalminion(c)) {
                notindeck[nidn++] = cn2mn(c);
            }
        }
    }

    //对于每个手牌中的同类奥秘，费用最低的一张以外视为垃圾，已经在奥秘区则均视为垃圾（提前标记-999）
    rep(i, 0, autost.H - 1) {
        int c = autost.hands[i].cost;
        int d = handsecret[i];
        if (d >= 0) {
            secretcheapest[d] = std::min(secretcheapest[d], c);
        }
    }
    rep(i, 0, autost.H - 1) {
        int c = autost.hands[i].cost;
        int d = handsecret[i];
        if (d >= 0) {
            if (c > secretcheapest[d]) {
                autost.hands[i].name = invalid;
                autost.hands[i].cost = 0;
            } else if (c == secretcheapest[d]) {
                secretcheapest[d] = -999;
            }
        }
    }

    autost.mana = atoi(id2tag2stamp_value[myid]["RESOURCES"].second.c_str())
                  - atoi(id2tag2stamp_value[myid]["RESOURCES_USED"].second.c_str())
                  + atoi(id2tag2stamp_value[myid]["TEMP_RESOURCES"].second.c_str());

    autost.num = atoi(id2tag2stamp_value[myid]["NUM_CARDS_PLAYED_THIS_TURN"].second.c_str());

    autost.drawmn = 0;

    autost.hatk = atoi(id2tag2stamp_value[myhid]["ATK"].second.c_str());

    if (oppotaunt == 1
        || atoi(id2tag2stamp_value[myhid]["NUM_ATTACKS_THIS_TURN"].second.c_str()) > 0
        || atoi(id2tag2stamp_value[myhid]["FROZEN"].second.c_str()) > 0
    ) {
        autost.hatk = -1;
    }

    _tar = atoi(id2tag2stamp_value[yourhid]["HEALTH"].second.c_str())
           - atoi(id2tag2stamp_value[yourhid]["DAMAGE"].second.c_str())
           + atoi(id2tag2stamp_value[yourhid]["ARMOR"].second.c_str());

    if (_demiseif == 1) {
        autost.todemise = autost.hands[_demisepos].name;
        autost.hands[_demisepos].name = demise;
        autost.hands[_demisepos].cost = 0;
        if (_demisepos2 != -1) {
            assert(autost.todemise == autost.hands[_demisepos2].name);
            autost.hands[_demisepos2].name = demise;
            autost.hands[_demisepos2].cost = 0;
        }
    } else {
        autost.todemise = anyspell;
    }

    parsedeck(_s);

    int truemn = 0;
    rep(i, 0, deckmn - 1) {
        bool flag = false;
        rep(j, 0, nidn - 1) {
            if (deckm[i] == notindeck[j]) {
                flag = true;
                notindeck[j] = nul;
                break;
            }
        }
        if (!flag) {
            deckm[truemn++] = deckm[i];
        }
    }
    deckmn = truemn;

    return autost;
}