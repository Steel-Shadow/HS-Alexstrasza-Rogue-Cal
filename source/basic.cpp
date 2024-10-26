#include "basic.h"

cardname mn2cn(minionname a) {
	switch (a) {
		case sharkspirit_m: {
			return sharkspirit;
			break;
		}
		case sharkspirit_mx: {
			return sharkspirit;
			break;
		}
		case foxyfraud_m: {
			return foxyfraud;
			break;
		}
		case mailboxdancer_m: {
			return mailboxdancer;
			break;
		}
		case cutterbutter_m: {
			return cutterbutter;
			break;
		}
		case redsmoke_m: {
			return redsmoke;
			break;
		}
		case shadowcaster_m: {
			return shadowcaster;
			break;
		}
		case spectralpillager_m: {
			return spectralpillager;
			break;
		}
		case elvensinger_m: {
			return elvensinger;
			break;
		}
		case illucia_m: {
			return illucia;
			break;
		}
		case brann_m: {
			return brann;
			break;
		}
		case zolag_m: {
			return zolag;
			break;
		}
		case anyminion_m: {
			return anyminion;
			break;
		}
		default: {
			assert(0);
			return anyminion;
			break;
		}
	}
}
minionname cn2mn(cardname a) {
	switch (a) {
		case sharkspirit: {
			return sharkspirit_m;
			break;
		}
		case foxyfraud: {
			return foxyfraud_m;
			break;
		}
		case mailboxdancer: {
			return mailboxdancer_m;
			break;
		}
		case cutterbutter: {
			return cutterbutter_m;
			break;
		}
		case redsmoke: {
			return redsmoke_m;
			break;
		}
		case shadowcaster: {
			return shadowcaster_m;
			break;
		}
		case spectralpillager: {
			return spectralpillager_m;
			break;
		}
		case elvensinger: {
			return elvensinger_m;
			break;
		}
		case illucia: {
			return illucia_m;
			break;
		}
		case zolag: {
			return zolag_m;
			break;
		}
		case anyminion: {
			return anyminion_m;
			break;
		}
		case alexstrasza: {
			return  alexstrasza_m;
			break;
		}
		case ETC: {
			return ETC_m;
			break;
		}
		default: {
			assert(0);
			return anyminion_m;
			break;
		}
	}
}
bool normalminion(cardname a) {
	switch (a) {
		case sharkspirit:
		case foxyfraud:
		case mailboxdancer:
		case cutterbutter:
		case redsmoke:
		case shadowcaster:
		case spectralpillager:
		case elvensinger:
		case illucia:
		case brann:
		case zolag:
		case alexstrasza:
		case ETC:
		case anyminion: {
			return true;
			break;
		}
		default: {
			return false;
			break;
		}
	}
}
bool normalspell(cardname a) {
	switch (a) {
		case shadowstep:
		case backstab:
		case fakecoin:
		case preparation:
		case illusionpotion:
		case bonespike:
		case shroud:
		case extortion:
		case swindle:
		case madnessplague:
		case bounceAround:
		case anyspell:
		case anycombospell: {
			return true;
			break;
		}
		default: {
			return false;
			break;
		}
	}
}
int originalcost(minionname a) {
	switch (a) {
		case sharkspirit_m: {
			return 4;
			break;
		}
		case sharkspirit_mx: {
			return 4;
			break;
		}
		case foxyfraud_m: {
			return 2;
			break;
		}
		case mailboxdancer_m: {
			return 2;
			break;
		}
		case cutterbutter_m: {
			return 4;
			break;
		}
		case redsmoke_m: {
			return 2;
			break;
		}
		case shadowcaster_m: {
			return 5;
			break;
		}
		case spectralpillager_m: {
			return 6;
			break;
		}
		case elvensinger_m: {
			return 4;
		}
		case illucia_m: {
			return 3;
		}
		case brann_m: {
			return 3;
		}
		case zolag_m: {
			return 3;
		}
		case alexstrasza_m: {
			return 9;
		}
		case ETC_m: {
			return 4;
		}
		case anyminion_m: {
			return 99;
			break;
		}
		case enemyhero: {
			assert(0);
			return 0;
			break;
		}
		case enemyminion: {
			assert(0);
			return 0;
			break;
		}
		default: {
			assert(0);
			return 0;
			break;
		}
	}
}
int originalcost_c(cardname a) {
	if (normalminion(a)) {
		return originalcost(cn2mn(a));
	}
	else switch(a) {
		case shadowstep: {
			return 0;
			break;
		}
		case backstab: {
			return 0;
			break;
		}
		case extortion: {
			return 1;
		}
		case fakecoin: {
			return 0;
			break;
		}
		case preparation: {
			return 0;
			break;
		}
		case illusionpotion: {
			return 4;
			break;
		}
		case bonespike: {
			return 2;
			break;
		}
		case shroud: {
			return 3;
			break;
		}
		case swindle: {
			return 2;
		}
		case madnessplague: {
			return 1;
		}
		case bounceAround: {
			return 3;
		}
		case anyweapon: {
			return 1;
			break;
		}
		default: {
			return 0;
			break;
		}
	}
}
int originalhealth(minionname a) {
	switch (a) {
		case sharkspirit_m: {
			return 3;
			break;
		}
		case sharkspirit_mx: {
			return 3;
			break;
		}
		case foxyfraud_m: {
			return 2;
			break;
		}
		case mailboxdancer_m: {
			return 2;
			break;
		}
		case cutterbutter_m: {
			return 3;
			break;
		}
		case redsmoke_m: {
			return 2;
			break;
		}
		case shadowcaster_m: {
			return 4;
			break;
		}
		case spectralpillager_m: {
			return 5;
			break;
		}
		case elvensinger_m: {
			return 2;
		}
		case illucia_m: {
			return 3;
		}
		case brann_m: {
			return 4;
		}
		case zolag_m: {
			return 2;
		}
		case anyminion_m: {
			return 99;
			break;
		}
		case alexstrasza_m: {
			return 8;
			break;
		}
		case ETC_m: {
			return 4;
			break;
		}
		case enemyhero: {
			assert(0);
			return 0;
			break;
		}
		case enemyminion: {
			assert(0);
			return 0;
			break;
		}
		default: {
			assert(0);
			return 0;
			break;
		}
	}
}
int originalhealth_c(cardname a) {
	if (normalminion(a)) {
		return originalhealth(cn2mn(a));
	}
	else {
		return 0;
	}
}

