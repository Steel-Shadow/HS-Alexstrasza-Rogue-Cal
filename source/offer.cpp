#include "offer.h"

#include <functional>

bool notcoinopt4demise(state a) {
    //������Ӱ����Ӳ�����ȵĸ����߼���
    //�����������Ӱ����������Ӱ��ǰ���ƵĲ���any/coin����Ӳ�����Ȳ�ֱ�ӳ���
    //����Ϊ�˱���������Ӱ��ǰ���Ƶķ������ڴ˱��������£��������淨��Ҳ��Ӧ�������
    //�ڴ˱�����������Σ����ü�����������Ӳ�����ȣ���Ϊ��һ���������临������֮�����ķ�����������˳�������а�����
    //Ҳ����˵��ҪôӲ�����ȣ�Ҫô��������
    //ע�⣺�ڼ��������£�����Ȼ����©���ģ����п��ܷ�����������Ӱ����Ӳ��
    //�׿��������Ʋ�̸�����������Ӱ��Ҫ����Ӳ�ң����ǿ�������Ӳ��һ�����ģ���������
    //���ǣ������ڷ���Ϊ9������£���������������Ӱ��Ӳ�ң��Ļ���п�����Ҫ�ȴ��Ļ���ٴ�Ӳ�ң�Ȼ����������Ӱ����Ӳ��
    //����ȴ�Ӳ�ң���ʱ�Ѿ�����Ϊ10��������Ӱ�������Ժ��ʵظ��Ƶ�Ӳ��
    //���©��������֮��ᱻ��ֹ
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
    //Ӳ�������߼�����0��Ӳ�ң����ܼӼ��ѹ⻷Ӱ�죬��ǰ����С�����ޣ�����Ҫ�Ʊ�
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
 * @brief ţͷ��ѡ�������п��ܣ���Ҫ����ѡ��������ͭ�� ���� ѡ2�Σ�
 * @param cards ��ѡȡ�Ŀ�
 * @param tempChosenCards ��ʱ�ã�ѡȡ�Ŀ�
 * @param tempChosen ��ʱ�ã��Ѿ���ѡȡ�Ŀ�
 * @param choseCardNum ѡȡ��������
 * @param choseCallback ѡ���Ļص�����
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
        if (tempChosen[i]) continue; // ������ʹ�õ�Ԫ��
        tempChosen[i] = true; // ���Ϊ��ʹ��
        tempChosenCards.push_back(cards[i]); // ����ǰԪ����ӵ���ʱ�����

        choseCards(cards, tempChosenCards, tempChosen, choseCardNum, choseCallback); // �ݹ����

        tempChosenCards.pop_back(); // ���ݣ��Ƴ����һ��Ԫ��
        tempChosen[i] = false; // �ָ����
    }
}

/**
 *
 * @param operations ��ӵ��Ĳ�������
 * @param handNum ţͷ�˵��������
 * @param etcChoose ţͷ��ѡȡ�Ŀ����б�
 */
void etcChoseCard(std::vector<oxy> operations, int handNum, const std::vector<cardname> &etcChoose) {
    operations.push_back(oxycons(handNum, -1, etcChoose));
}

// �г���ǰ state �����п��еĲ���
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
                //�����������£���ͬ�ڵ�ǰ���Ƶķ�����Ӧ�������
                //��ǰ���Ƶķ����Ѿ�ȷ������any/coin������any/coin����Ҫ�����ų�
                continue;
            }
        }

        // ѡ��������󣬹��˳����ظ������
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
            // TODO: Ŀǰ��֧���޸�ţͷ���ڵĿ����̶�Ϊ�������趯ȫ�����þ�ҩˮ

            // cards ţͷ���ڿ�ȡ�Ŀ���ȥ�����Ѿ���ȡ�ߵ�
            std::vector<cardname> cards = {alexstrasza, bounceAround, illusionpotion};
            for (bool etc_taken: a.etcTaken) {
                auto it = std::find(cards.begin(), cards.end(), etc_taken);
                if (it != cards.end()) {
                    cards.erase(it);
                }
            }

            int choseNum = 1; // ȡ������
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