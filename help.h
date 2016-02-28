#pragma once
#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

class Rand
{
public:
    static float random(int a,int b)//产生一个范围内的随机数
    {return (rand() % (b-a+1))+ a;}
    
    static bool rand_1_2()//二分之一权重的随机
    {
        int seed=random(0,2);
        if(seed==2)
        {return rand_1_2();}
        if(seed>=0&&seed<1)
        {return true;}
        return false;
    }
    
    bool rand_2_3()//二分之三权重的随机
    {
      int seed=random(0,3);
      if(seed==3)
      {return rand_2_3();}
      if((seed>=0&&seed<1)||(seed>=1&&seed<2))
      {return true;}
      return false;
    }
};

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


