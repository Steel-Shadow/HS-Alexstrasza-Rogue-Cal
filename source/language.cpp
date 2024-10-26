//
// Created by Steel_Shadow on 2024/11/2.
//

#include "basic.h"

lang _lang = CN;

string shak_s() {
	return _lang == CN ? "鱼灵" : "Shak";
}
string shxk_s() {
	return _lang == CN ? "沉鱼" : "Shxk";
}
string foxy_s() {
	return _lang == CN ? "老千" : "Foxy";
}
string mail_s() {
	return _lang == CN ? "箱舞" : "Mail";
}
string scab_s() {
	return _lang == CN ? "刀油" : "Scab";
}
string tenw_s() {
	return _lang == CN ? "腾武" : "Tenw";
}
string cast_s() {
	return _lang == CN ? "暗施" : "Cast";
}
string pill_s() {
	return _lang == CN ? "鬼灵" : "Pill";
}
string elvn_s() {
	return _lang == CN ? "咏唱" : "Elvn";
}
string anym_s() {
	return _lang == CN ? "随从" : "AnyM";
}
string alexstrasza_s() {
	return _lang == CN ? "红龙" : "Alexstrasza";
}
string ETC_s() {
	return _lang == CN ? "牛头" : "ETC";
}
string bounceAround_s() {
	return _lang == CN ? "舞动" : "BounceAround";
}
string face_s() {
	return _lang == CN ? "对面" : "Face";
}
string step_s() {
	return _lang == CN ? "暗步" : "Step";
}
string stab_s() {
	return _lang == CN ? "背刺" : "Stab";
}
string si7_s() {
	return _lang == CN ? "要挟" : "SI7.";
}
string coin_s() {
	return _lang == CN ? "假币" : "Coin";
}
string prep_s() {
	return _lang == CN ? "伺机" : "Prep";
}
string pshn_s() {
	return _lang == CN ? "幻药" : "Pshn";
}
string anys_s() {
	return _lang == CN ? "法术" : "Anys";
}
string trsh_s() {
	return _lang == CN ? "垃圾" : "Trsh";
}
string anyw_s() {
	return _lang == CN ? "武器" : "AnyW";
}
string cmbs_s() {
	return _lang == CN ? "连法" : "CmbS";
}
string bone_s() {
	return _lang == CN ? "齿刺" : "Bone";
}
string shrd_s() {
	return _lang == CN ? "帷幕" : "Shrd";
}
string swin_s() {
	return _lang == CN ? "行骗" : "Swin";
}
string iuca_s() {
	return _lang == CN ? "裂心" : "Iuca";
}
string bran_s() {
	return _lang == CN ? "铜须" : "Bran";
}
string zola_s() {
	return _lang == CN ? "佐拉" : "Zola";
}
string plag_s() {
	return _lang == CN ? "毒刀" : "Plag";
}
string clr_s() {
	return _lang == CN ? "清除" : "Clr.";
}
string mana_s() {
	return _lang == CN ? "水晶" : "Mana";
}
string calc_s() {
	return _lang == CN ? "计算" : "Calc";
}
string randc_s() {
	return _lang == CN ? "读算" : "R&C.";
}
string time_s() {
	return _lang == CN ? "时限" : "Time";
}
string targ_s() {
	return _lang == CN ? "目标" : "Targ";
}
string adpt_s() {
	return _lang == CN ? "适应" : "Adpt";
}
string chng_s() {
	return _lang == CN ? "修改" : "Chng";
}
string read_s() {
	return _lang == CN ? "读取" : "Read";
}
string back_s() {
	return _lang == CN ? "回退" : "Back";
}
string stax_s() {
	return _lang == CN ? "法术加费" : "AnySTax.";
}
string mtax_s() {
	return _lang == CN ? "随从加费" : "AnyMTax,";
}
string btax_s() {
	return _lang == CN ? "战吼加费" : "BcryTax.";
}
string able_s() {
	return _lang == CN ? "背刺可用" : "StabAble";
}
string able2_s() {
	return _lang == CN ? "齿刺可用" : "BoneAble";
}
string plyd_s() {
	return _lang == CN ? "已用牌数" : "CrdsPlyd";
}
string samp_s() {
	return _lang == CN ? "查看样例" : "ViewSamp";
}
string cl_s() {
	return _lang == CN ? "清" : "Cl";
}
string a0_s() {
	return _lang == CN ? "伺机层数" : "PrepDisc";
}
string a1_s() {
	return _lang == CN ? "老千层数" : "FoxyDisc";
}
string a2_s() {
	return _lang == CN ? "下一减费" : "Nxt1Disc";
}
string a3_s() {
	return _lang == CN ? "下二减费" : "Nxt2Disc";
}
string hint_s() {
	return _lang == CN ? "请输入炉石传说本地路径（回车确认）" : "Please enter the local path of HS:";
}
string calcing_s() {
	return _lang == CN ? "(正在计算)" : "(Calcing.)";
}
string exhaust_s() {
	return _lang == CN ? "(穷尽掐断)" : "(Exhaust.)";
}
string targrch_s() {
	return _lang == CN ? "(达标掐断)" : "(TargRch.)";
}
string timerch_s() {
	return _lang == CN ? "(时限掐断)" : "(TimeRch.)";
}
string iceblock_s() {
	return _lang == CN ? "破冰需要" : "IceBlock";
}
string heroattk_s() {
	return _lang == CN ? "英雄攻击" : "HeroAttk";
}
string demi_s() {
	return _lang == CN ? "殒命" : "Demi";
}
string smal_s() {
	return "><";
}
string larg_s() {
	return "<>";
}

