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