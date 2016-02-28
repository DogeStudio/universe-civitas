#pragma once
#include <string>
#include <list>

using namespace std;

enum jiaoliu{gongji,fangyu,youhao};

struct wenming
{
    int wmzhi;//文明值，代表文明的综合素质
    jiaoliu jltezheng;//交流特征
    bool tstezheng;//探索特征，true为是，false非否
    string name;
    int x;
    int y;
    int tansuox;
    int tansuoy;
    int num;
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

