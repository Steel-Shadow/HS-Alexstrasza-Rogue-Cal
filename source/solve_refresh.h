#pragma once

#include "basic.h"

struct syn {
	std::pair<state, int> pa;
	//��ǰ״̬���ۼ��˺� 
	double pri;
	//���ȼ� 
	opes os;
	//�������� 
};
syn syncons(const std::pair<state, int> &a, double b, const opes &c);
bool operator<(const syn &a, const syn &b);

const double sumbasic = 1.;
const double boundbasic = 10.;

extern int done, curdmg;
extern opes curos;
extern int testcnt;

std::string _solve(state st, int _need, int _tlim, int _collect, int _addquiz, int _print, int _exbound, int _optimize, int _pureformula, int _test);