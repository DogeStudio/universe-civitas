#pragma once
#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

float rand(int a,int b)//产生一个范围内的随机数
{return (rand() % (b-a+1))+ a;}

void outln(string text)
{cout<<text<<endl;}

string tostring(int i)
{
    char t[256];
    string s;
    sprintf(t,"%d",i);
    s=t;
    return s;
}

bool boolrand()//两个随机值里选择
{
    int seed=rand(0,2);
    if(seed==2)
    {return erfenzhiyiquanzhong();}
    if(seed>=0&&seed<1)
    {return true;}
    return false;
}
