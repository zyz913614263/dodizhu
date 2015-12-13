#pragma once
#include "SimpleAudioEngine.h"
#include <string>
#include <vector>
#include "global.h"
using namespace std;

class Music
{
public:
	static Music *GetInstance(){static Music *mu=new Music(); return mu;};
	void playSound(const char *path,bool flag=false);
	void outCardSound(bool sex,char card,char type);
	void jiaoFenSound(bool sex,char type);
	void isOut(bool sex,bool type);
	void playEffect(const char *path);
	void isWin(bool type);
private:
	Music(void);
	~Music(void);
};

