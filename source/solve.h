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
bool operator<(syn a, syn b);

const double sumbasic = 1.;
const double boundbasic = 10.0;

extern int done, curdmg;
extern opes curos;
extern int testcnt;

std::string _solve(state st, int _need, int _tlim, int _collect, int _addquiz, int _print, int _exbound, int _optimize, int _pureformula, int _test);