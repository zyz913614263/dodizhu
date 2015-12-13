#include "Music.h"

const char dir[] = "sound/";
const char ext[] = ".mp3";
//背景音乐
const char back[]="mg_bg";//1
const char boom[]="boombeffect";//2
const char chupai[] = "chupai";//3
const char get_glod[] = "get_glod";//4
const char lose[] = "lose";//5
const char lot_end[] = "lot_end";//6
const char lot_ing[] = "lot_ing";//7
const char planeeffect[]="planeeffect";//8
const char outcard[]="outcard";//9
const char warn[]="warn";//10
const char win[]="win";//11
const char winchoudi[]="winchoudi";//12

char man[][10]={"m_1_3","m_1_17","m_2_3","m_2_15","m_tuple3","m_tuple15"};
const char nan_feiji[] = "nan_feiji";
const char nan_jiabei[]="nan_jiabei";
const char nan_liandui[]="nan_liandui";
const char nan_pass[]="nan_pass";
const char nan_shunzi[]="nan_shunzi";
const char nan_wangzha[]="nan_wangzha";
const char nan_bujiabei[] = "nan_bujiabei";
const char nan_3dai0[] = "nan_3dai0";
const char nan_3dai1[] = "nan_3dai1";
const char nan_3dai2[] = "nan_3dai2";
const char nan_4dai2[] = "nan_4dai2";
const char nan_4dai22[] = "nan_4dai22";
const char nan_bomb[] = "nan_bomb";

void Music::isWin(bool type)
{
	if(type)
	{
		string path=dir+string("win")+ext;
		playEffect(path.c_str());
	}else 
	{
		string path=dir+string("lose")+ext;
		playEffect(path.c_str());
	}
}

void Music::isOut(bool sex,bool type)
{
	if(sex == false)
	{
		if(type)
		{
			string path=dir+string("chupai")+ext;
			playEffect(path.c_str());
		}else 
		{
			string path=dir+string("nan_pass")+ext;
			playEffect(path.c_str());
		}
	}
	else
	{
		if(type)
		{
			string path=dir+string("chupai")+ext;
			playEffect(path.c_str());
		}else 
		{
			string path=dir+string("nv_pass")+ext;
			playEffect(path.c_str());
		}
	}
}
void Music::jiaoFenSound(bool sex,char type)
{
	
	if(sex == false)
	{
		if(type == 0)
		{
			string path=dir+string("nan_bujiao")+ext;
			playEffect(path.c_str());
		}
		else
		{
			char tmp[20];
			sprintf_s(tmp,"nan_%dfen",type);
			string path="";
			path+=dir;
			path+=tmp;
			path+=ext;
			playEffect(path.c_str());
		}
	}
	else
	{
		if(type == 0)
		{
			string path=dir+string("nv_bujiao")+ext;
			playEffect(path.c_str());
		}
		else
		{
			char tmp[20];
			sprintf_s(tmp,"nv_%dfen",type);
			string path="";
			path+=dir;
			path+=tmp;
			path+=ext;
			playEffect(path.c_str());
		}
	};
}

Music::Music(void)
{
}


Music::~Music(void)
{
}

void Music::playSound(const char *path,bool flag)
{
	if(path == NULL) return;
	
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(path,flag);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(100);
}
void Music::playEffect(const char *path)
{
	if(path == NULL) return;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(path);
}
void Music::outCardSound(bool sex,char card,char type)
{
	switch(type)
	{
	case SINGLE_CARD:		//单牌-
		if(sex == false)
		{
			char tmp[20];
			sprintf_s(tmp,"m_1_%d",card);
			string path="";
			path+=dir;
			path+=tmp;
			path+=ext;
			playEffect(path.c_str());
		}
		else
		{
			char tmp[20];
			sprintf_s(tmp,"w_1_%d",card);
			string path="";
			path+=dir;
			path+=tmp;
			path+=ext;
			playEffect(path.c_str());
		};
		break;
	case DOUBLE_CARD:
		break;//对子-
	case THREE_CARD:				//3不带-
	case BOMB_CARD:			//炸弹
	case THREE_ONE_CARD:			//3带1-
	case THREE_TWO_CARD:			//3带2-
	case BOMB_TWO_CARD:			//四个带2张单牌
	case BOMB_TWOOO_CARD:		//四个带2对
	case CONNECT_CARD:			//连牌-
	case COMPANY_CARD:		//连队-
	case AIRCRAFT_CARD:			//飞机不带-
	case AIRCRAFT_SINGLE_CARD:	//飞机带单牌-
	case AIRCRAFT_DOBULE_CARD:	//飞机带对子-
	case ERROR_CARD:				//错误的牌型
	default: break;
	} ;
	
}