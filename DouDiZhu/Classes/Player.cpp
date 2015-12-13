#include "Player.h"
#include "Poker.h"
Player::Player():m_sex(false),m_isCall(false),m_iCallNum(0),m_isDiZhu(false),m_isOutPk(false)
{
	m_arrPk = CCArray::create();
	m_arrPk->retain();
}

Player::~Player()
{
	CC_SAFE_RELEASE(m_arrPk);
}
void Player::updatePkWeiZhi(){
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	int x,y;
	if(m_iPlayerClass == 0 || m_iPlayerClass == 3)
	{
		x = size.width/2-((m_arrPk->count()-1)*pkJianJu+pkWidth)/2;
		y = m_point.y;
	}
	else if(m_iPlayerClass == 1 || m_iPlayerClass == 4 || m_iPlayerClass == 5)
	{
		x = m_point.x;
		y = m_point.y;
	}
	else if(m_iPlayerClass == 2)
	{
		x = size.width/2-(m_arrPk->count()*pkWidth+(m_arrPk->count()-1)*pkJianJu)/2;
		y = m_point.y;
	}
	int num = 0;
	CCObject* object;
	//对牌进行排序
	if(m_iPlayerClass != 3 && m_iPlayerClass != 4 && m_iPlayerClass != 5)
		for(unsigned int i=0; m_arrPk->count()!=0 && i<m_arrPk->count()-1; ++i)
		{
			for(unsigned int j=0; j<m_arrPk->count()-1-i; ++j)
			{
				Poker* pk1 = (Poker*)m_arrPk->objectAtIndex(j);
				Poker* pk2 = (Poker*)m_arrPk->objectAtIndex(j+1);
				if(pk1->getNum() < pk2->getNum())
					m_arrPk->exchangeObject(pk1,pk2);
			}
		}
	//更新位置
	CCARRAY_FOREACH(m_arrPk,object){
		Poker* pk = (Poker*)object;
		if (m_iPlayerClass == 0 || m_iPlayerClass == 3)
		{
			pk->showFront();
			pk->setPosition(ccp(x+num*pkJianJu+pkWidth/2,y));
		}
		else if(m_iPlayerClass == 1 || m_iPlayerClass == 4 || m_iPlayerClass == 5)
		{
			pk->showFront();
			if(m_iPlayerClass == 1)
				pk->showLast();
			pk->setPosition(ccp(x,y-num*pkJianJu));
		}
		else if(m_iPlayerClass == 2)
		{
			pk->setPosition(ccp(x+num*pkJianJu+num*pkWidth+pkWidth/2,y));
		}
		++num;
	}
	//改变牌的z值或牌的优先
	int i=m_arrPk->count()-1;
	CCARRAY_FOREACH(m_arrPk,object){
		Poker* pk = (Poker*)object;
		//改变z值
		pk->setZOrder(pk->getPositionX());
		//改变优先级
		Poker* pk1 = (Poker *)m_arrPk->objectAtIndex(i--);
		pk->setTouchPriority(pk1->getPositionX());
	}
}