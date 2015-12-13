#pragma once
#include "cocos2d.h"
#include "Global.h"
class GameScene;
USING_NS_CC;
class Poker : public CCSprite,public CCTouchDelegate
{
public:
	Poker();
	~Poker();
	static Poker* create(const char *pszFileName, const CCRect& rect);
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
	void showFront();//显示正面
	void showLast();//显示背面
	Poker* copy();//拷贝
	void setTouchPriority(int num);
	void SelectPkLuTou();//如果选择了牌就露出头
	void SelectPkSuoTou();//如果选择了牌就缩头
private:
	CC_SYNTHESIZE(bool,m_isSelect,Select);//是否已选
	CC_SYNTHESIZE(GameScene*,m_gameMain,GameMain);
	CC_SYNTHESIZE(bool,m_isDianJi,DianJi);//是否能被点击
	CC_SYNTHESIZE(int,m_huaSe,HuaSe);//花色
	CC_SYNTHESIZE(int,m_num,Num);//牌值
};
