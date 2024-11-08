#include "output.h"

std::string o2s(ope o) {
    std::string s = "";
    if (o.name == heroattack) {
        s = s + heroattk_s();
    } else if (o.name == demise) {
        s = s + demi_s();
    } else {
        s = s + cn2str(o.name);
        s = s + "(";
        s = s + std::to_string(o.cost);
        s = s + ")";
    }
    if (o.target != nul) {
        if (o.target == invalid_m) {
            s += "->";
            for (auto i: o.choose) {
                s += cn2str(i) + " ";
            }
        } else {
            s = s + "->" + mn2str(o.target);
        }
    }
    s = s + "\n";
    return s;
}

std::string output(opes o, int d, int u, ll t) {
    std::string s = "";
    if (u == -1) s += calcing_s();
    if (u == 0) s += exhaust_s();
    if (u == 1) s += targrch_s();
    if (u == 2) s += timerch_s();
    if (d >= _tar_ice2) d = d - _tar_ice1;
    s = s + "\n";
    s = s + std::to_string(d) + "\n";
    //int count = 0;
    for (auto i: o.os) {
        s = s + o2s(i);
        //count++;
        //if (count % 4 == 0) s = s + "\n";
    }
    s = s + "(" + std::to_string(t) + ")\n";
    return s;
}