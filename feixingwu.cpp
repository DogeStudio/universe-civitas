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
	outln(fashewenming->getname()+"向"+jieshouwenming->getname()+"发射了"+gettype());
	//计算到达需要回合数
	float lucheng=sqrt(pow(fashewenming->x-jieshouwenming->x,2)+pow(fashewenming->y-jieshouwenming->y,2));//求路程，不过似乎有点问题（妈了个鸡的有啥问题你倒是说明白了啊
	this->shengyult=lucheng/anewfxw->sudu;//到达需要的回合数
	outln(gettype()+"还有"+tostring(anewfxw->shengyult)+"轮到达"+jieshouwenming->getname());
	if(this->shengyult<=0)
    {action();}
	//到这里，没写完（这是我当年写的，我也不知道哪没写完，我感觉写完了啊）
}

string feixingwu::gettype()
{
	if (gaibianwmz>=0)
	{return "交流飞船";}
	return "战舰";
}

void feixingwu::action()
{
	jieshouwenming->wmzhi=this->gaibianwmz;
	outln(fashewenming->getname()+"的"+gettype()+"降落在了"+jieshouwenming->getname());
	outln("   "+jieshouwenming->getname()+"目前文明值为"+tostring(jieshouwenming->wmzhi));
}
