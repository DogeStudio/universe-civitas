#include "var.h"

list<wenming*> suoyouwm;//所有文明

wenming::wenming(string name,int x,int y,int tansuox,int tansuoy,jiaoliu jltezheng,bool tstezheng)
{
	wmnum++;
	if(wmnum==wuqiong)
    {
      exit(-2);//异常退出之二，-2为文明数量过多
    }
	this->num=wmnum;
	//正式开始添加
	suoyouwm.push_back(this);
	this->x=x;
	this->y=y;
	this->name=name;
	this->tansuox=tansuox;
	this->tansuoy=tansuoy;
	this->jltezheng=jltezheng;
	this->tstezheng=tstezheng;
}

wenming::wenming(wenming* native)
{
	wenming(native->x,native->y,native->name,native->tansuox,native->tansuoy,native->jltezheng,native->tstezheng);
}

wenming::~wenming()
{num]=nullptr;}

void wenming::clone()
{
	wenming *anewwm=new wenming(this);
	/*
	这块应该是……
	决定新文明坐标的代码……
	但是……
	我自己看不懂了TAT！！
	所以略
	*/
	outln(getname()+"在"+tostring(this->x)+","+tostring(this->y)+"处发展出了一个分支文明");
}

void wenming::setwmzhi(int wmzhigaibian)
{
	wzzlxiajiang(wmzhigaibian);//文明值增加，物质总量就会减少，黑暗森林的基本公理
	this->wmzhi+=wmzhigaibian;
}

string wenming::getname()
{
	if(this->name!="")
	{return this->name;}
	return tostring(this->num)+"号文明";
}

string wenming::gettezheng()
{
    string texing="文明特性为";
    if(this->jltezheng==gongji)
    {texing+="攻击";}
    if(this->jltezheng==fangyu)
    {texing+="防御";}
    if(this->jltezheng==youhao)
    {texing+="友好";}
    if(this->tstezheng)
    {texing+="和探索";}
    else
    {texing+="和保守";}
    return texing;
}

void wenming::tozero()//文明归零不是文明值为0，而是彻底被杀死了
{
    outln(getname()+"遭到归零");
    delete this;
}

bool wenming::isalive()//此项为假的文明不能行动
{
    if(this->wmzhi>0)//文明值大于0为活着
    {return true;}
    else
    {return false;}
}

void wenming::attack(wenming* jieshouwenming)
{launch(-1,jieshouwenming);}

void wenming::help(wenming* jieshouwenming)
{launch(1,jieshouwenming);}

void wenming::launch(int one,wenming* jieshouwenming)
{
	if(!fanweipanduan(x,y,jieshouwenming->x,jieshouwenming->y,tansuox,tansuoy))
		return;
	
	int gaibianwmz=hudongxishu*one-this->wmzhi;
    int sudu=this->wmzhi*suduxishu;
	feixingwu *anewfxw=new feixingwu(gaibianwmz,sudu,this,jieshouwenming);
}

void wenming::explore()
{
	this->tansuox+=this->wmzhi*tansuoxishu;
    this->tansuoy+=this->wmzhi*tansuoxishu;
    outln(getname()+"进行了探索，目前的探索范围是横轴"+tostring(tansuox)+"个长度单位，纵轴"+tostring(tansuoy)+"个长度单位");
}

bool wenming::operator == (const wenming& a)
{return this->num==a.num;}

void wenming::xingdong()
{
    if(this->jltezheng==gongji)//如果文明的特征是攻击
    {
        for(auto a:suoyouwm)
        {
			if(this==a)
			{continue;}
			this->attack(a);
		}
    }
    if(this->jltezheng==youhao)
    {
        for(auto a:suoyouwm)
        {
			if(this==a)
			{continue;}
			this->help(a);
        }
    }
    if(this->jltezheng==fangyu) //防御，被帮就帮，被打就打
    {
        for(auto a:suoyoufxw)
        {
          if(fanweipanduan(this->x,this->y,a->fashewenming->x,a->fashewenming->y,this->tansuox,this->tansuoy)
            &&a->jieshouwenming==this
			&&!a->isreplyed)
          {
			if(a->gaibianwmz<0)
			{this->attack(a);}
			if(a->gaibianwmz>0)
			{this->help(a);}
			a->isreplyed=true;
          }
        }
    }
    //下面是探索
    if(this->tstezheng)
    {
        if(Rand::rand_2_3())
        {this->explore();}
        else
        {this->clone();}
    }
    else
    {
        if(Rand::rand_2_3())
        {this->explore();}
    }
	
	int wmzhigaibian=rand(-1*wuqiong,wuqiong);
    setwmzhi(wmzhigaibian);
	if(wmzhigaibian>0)
		outln(getname()+"发展，目前的文明值是"+tostring(wmzhi));
	if(wmzhigaibian<0)
		outln(getname()+"内战，目前的文明值是"+tostring(wmzhi));
}
