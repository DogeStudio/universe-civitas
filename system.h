#pragma once
#include <string>
#include <list>

using namespace std;

enum jiaoliu{gongji,fangyu,youhao};
extern list<wenming*> suoyouwm;//所有文明
extern int wmnum;//文明数
extern int fxwnum;//飞行器数
#define wuqiong //无穷的大小，之前那个数不好，你再想一个吧

//wenming相关（我实在懒得整理到一个文件里了，就这么凑合办吧
jiaoliu randjl()//决定交流特征，三个枚举值里选择
{
    float seed=rand(0,3);
    if(seed==3)
    {return randjl();}
    if(seed>=0&&seed<1)
    {return gongji;}
    if(seed>=1&&seed<2)
    {return fangyu;}
    else
    {return youhao;}
}

class wenming
{
public:
	wenming(string name,int x,int y,int tansuox,int tansuoy);
    int wmzhi;//文明值，代表文明的综合素质
	void clone();
	string getname();
	string gettezheng();
	void tozero();//挂掉
	bool isalive();//此项为假的文明不能行动
	void attack();
	void help();
	
private:
	void launch(int one,wenming* jieshouwenming);
	int num;//序号
    jiaoliu jltezheng;//交流特征
    bool tstezheng;//探索特征，true为是，false为否
    string name;
	//位置
    int x;
    int y;
	//探索到的范围
    int tansuox;
    int tansuoy;
};

//飞行物相关TAT
class feixingwu
{
public:
	feixingwu(int gaibianwmz,int sudo,wenming* fashewenming,wenming* jieshouwenming);
	string gettype();
	void action();
	
private:
    int gaibianwmz;
    int sudu;
	int shengyult;//到达目标的剩余回合数
    wenming* fashewenming;//发射的文明
    wenming* jieshouwenming;//接收的文明
    int num;
};

