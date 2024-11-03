#pragma once

#include "basic.h"

int o2i(const ope &a);

const int flimr = 4;
const int fliml = 2;
const double rho = 0.5;

ull ishash(int l, int r, const int* s);
extern std::map<ull, double> value;