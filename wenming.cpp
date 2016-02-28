#include <iostream>
#include <math.h>
#include "help.h"
#include "var.h"

wenming::wenming(string name,int x,int y,int tansuox,int tansuoy)
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
}

void wenming::clone()
{
	wenming *anewwm=new wenming;
	*anewwm=*this;
	/*
	这块应该是……
	决定新文明坐标的代码……
	但是……
	我自己看不懂了TAT！！
	所以略
	*/
	outln(getname()+"在"+tostring(this->x)+","+tostring(this->y)+"处发展出了一个分支文明");
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
