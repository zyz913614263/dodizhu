#pragma once
#include "cocos2d.h"
#include "GameScene.h"
USING_NS_CC;
class Player : public CCObject
{
public:
	Player();
	~Player();
	void updatePkWeiZhi();//设置牌的位置
	
private:
	CC_SYNTHESIZE(bool,m_sex,Sex);//性别 0男，1女
	CC_SYNTHESIZE(bool,m_isDiZhu,IsDiZhu);//是否为地主
	CC_SYNTHESIZE(bool,m_isCall,Call);//是否已叫地主
	CC_SYNTHESIZE(int,m_iCallNum,CallNum);//叫地主的分数
	CC_SYNTHESIZE(CCArray*,m_arrPk,ArrPk);//手里拥有的扑克牌
	CC_SYNTHESIZE(CCPoint,m_point,Point);//牌在桌面的初始位置
	CC_SYNTHESIZE(int,m_iPlayerClass,PlayerClass);//玩家种类:0为玩家，1为电脑，2为显示的三张牌,3为玩家要出的牌，4为电脑1要出的牌，5为电脑2要出的牌
	std::vector<PaiXing> m_vecPX;//保存牌型
	CC_SYNTHESIZE(bool,m_isOutPk,IsOutPk);//玩家是否出牌true:出 false:不出
};

