#pragma once

#include "basic.h"

struct syn {
	std::pair<state, int> pa;
	//当前状态与累计伤害 
	double pri;
	//优先级 
	opes os;
	//操作序列 
};
syn syncons(const std::pair<state, int> &a, double b, const opes &c);
bool operator<(const syn &a, const syn &b);

const double sumbasic = 1.;
const double boundbasic = 10.;

extern int done, curdmg;
extern opes curos;
extern int testcnt;

std::string _solve(state st, int _need, int _tlim, int _collect, int _addquiz, int _print, int _exbound, int _optimize, int _pureformula, int _test);