string mn2str(minionname a) {
	switch (a) {
		case sharkspirit_m: {
			return shak_s();
			break;
		}
		case sharkspirit_mx: {
			return shxk_s();
		}
		case foxyfraud_m: {
			return foxy_s();
			break;
		}
		case mailboxdancer_m: {
			return mail_s();
			break;
		}
		case cutterbutter_m: {
			return scab_s();
			break;
		}
		case redsmoke_m: {
			return tenw_s();
			break;
		}
		case shadowcaster_m: {
			return cast_s();
		}
		case spectralpillager_m: {
			return pill_s();
			break;
		}
		case elvensinger_m: {
			return elvn_s();
		}
		case illucia_m: {
			return iuca_s();
			break;
		}
		case brann_m: {
			return bran_s();
			break;
		}
		case zolag_m: {
			return zola_s();
			break;
		}
		case anyminion_m: {
			return anym_s();
			break;
		}
	case alexstrasza_m:
			{
				return alexstrasza_s();break;

			}
	case ETC_m:
			{
				return ETC_s();break;

			}
		case enemyhero: {
			return face_s();
			break;
		}
		case enemyminion: {
			assert(0);
			return "";
			break;
		}
		case nul: {
			return "";
			break;
		}
		default: {
			assert(0);
			return "";
			break;
		}
	}
}
string cn2str(cardname a) {
	switch (a) {
		case sharkspirit: {
			return shak_s();
			break;
		}
		case foxyfraud: {
			return foxy_s();
			break;
		}
		case mailboxdancer: {
			return mail_s();
			break;
		}
		case cutterbutter: {
			return scab_s();
			break;
		}
		case redsmoke: {
			return tenw_s();
			break;
		}
		case shadowcaster: {
			return cast_s();
		}
		case spectralpillager: {
			return pill_s();
			break;
		}
		case elvensinger: {
			return elvn_s();
			break;
		}
		case illucia: {
			return iuca_s();
			break;
		}
		case brann: {
			return bran_s();
			break;
		}
		case zolag: {
			return zola_s();
			break;
		}
		case anyminion: {
			return anym_s();
			break;
		}
		case shadowstep: {
			return step_s();
			break;
		}
		case backstab: {
			return stab_s();
			break;
		}
		case extortion: {
			return si7_s();
			break;
		}
		case fakecoin: {
			return coin_s();
			break;
		}
		case preparation: {
			return prep_s();
			break;
		}
		case illusionpotion: {
			return pshn_s();
			break;
		}
		case anyspell: {
			return anys_s();
			break;
		}
		case anyweapon: {
			return anyw_s();
			break;
		}
		case anycombospell: {
			return cmbs_s();
			break;
		}
		case bonespike: {
			return bone_s();
			break;
		}
		case shroud: {
			return shrd_s();
		}
		case swindle: {
			return swin_s();
		}
		case madnessplague: {
			return plag_s();
		}
		case demise: {
			return demi_s();
		}
		case alexstrasza: {
			return alexstrasza_s();
		}
		case ETC: {
			return ETC_s();
		}
		case bounceAround: {
			return bounceAround_s();
		}
		case invalid: {
			return trsh_s();
			break;
		}
		default: {
			assert(0);
			return "";
			break;
		}
	}
}