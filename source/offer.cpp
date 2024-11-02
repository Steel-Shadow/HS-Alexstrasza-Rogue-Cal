#include "offer.h"

#include <functional>

bool notcoinopt4demise(state a) {
    //殒命暗影对于硬币优先的附加逻辑：
    //如果有殒命暗影，且殒命暗影当前复制的不是any/coin，则硬币优先不直接成立
    //这是为了保护殒命暗影当前复制的法术，在此保护情形下，其他常规法术也不应当被打出
    //在此保护以外的情形，（该计算器）保持硬币优先，因为这一定不妨碍其复制其他之后打出的法术（反而对顺利复制有帮助）
    //也就是说，要么硬币优先，要么保护情形
    //注意：在极端情形下，这仍然是有漏洞的！这有可能妨碍了殒命暗影复制硬币
    //抛开费用限制不谈，如果殒命暗影需要复制硬币，总是可以随着硬币一起打出的，并不妨碍
    //但是：例如在费用为9的情况下，手牌中有殒命暗影，硬币，帷幕。有可能需要先打帷幕，再打硬币，然后让殒命暗影复制硬币
    //如果先打硬币，此时已经费用为10，殒命暗影可能难以合适地复制到硬币
    //这个漏洞可能在之后会被防止
    if (a.todemise == anyspell || a.todemise == anycombospell || a.todemise == fakecoin) {
        return false;
    }
    rep(i, 0, a.H - 1) {
        if (a.hands[i].name == demise) {
            return true;
        }
    }
    return false;
}

bool coinopt(state a, oxy &b) {
    //硬币优先逻辑：有0费硬币，不受加减费光环影响，当前费用小于上限，不需要破冰
    if (iceblockif == 1) return false;
    if (a.mana < manalim && a.auras[2] == 0 && a.auras[3] == 0 && a.auras[0] == 0 && spelldebuff == 0) {
        rep(i, 0, a.H - 1) {
            if (a.hands[i].name == fakecoin && a.hands[i].cost == 0) {
                b.x = i;
                b.y = -1;
                return true;
            }
        }
        return false;
    }
    return false;
}

/**
 * @brief 牛头人选卡的所有可能，需要给定选卡数量（铜须 鲨鱼 选2次）
 * @param cards 可选取的卡
 * @param tempChosenCards 临时用，选取的卡
 * @param tempChosen 临时用，已经被选取的卡
 * @param choseCardNum 选取卡的数量
 * @param choseCallback 选卡的回调函数
 */
void choseCards(const std::vector<cardname> &cards,
                std::vector<cardname> &tempChosenCards,
                std::vector<bool> &tempChosen,
                int choseCardNum,
                const std::function<void(const std::vector<cardname> &)> &choseCallback) {
    if (tempChosenCards.size() == choseCardNum) {
        // for (auto cardName: tempChosenCards) {
        //     std::cout << cn2str(cardName) << " ";
        // }
        // std::cout << std::endl;
        choseCallback(tempChosenCards);
        return;
    }

    for (size_t i = 0; i < cards.size(); ++i) {
        if (tempChosen[i]) continue; // 跳过已使用的元素
        tempChosen[i] = true; // 标记为已使用
        tempChosenCards.push_back(cards[i]); // 将当前元素添加到临时结果中

        choseCards(cards, tempChosenCards, tempChosen, choseCardNum, choseCallback); // 递归调用

        tempChosenCards.pop_back(); // 回溯，移除最后一个元素
        tempChosen[i] = false; // 恢复标记
    }
}

/**
 *
 * @param operations 添加到的操作序列
 * @param handNum 牛头人的手牌序号
 * @param etcChoose 牛头人选取的卡牌列表
 */
void etcChoseCard(std::vector<oxy> operations, int handNum, const std::vector<cardname> &etcChoose) {
    operations.push_back(oxycons(handNum, -1, etcChoose));
}

// 列出当前 state 下所有可行的操作
oxys offer(state a) {
    oxys os = emptyoxyscons();
    oxy o;

    bool protectdemise = false;
    if (coinopt(a, o)) {
        os.os.push_back(o);
        if (notcoinopt4demise(a)) {
            protectdemise = true;
        } else {
            return os;
        }
    }

    if (a.hatk > 0) {
        os.os.push_back(oxycons(-1, -2));
    }

    rep(i, 0, a.H - 1) {
        int co = a.hands[i].cost;
        cardname na = a.hands[i].name;
        bool dup = false;
        rep(j, 0, i - 1) {
            if (a.hands[j].cost == co && a.hands[j].name == na && a.hands[j].health == a.hands[i].health) {
                dup = true;
                break;
            }
        }
        if (dup) continue;

        if (na == demise) {
            na = a.todemise;
        }

        if (protectdemise) {
            if (normalspell(na) && na != a.todemise) {
                //被保护情形下，不同于当前复制的法术不应当被打出
                //当前复制的法术已经确定不是any/coin，所以any/coin不需要额外排除
                continue;
            }
        }

        // 选择操作对象，过滤场上重复的随从
        if (na == shadowstep || na == backstab || na == extortion || na == bonespike
            || na == redsmoke || na == shadowcaster || na == zolag || na == spectralpillager || alexstrasza) {
            rep(j, 0, a.F - 1) {
                bool dup2 = false;
                rep(k, 0, j - 1) {
                    if (a.fields[k].name == a.fields[j].name && a.fields[k].health == a.fields[j].health && a.fields[k].curhealth == a.fields[j].curhealth) {
                        dup2 = true;
                        break;
                    }
                }
                if (dup2) continue;
                os.os.push_back(oxycons(i, j));
            }
        }
        if (na == spectralpillager || na == alexstrasza) {
            os.os.push_back(oxycons(i, -2));
        }
        if (na == backstab || na == extortion || na == bonespike
            || na == fakecoin || na == preparation || na == illusionpotion || na == shroud || na == swindle || na == madnessplague
            || na == bounceAround
            || na == redsmoke || na == shadowcaster || na == zolag
            || na == mailboxdancer || na == foxyfraud || na == cutterbutter || na == elvensinger || na == sharkspirit || na == illucia || na == brann
            || na == anyminion || na == anyspell || na == anyweapon || na == anycombospell) {
            os.os.push_back(oxycons(i, -1));
        }
        if (na == ETC) {
            // TODO: 目前不支持修改牛头人内的卡，固定为红龙、舞动全场、幻觉药水

            // cards 牛头人内可取的卡，去除了已经被取走的
            std::vector<cardname> cards = {alexstrasza, bounceAround, illusionpotion};
            for (bool etc_taken: a.etcTaken) {
                auto it = std::find(cards.begin(), cards.end(), etc_taken);
                if (it != cards.end()) {
                    cards.erase(it);
                }
            }

            int choseNum = 1; // 取卡数量
            for (int j = 0; j <= a.F - 1; j++) {
                if (a.fields[j].name == sharkspirit_m || a.fields[j].name == brann_m) {
                    choseNum = 2;
                }
            }

            std::vector<cardname> t1{};
            std::vector<bool> t2(cards.size(), false);
            auto etcChoseCardWrap = [&os, i](auto &etcChoose) {
                os.os.push_back(oxycons(i, -1, etcChoose));
            };
            choseCards(cards, t1, t2, choseNum, etcChoseCardWrap);
        }
    }
    return os;
}