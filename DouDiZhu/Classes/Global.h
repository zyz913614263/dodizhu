#pragma once
#include <vector>
#include "music.h"
const int pkWidth = 71;//牌的宽
const int pkHeight = 96;//牌的高
const int pkJianJu = 20;//牌与牌之间的间距

//花色
enum HuaSe	
{
	HeiTao = 0,
	HongTao,
	MeiHua,
	FangKuai,
	Gui,
	HuaSeBM = 4     //花色背面
};
//牌号
enum PaiHao
{
	San = 0,Si,Wu,Liu,Qi,Ba,Jiu,Shi,ShiYi,ShiEr,ShiSan,Yi,Er,XiaoGui,DaGui,
	PaiHaoBM=2 //牌号背面
};
//标签
enum BiaoQian
{
	FenShu,
	NpcTwoBuChu,
	NpcOneBuChu
};
//斗地主共有13种牌型
enum CARD_TYPE
{
	SINGLE_CARD = 1,		//单牌-
	DOUBLE_CARD,			//对子-
	THREE_CARD,				//3不带-
	BOMB_CARD,				//炸弹
	THREE_ONE_CARD,			//3带1-
	THREE_TWO_CARD,			//3带2-
	BOMB_TWO_CARD,			//四个带2张单牌
	BOMB_TWOOO_CARD,		//四个带2对
	CONNECT_CARD,			//连牌-
	COMPANY_CARD,			//连队-
	AIRCRAFT_CARD,			//飞机不带-
	AIRCRAFT_SINGLE_CARD,	//飞机带单牌-
	AIRCRAFT_DOBULE_CARD,	//飞机带对子-
	ERROR_CARD				//错误的牌型
} ;
struct CRAD_INDEX//分析飞机，四带用
{
	std::vector<int> single_index;//单张
	std::vector<int> duble_index;//双张
	std::vector<int> three_index;//三张
	std::vector<int> four_index;//四张
};

