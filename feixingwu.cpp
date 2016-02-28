#include <iostream>
#include <math.h>
#include "help.h"
#include "var.h"

feixingwu::feixingwu(int gaibianwmz,int sudu,wenming* fashewenming,wenming* jieshouwenming)
{
	fxwnum++;
	if(fxwnum==wuqiong)
    {
      exit(-1);//异常退出之一，-1为飞行器数量过多
    }
	this->num=fxwnum;
	//正式开始添加
	this->gaibianwmz=gaibianwmz;
	this->sudu=sudu;
	this->fashewenming=fashewenming;
	this->jieshouwenming=jieshouwenming;
	suoyoufxw.push_back(anewfxw);
	//到这里，没写完（这是我当年写的，我也不知道哪没写完）
}