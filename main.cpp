#include "var.h"

void chanshengwenming()
{
    int chanshengnum=rand(0,wuqiong);//随机确定产生的数量
    for(int i=0;i<=chanshengnum;i++)
    {
	  wenming *anewwm=new wenming("",Rand::random(0,yuzhoux),Rand::random(0,yuzhouy),0,0,randjl(),Rand::rand_2_1());
	  anewwm->setwmzhi(Rand::random(0,wuqiong));//初始的文明值随机
      shuchu(anewwm->getname()+"在宇宙中产生，"+anewwm->gettezheng()+"位置为"+tostring(anewwm->x)+","+tostring(anewwm->y));
    }
}

int main()
{
	
}
