//
// Created by Steel_Shadow on 2024/11/2.
//

#include "basic.h"

lang _lang = CN;

string shak_s() {
	return _lang == CN ? "����" : "Shak";
}
string shxk_s() {
	return _lang == CN ? "����" : "Shxk";
}
string foxy_s() {
	return _lang == CN ? "��ǧ" : "Foxy";
}
string mail_s() {
	return _lang == CN ? "����" : "Mail";
}
string scab_s() {
	return _lang == CN ? "����" : "Scab";
}
string tenw_s() {
	return _lang == CN ? "����" : "Tenw";
}
string cast_s() {
	return _lang == CN ? "��ʩ" : "Cast";
}
string pill_s() {
	return _lang == CN ? "����" : "Pill";
}
string elvn_s() {
	return _lang == CN ? "ӽ��" : "Elvn";
}
string anym_s() {
	return _lang == CN ? "���" : "AnyM";
}
string alexstrasza_s() {
	return _lang == CN ? "����" : "Alexstrasza";
}
string ETC_s() {
	return _lang == CN ? "ţͷ" : "ETC";
}
string bounceAround_s() {
	return _lang == CN ? "�趯" : "BounceAround";
}
string face_s() {
	return _lang == CN ? "����" : "Face";
}
string step_s() {
	return _lang == CN ? "����" : "Step";
}
string stab_s() {
	return _lang == CN ? "����" : "Stab";
}
string si7_s() {
	return _lang == CN ? "ҪЮ" : "SI7.";
}
string coin_s() {
	return _lang == CN ? "�ٱ�" : "Coin";
}
string prep_s() {
	return _lang == CN ? "�Ż�" : "Prep";
}
string pshn_s() {
	return _lang == CN ? "��ҩ" : "Pshn";
}
string anys_s() {
	return _lang == CN ? "����" : "Anys";
}
string trsh_s() {
	return _lang == CN ? "����" : "Trsh";
}
string anyw_s() {
	return _lang == CN ? "����" : "AnyW";
}
string cmbs_s() {
	return _lang == CN ? "����" : "CmbS";
}
string bone_s() {
	return _lang == CN ? "�ݴ�" : "Bone";
}
string shrd_s() {
	return _lang == CN ? "�Ļ" : "Shrd";
}
string swin_s() {
	return _lang == CN ? "��ƭ" : "Swin";
}
string iuca_s() {
	return _lang == CN ? "����" : "Iuca";
}
string bran_s() {
	return _lang == CN ? "ͭ��" : "Bran";
}
string zola_s() {
	return _lang == CN ? "����" : "Zola";
}
string plag_s() {
	return _lang == CN ? "����" : "Plag";
}
string clr_s() {
	return _lang == CN ? "���" : "Clr.";
}
string mana_s() {
	return _lang == CN ? "ˮ��" : "Mana";
}
string calc_s() {
	return _lang == CN ? "����" : "Calc";
}
string randc_s() {
	return _lang == CN ? "����" : "R&C.";
}
string time_s() {
	return _lang == CN ? "ʱ��" : "Time";
}
string targ_s() {
	return _lang == CN ? "Ŀ��" : "Targ";
}
string adpt_s() {
	return _lang == CN ? "��Ӧ" : "Adpt";
}
string chng_s() {
	return _lang == CN ? "�޸�" : "Chng";
}
string read_s() {
	return _lang == CN ? "��ȡ" : "Read";
}
string back_s() {
	return _lang == CN ? "����" : "Back";
}
string stax_s() {
	return _lang == CN ? "�����ӷ�" : "AnySTax.";
}
string mtax_s() {
	return _lang == CN ? "��Ӽӷ�" : "AnyMTax,";
}
string btax_s() {
	return _lang == CN ? "ս��ӷ�" : "BcryTax.";
}
string able_s() {
	return _lang == CN ? "���̿���" : "StabAble";
}
string able2_s() {
	return _lang == CN ? "�ݴ̿���" : "BoneAble";
}
string plyd_s() {
	return _lang == CN ? "��������" : "CrdsPlyd";
}
string samp_s() {
	return _lang == CN ? "�鿴����" : "ViewSamp";
}
string cl_s() {
	return _lang == CN ? "��" : "Cl";
}
string a0_s() {
	return _lang == CN ? "�Ż�����" : "PrepDisc";
}
string a1_s() {
	return _lang == CN ? "��ǧ����" : "FoxyDisc";
}
string a2_s() {
	return _lang == CN ? "��һ����" : "Nxt1Disc";
}
string a3_s() {
	return _lang == CN ? "�¶�����" : "Nxt2Disc";
}
string hint_s() {
	return _lang == CN ? "������¯ʯ��˵����·�����س�ȷ�ϣ�" : "Please enter the local path of HS:";
}
string calcing_s() {
	return _lang == CN ? "(���ڼ���)" : "(Calcing.)";
}
string exhaust_s() {
	return _lang == CN ? "(�����)" : "(Exhaust.)";
}
string targrch_s() {
	return _lang == CN ? "(�������)" : "(TargRch.)";
}
string timerch_s() {
	return _lang == CN ? "(ʱ������)" : "(TimeRch.)";
}
string iceblock_s() {
	return _lang == CN ? "�Ʊ���Ҫ" : "IceBlock";
}
string heroattk_s() {
	return _lang == CN ? "Ӣ�۹���" : "HeroAttk";
}
string demi_s() {
	return _lang == CN ? "����" : "Demi";
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