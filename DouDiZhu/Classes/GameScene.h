#pragma once
#include "cocos2d.h"
#include "Global.h"
#include "vector"
class Poker;
class Player;
USING_NS_CC;
//记数 排序出的牌用
struct JiShu
{
	int pkZhi;//牌值
	int num; //牌数量
	CCArray* arr; //集合牌
};
//保存电脑牌型
struct PaiXing :public CCObject
{
	CARD_TYPE type;
	std::vector<Poker*> vec;
};
class GameScene : public CCLayer
{
public:
	GameScene();
	~GameScene();
	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	virtual void onEnter();
	virtual void onExit();
private:
	bool initBackGround();//加载背景
	bool initPlayer();//初始化玩家信息
	bool initAnNiu();//初始化叫分按钮
	Poker* selectPoker(int huaSe,int num);//生成一个牌
	bool createPokers();//创建一副扑克牌
	bool xiPai();//洗牌
	void SendPk();//发牌
	void MovePk(Player* play,Poker* pk);//发牌移动动画
	void Call(float dt);//叫地主
	void func(CCNode* pSender, void* pData);
	void update(float delta);
	void menuCallbackYi(CCObject* sender);
	void menuCallbackEr(CCObject* sender);
	void menuCallbackSan(CCObject* sender);
	void menuCallbackBuJiao(CCObject* sender);
	void menuChuPai(CCObject* sender);
	void menuBuChu(CCObject* sender);
	void menuShengLi(CCObject* sender);
	void menuShu(CCObject* sender);
	void NpcCall(Player* npc,Player* npc1);//电脑玩家叫分
	void ShowFenShu(CCPoint pt,int num); //显示分数
	bool InitNpcBuChuLable();//初始化NPC"不出"标签
	void OutCard(float delta);//出牌
	//玩家牌型的判断
	int PaiDuanPaiXing();//判断牌型
	bool IsLianPai();//是否为连牌
	bool IsLianDui();//是否为连队
	int IsFeiJi();//是否为飞机
	bool IsFeiJiLian(std::vector<int> vec);//飞机是否连牌
	CRAD_INDEX FenXiFeiJi();//分析飞机 
	//分拆电脑的牌
	void FenChaiNpcPai(Player* npc);
	void TiQuFeiJi(Player* npc,CARD_TYPE type,std::vector<PaiXing> &vec);//提取飞机
	void TiQuLianDui(Player* npc,std::vector<PaiXing> &vec);//提取连队
	void TiQuLianPai(Player* npc,std::vector<PaiXing> &vec);//提取连牌
	void NpcOutPoker(Player* npc,CCArray* out,Player* out1);//电脑出牌
	void NpcGenPoker(Player* npc,CCArray* out,Player* out1);//电脑跟牌
	bool SanDaiYiOrEr(Player* npc,CCArray* out,Player* out1);//出三带一或三带二
	bool FeiJiDaiChiBang(Player* npc,CCArray* out,Player* out1);//飞机带翅膀
	bool NpcChaiDan(Player* npc,CCArray* out ,Player* out1);//对电脑牌拆单张牌
	bool NpcChaiDui(Player* npc,CCArray* out,Player* out1);//对电脑牌拆对牌
	bool NpcChaiSan(Player* npc,CCArray* out,Player* out1);//对电脑牌拆三条
	bool NpcChaiFeiJi(Player* npc,CCArray* out,Player* out1);//对电脑牌拆飞机
	bool NpcChaiLianPai(Player* npc,CCArray* out,Player* out1);//对电脑牌拆连牌
	bool NpcChaiShuangShun(Player* npc,CCArray* out,Player* out1);//对电脑牌拆双顺
	int GetNpcPxNum(Player* npc,CARD_TYPE cardType);//返回NPC某牌型的个数
	int FenXiFeiJiNum(CCArray* arr);//分析飞机有几个三带
	void ClearOutPk();//清除所有出的牌
	bool IsOutPkFinish();//是否有玩家出完牌
	void IsShengLi();//胜利的判断
	void ReStart();//重新开始
public:
	void PlayerOutPaiXu(CCArray* m_arrPlayerOut);//对出的牌进行排序
private:
	CCArray* m_arrPokers;//所有的牌
	CC_SYNTHESIZE(Player*,m_player,Player);//玩家
	Player* m_npcOne;//电脑1
	Player* m_npcTwo;//电脑2
	Player* m_Three;//显示三张剩余牌
	CC_SYNTHESIZE(Player*,m_playerOut,PlayerOut);//玩家出的牌
	CC_SYNTHESIZE(CCArray*,m_arrPlayerOut,ArrPlayerOut);//玩家选的要出的牌
	Player* m_npcOneOut;//电脑1出的牌
	Player* m_npcTwoOut;//电脑2出的牌
	CCMenu* m_menu;//叫地主菜单
	CCMenu* m_chuPaiMenu;//出牌菜单
	CCMenu* m_menuShengLi;//胜利菜单
	CCMenu* m_menuShu;//输的菜单
	CCLabelTTF* m_lableDiZhu;//地主标签
	CCArray* m_arrGenPk;//要跟的牌
	bool m_isSend;//是否发完牌
	int m_iSendPk;//已发出第几张牌
	int m_iState;//当前状态 0：发牌状态 1：叫地主状态 2：出牌状态 3：结果状态
	int m_iCall;//论到谁叫斗地主 0：玩家 1：电脑1 2：电脑2
	int m_iCallTime;//论流叫地主
	int m_iOutCard;//论到谁出牌
	bool m_bCall[3];//分数是否被叫 m_bCall[0]:1分 m_bCall[1]:2分 m_bCall[2]:3分
	int m_type;//打出的类型
	int m_typeTem;//打出的类型副本
	bool m_isChiBang;//是否带上翅膀
	int m_count; //计算出飞机牌的个数
	int m_threeNum;//飞机带翅膀的飞机数
	CCPoint playerDiZhuLablePt;
	CCPoint npcOneDiZhuLablePt;
	CCPoint npcTwoDiZhuLablePt;
	Player* m_lastOut;//最后出牌的一方
	CC_SYNTHESIZE(bool,m_isOver,IsOver);
};