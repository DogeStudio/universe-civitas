#include "system.h"

unsigned long long wuzhizongliang;

void wzzlxiajiang(int xiajiang)
{
    wuzhizongliang-=xiajiang;
    if(wuzhizongliang<=0)
    {
      exit(0);//宇宙物质耗尽，正常退出
    }
}

jiaoliu randjl()//决定交流特征，三个枚举值里选择
{
    float seed=Rand::random(0,3);
    if(seed==3)
    {return randjl();}
    if(seed>=0&&seed<1)
    {return gongji;}
    if(seed>=1&&seed<2)
    {return fangyu;}
    else
    {return youhao;}
}

bool fanweipanduan(int ix,int iy,int ax,int ay,int tansuox,int tansuoy)
{return ax<=ix+tansuox&&ax>=ix-tansuox&&ay<=iy+tansuox&&ay>=iy-tansuoy;}
