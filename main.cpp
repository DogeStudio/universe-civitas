#include "system.h"

unsigned long long wmnum=-1;//文明数
unsigned long long fxwnum=-1;//飞行器数

void chanshengwenming()
{
    int chanshengnum=Rand::random(0,wuqiong);//随机确定产生的数量
    for(int i=0;i<=chanshengnum;i++)
    {
      wenming *anewwm=new wenming("",Rand::random(0,yuzhoux),Rand::random(0,yuzhouy),0,0,randjl(),Rand::rand_1_2());
      anewwm->setwmzhi(Rand::random(0,wuqiong));//初始的文明值随机
      coutln(anewwm->getname()+"在宇宙中产生，"+anewwm->gettezheng()+"位置为"+tostring(anewwm->x)+","+tostring(anewwm->y));
    }
}

void xingdong()
{
    for(auto i:suoyouwm)
    {
        if(!i->isalive())//半死不活先跳过
        {continue;}
        if(i==nullptr)//真死了的也跳过
        {continue;}
        i->xingdong();
    }
}

void feixing()
{
    for(auto i:suoyoufxw)
    {
        if(i==nullptr)
        {continue;}
        i->feixing();
    }
}

int main()
{
    srand((unsigned)time(NULL));//开始先设定随机种子
    int t=1;//设定回合数为1
    int num;
    while(1)
    {
        chanshengwenming();//生成新文明
        xingdong();//文明行动
        feixing();//飞行器飞行
        cout<<"【输入想操作的文明序号并给它一个别名，如果什么都不想做按-1】"<<endl;
        cin>>num;
        if(num!=-1)
        {
            cout<<"【请输入该文明的别名】"<<endl;
            cin>>suoyouwm[num]->name;
        }
        cout<<"【第"+tostring(t)+"回合结束】"<<endl;
        t++;
    }
}
