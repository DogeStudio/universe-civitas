#include "help.h"

float Rand::random(unsigned long long a,unsigned long long b)//产生一个范围内的随机数
{return (rand() % (b-a+1))+ a;}

bool Rand::rand_1_2()//二分之一权重的随机
{
    int seed=random(0,2);
    if(seed==2)
    {return rand_1_2();}
    if(seed>=0&&seed<1)
    {return true;}
    return false;
}

bool Rand::rand_2_3()//二分之三权重的随机
{
  int seed=random(0,3);
  if(seed==3)
  {return rand_2_3();}
  if((seed>=0&&seed<1)||(seed>=1&&seed<2))
  {return true;}
  return false;
}

string tostring(int i)
{
    char t[256];
    string s;
    sprintf(t,"%d",i);
    s=t;
    return s;
}


