#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Rand
{
public:
    static float random(unsigned long long a,unsigned long long b);//产生一个范围内的随机数
    static bool rand_1_2();//二分之一权重的随机
    static bool rand_2_3();//二分之三权重的随机
};

inline void coutln(string text)
{cout<<text<<endl;}

string tostring(int i);


