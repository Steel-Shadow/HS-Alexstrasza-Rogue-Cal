#include "basic.h"
#include "offer.h"
#include "trans.h"
#include "output.h"
#include "formula.h"
#include "solve.h"
#include "gen.h"
#include "pre.h"
#include "auto.h"
#include "ui.h"

int main() {
#ifdef Windows
	ui_main();
#elif Linux
	pre_main();
#endif
	return 0;
}