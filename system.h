#pragma once
#include <string>
#include <list>
#include <math.h>
#include "parameter.h"
using namespace std;

//前置声明
class wenming;
class feixingwu;

//全局变量
enum jiaoliu{gongji,fangyu,youhao};
extern list<wenming*> suoyouwm;//所有文明
extern list<feixingwu*> suoyoufxw;//所有飞行物
extern int wmnum;//文明数
extern int fxwnum;//飞行器数

//宇宙事件
void wzzlxiajiang(int xiajiang)
{
    wuzhizongliang-=xiajiang;
    if(wuzhizongliang<=0)
    {
      exit(0);//宇宙物质耗尽，正常退出
    }
}

//wenming（我实在懒得整理到一个文件里了，就这么凑合办吧
jiaoliu randjl()//决定交流特征，三个枚举值里选择
{
    float seed=Rand::random(0,3);
    if(seed==3)
    {return randjl();}
    if(seed>=0&&seed<1)
    {return gongji;}
    if(seed>=1&&seed<2)
    {return fangyu;}
    else
    {return youhao;}
}

bool fanweipanduan(int ix,int iy,int ax,int ay,int tansuox,int tansuoy)
{return ax<=ix+tansuox&&ax>=ix-tansuox&&ay<=iy+tansuox&&ay>=iy-tansuoy;}

class wenming
{
public:
	wenming(string name,int x,int y,int tansuox,int tansuoy,jiaoliu jltezheng);
	wenming(wenming* native);
	~wenming();
	void setwmzhi(int wmzhigaibian);
	void clone();
	string getname();
	string gettezheng();
	void tozero();//挂掉
	bool isalive();//此项为假的文明不能行动
	void attack(wenming* jieshouwenming);
	void help(wenming* jieshouwenming);
	void explore();
	void xingdong();
	bool operator == (const wenming& a);
	
	//位置
    int x;
    int y;
	int wmzhi;//文明值，代表文明的综合素质
	
private:
	void launch(int one,wenming* jieshouwenming);
	int num;//序号
    jiaoliu jltezheng;//交流特征
    bool tstezheng;//分裂特征，true会克隆，false不会克隆
    string name;
	//探索到的范围
    int tansuox;
    int tansuoy;
};

//飞行物相关TAT
class feixingwu
{
public:
	feixingwu(int gaibianwmz,int sudo,wenming* fashewenming,wenming* jieshouwenming);
	~feixingwu();
	string gettype();
	void action();
	void feixing();
	bool isreplyed=false;
	
private:
    int gaibianwmz;
    int sudu;
	int shengyult;//到达目标的剩余回合数
    wenming* fashewenming;//发射的文明
    wenming* jieshouwenming;//接收的文明
    int num;
};