card cardcons(cardname a, int b) {
	card c;
	c.name = a;
	c.cost = b;
	c.health = originalhealth_c(a);
	return c;
}
card cardcons(cardname a, int b, int c) {
	card d;
	d.name = a;
	d.cost = b;
	d.health = c;
	return d;
}

minion minioncons(minionname a) {
	minion b;
	b.name = a;
	b.health = originalhealth(a);
	b.curhealth = b.health;
	return b;
}
minion minioncons(minionname a, int b, int c) {
	minion d;
	d.name = a;
	d.health = b;
	d.curhealth = c;
	return d;
}

state emptystcons() {
	state a;
	a.H = 0;
	a.F = 0;
	rep(i, 0, 3) a.auras[i] = 0;
	a.mana = 0;
	a.num = 0;
	a.drawmn = 0;
	a.hatk = 0;
	a.todemise = anyspell;
	return a;
}
state emptyst = emptystcons();

oxy oxycons(int a, int b){//oxy:x-y操作
	oxy c;
	c.x = a;
	c.y = b;
	return c;
}
ope opecons(int a, cardname b, minionname c) {//
	ope d;
	d.cost = a;
	d.name = b;
	d.target = c;
	return d;
}
ope exact(state a, oxy b) {//将x-y操作具体为用于输出的具体操作
	minionname z = nul;
	if (b.y >= 0) {
		z = a.fields[b.y].name;
		if (a.hands[b.x].name == backstab && a.fields[b.y].curhealth > 2) {
			z = nul;
		}
		if (a.hands[b.x].name == extortion && a.fields[b.y].curhealth > 3) {
			z = nul;
		}
	}
	else if (b.y == -1) {
		z = nul;
	}
	else if (b.y == -2) {
		z = enemyhero;
	}
	else {
		assert(0);
	}

	if (b.x >= 0) {
		return opecons(a.hands[b.x].cost, a.hands[b.x].name, z);
	}
	else if (b.x == -1) {
		return opecons(0, heroattack, z);
	}
	else {
		assert(0);
		return opecons(0, invalid, nul);
	}
}

ope exact4f(state a, oxy b) {//与具体操作类似，且融入公式
	ope o = exact(a, b);
	if (o.name == extortion) o.name = backstab;//要挟按照背刺融入公式
	//某些不常见（随从）牌也可以按照另一张融入公式，暂不考虑
	if (o.name == demise) o.name = a.todemise;//殒命暗影按照实际复制的法术融入公式
	return o;
}

oxys emptyoxyscons() {
	oxys a;
	a.os.clear();
	return a;
}
oxys emptyoxys = emptyoxyscons();

opes emptyopescons() {
	opes a;
	a.os.clear();
	return a;
}
opes emptyopes = emptyopescons();

int stabable;
int boneable;
int spelldebuff;
int miniondebuff;
int battlecrydebuff;

int deckmn;
minionname deckm[99];

int oppoH;
card oppohands[10];

int iceblockif;

int iseq[999], isn;

quiz emptyqcons() {
	quiz q;
	q.qst = emptystcons();
	q.qnd = 0;
	return q;
}
vector<quiz> quizs;

vector<opes> cls;
vector<opes> allcls;