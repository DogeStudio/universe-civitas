#pragma once
#include <string>
#include <list>

using namespace std;

enum jiaoliu{gongji,fangyu,youhao};
list<wenming*> suoyouwm;//所有文明
const long long wuqiong;//无穷的大小，之前那个数不好，你再想一个吧

class wenming
{
public:
	wenming(string name,int x,int y,int tansuox,int tansuoy);

	int num;//序号
    int wmzhi;//文明值，代表文明的综合素质
    jiaoliu jltezheng;//交流特征
    bool tstezheng;//探索特征，true为是，false为否
    string name;
	//位置
    int x;
    int y;
	//探索到的范围
    int tansuox;
    int tansuoy;
    
	void clone();
	string getname();
};

struct feixingwu
{
    int gaibianwmz;
    int sudo;
    int shengyult;//到达目标的剩余回合数
    int fashewenming;//发射的文明
    int jieshouwenming;//接收的文明
    int num;
};
