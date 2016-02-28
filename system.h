#pragma once
#include <string>
#include <vector>
#include <math.h>
#include "parameter.h"
#include "help.h"
using namespace std;

//前置声明
class wenming;
class feixingwu;

//全局变量
enum jiaoliu{gongji,fangyu,youhao};
extern vector<wenming*> suoyouwm;//所有文明
extern vector<feixingwu*> suoyoufxw;//所有飞行物
extern unsigned long long wmnum;//文明数
extern unsigned long long fxwnum;//飞行器数

//宇宙事件
void wzzlxiajiang(int xiajiang);

//wenming（我实在懒得整理到一个文件里了，就这么凑合办吧
jiaoliu randjl();//决定交流特征，三个枚举值里选择
bool fanweipanduan(int ix,int iy,int ax,int ay,int tansuox,int tansuoy);
class wenming
{
public:
    wenming(string name,int x,int y,int tansuox,int tansuoy,jiaoliu jltezheng,bool tstezheng);
    wenming(){}
	~wenming();
	void setwmzhi(int wmzhigaibian);
	void clone();
	string getname();
    string name;
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
    string gettypeStr();
    bool gettype();
	void action();
	void feixing();

	bool isreplyed=false;
    wenming* fashewenming;//发射的文明
    wenming* jieshouwenming;//接收的文明
	
private:
    int gaibianwmz;
    int sudu;
	int shengyult;//到达目标的剩余回合数
    int num;
};

