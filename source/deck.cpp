#include "auto.h"
#include "deck.h"

#include <fstream>

int char2u6(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    }
    if (c >= '0' && c <= '9') {
        return c - '0' + 52;
    }
    if (c == '+') {
        return 62;
    }
    if (c == '/') {
        return 63;
    }
    return 0;
}

std::string plainu6(int x) {
    std::string s;
    rep(i, 0, 5) {
        s = static_cast<char>(x % 2 + 48) + s;
        x /= 2;
    }
    return s;
}

std::string dbfid2cid(int x) {
    if (x == 63517) return "BAR_552";
    if (x == 40437) return "CFM_630";
    if (x == 69521) return "CORE_CS2_072";
    if (x == 69622) return "CORE_EX1_144";
    if (x == 69623) return "CORE_EX1_145";
    if (x == 180) return "CS2_072";
    if (x == 65597) return "DED_004";
    if (x == 61635) return "DMF_071";
    if (x == 61151) return "DMF_511";
    if (x == 61154) return "DMF_512";
    if (x == 61159) return "DMF_515";
    if (x == 365) return "EX1_144";
    if (x == 1158) return "EX1_145";
    if (x == 45975) return "ICC_910";
    if (x == 45520) return "LOOT_204";
    if (x == 45531) return "LOOT_211";
    if (x == 45535) return "LOOT_214";
    if (x == 77148) return "REV_825";
    if (x == 77556) return "REV_938";
    if (x == 77557) return "REV_939";
    if (x == 59621) return "SCH_352";
    if (x == 64718) return "SW_070";
    if (x == 64033) return "SW_412";
    if (x == 49972) return "TRL_092";
    if (x == 72119) return "TSC_916";
    if (x == 54426) return "ULD_715";
    if (x == 68348) return "VAN_CS2_072";
    if (x == 69863) return "VAN_EX1_144";
    if (x == 69864) return "VAN_EX1_145";
    if (x == 63358) return "WC_016";

    if (x == 113183) return "LEG_CS3_031";
    if (x == 90749) return "ETC_080";
    if (x == 90606) return "ETC_079";

    return "";
}

int nums[99], nn;

std::vector<std::string> deckcode2cids(const std::string &s) {
    std::vector<std::string> cids;
    cids.clear();

    int l = s.length();
    std::string t = "";
    rep(i, 0, l - 1) t = t + plainu6(char2u6(s[i]));

    int l2 = t.length();
    if (l2 % 8) return cids;

    int cur = 0;
    int base = 1;
    nn = 0;
    rep(i, 0, l2 / 8 - 1) {
        int bit = 0;
        rep(j, 1, 7) bit = bit * 2 + (t[8 * i + j] - 48);
        cur = cur + base * bit;
        base = base * 128;
        if (t[8 * i] == 48) {
            if (nn >= 50) return cids;
            nums[nn++] = cur;
            cur = 0;
            base = 1;
        }
    }

    int m = nums[5];
    if (5 + m >= nn) return cids;
    rep(i, 0, m - 1) cids.push_back(dbfid2cid(nums[6 + i]));
    int k = nums[6 + m];
    if (6 + m + k >= nn) return cids;
    rep(i, 0, k - 1) rep(j, 0, 1) cids.push_back(dbfid2cid(nums[7 + m + i]));

    return cids;
}

void parsedeck(std::string _s) {
    std::cin.clear();
    //重置输入流，防止无法读取 

    fs::path logFilePath = findNewestDirectory(_s);
    std::ifstream logFile(logFilePath / "Decks.log");

    std::string line;
    std::string code;

    while (getline(std::cin, line)) {
        code = line;
    }

    auto p = code.find("A");
    if (p == -1) return;

    code = code.substr(p);

    std::vector<std::string> cids = deckcode2cids(code);
    deckmn = 0;
    for (auto cid : cids) {
        cardname c = cid2cn(cid);
        if (normalminion(c)) {
            deckm[deckmn++] = cn2mn(c);
        }
    }
}