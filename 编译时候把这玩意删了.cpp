#include <iostream>
#include <math.h>
#include "help.h"
#include "var.h"

using namespace std;

string numorname(int i)
{
  if(suoyouwm[i]->name!="")
  {return suoyouwm[i]->name;}
  return tostring(i)+"号文明";
}

string wenmingtexing(int i)
{
    string texing="文明特性为";
    if(suoyouwm[i]->jltezheng==gongji)
    {texing+="攻击";}
    if(suoyouwm[i]->jltezheng==fangyu)
    {texing+="防御";}
    if(suoyouwm[i]->jltezheng==youhao)
    {texing+="友好";}
    if(suoyouwm[i]->tstezheng)
    {texing+="和探索";}
    else
    {texing+="和保守";}
    return texing;
}

jiaoliu randjl()//决定交流特征，三个枚举值里选择
{
    float seed=rand(0,3);
    if(seed==3)
    {return randjl();}
    if(seed>=0&&seed<1)
    {return gongji;}
    if(seed>=1&&seed<2)
    {return fangyu;}
    else
    {return youhao;}
}

bool fxwshengxiao(int a)//此项为真的飞行物无需行动
{
    if (suoyoufxw[a]->shengyult<=0)
    {return true;}
    else
    {return false;}
}

void wmtozero(int i)//文明归零不是文明值为0，而是彻底被杀死了
{
    shuchu(numorname(i)+"遭到归零");
    suoyouwm[i]->wmzhi=-1;
    suoyouwm[i]->tansuox=0;
    suoyouwm[i]->tansuoy=0;
}

bool wmshengsi(int i)//此项为假的文明不能行动
{
    if(suoyouwm[i]->wmzhi>0)//文明值大于0为活着
    {return true;}
    else
    {return false;}
}

bool wmzhengfan(int i)//判断是否是反物质文明（即在正宇宙空间以外）
{
    if(suoyouwm[i]->x>=yuzhoux)
    {return false;}
    if(suoyouwm[i]->y>=yuzhouy)
    {return false;}
    return true;
}

void newfxw(feixingwu *anewfxw)
{
    fxwnum++;
    if(fxwnum==wuqiong)
    {
      exit(-1);//异常退出之一，-1为飞行器数量过多
    }
    suoyoufxw.push_back(anewfxw);
    anewfxw->num=fxwnum;
    //到这里，没写完
}

void newwm(wenming *anewwm)
{
    wmnum++;
    if(wmnum==wuqiong)
    {
      exit(-2);//异常退出之二，-2为文明数量过多
    }
    suoyouwm.push_back(anewwm);//正式添加新文明
    anewwm->name="";
    anewwm->tansuox=0;
    anewwm->tansuoy=0;
    anewwm->num=wmnum;//目前产生的这个文明的序号
}

void gongjixingwei(int a,int i)
{
    feixingwu *anewfxw=new feixingwu;
    newfxw(anewfxw);
    anewfxw->gaibianwmz=hudongxishu*(-1)-suoyouwm[i]->wmzhi;
    anewfxw->sudo=suoyouwm[i]->wmzhi*suduxishu;
    anewfxw->fashewenming=i;
    anewfxw->jieshouwenming=a;
    shuchu(numorname(i)+"向"+numorname(a)+"发射了战舰");
    float lucheng=sqrt(pow(suoyouwm[a]->x-suoyouwm[i]->x,2)+pow(suoyouwm[a]->y-suoyouwm[i]->y,2));//勾股定理求路程，不过似乎有点问题
    int t=lucheng/anewfxw->sudo;
    anewfxw->shengyult=t;
    shuchu("战舰还有"+tostring(t)+"轮到达"+numorname(a));
    if(anewfxw->shengyult<=0)
    {
        suoyouwm[anewfxw->jieshouwenming]->wmzhi+=anewfxw->gaibianwmz;
        shuchu(numorname(a)+"遭到了战舰打击，目前文明值为"+tostring(suoyouwm[a]->wmzhi));
    }
}

void bangzhuxingwei(int a,int i)
{
    feixingwu *anewfxw=new feixingwu;
    newfxw(anewfxw);
    anewfxw->gaibianwmz=hudongxishu-suoyouwm[i]->wmzhi;
    anewfxw->sudo=suoyouwm[i]->wmzhi*suduxishu;
    anewfxw->fashewenming=i;
    anewfxw->jieshouwenming=a;
    shuchu(numorname(i)+"向"+numorname(a)+"发射了交流飞船");
    float lucheng=sqrt(pow(suoyouwm[a]->x-suoyouwm[i]->x,2)+pow(suoyouwm[a]->y-suoyouwm[i]->y,2));//勾股定理求路程，不过似乎有点问题
    int t=lucheng/anewfxw->sudo;
    anewfxw->shengyult=t;
    shuchu("飞船还有"+tostring(t)+"轮到达"+numorname(a));
    if(anewfxw->shengyult<=0)
    {
        suoyouwm[anewfxw->jieshouwenming]->wmzhi+=anewfxw->gaibianwmz;
        shuchu(numorname(a)+"得到了帮助，目前文明值为"+tostring(suoyouwm[a]->wmzhi));
    }
}

bool fanweipanduan(int ix,int iy,int ax,int ay,int tansuox,int tansuoy)
{return ax<=ix+tansuox&&ax>=ix-tansuox&&ay<=iy+tansuox&&ay>=iy-tansuoy;}

bool erfenzhisanquanzhong()//二分之三权重的随机
{
  int seed=rand(0,3);
  if(seed==3)
  {return erfenzhisanquanzhong();}
  if((seed>=0&&seed<1)||(seed>=1&&seed<2))
  {return true;}
  return false;
}

bool erfenzhiyiquanzhong()//决定探索特征，两个随机值里选择
{
    int seed=rand(0,2);
    if(seed==2)
    {return erfenzhiyiquanzhong();}
    if(seed>=0&&seed<1)
    {return true;}
    return false;
}

void wzzlxiajiang(int xiajiang)
{
    wuzhizongliang-=xiajiang;
    if(wuzhizongliang<=0)
    {
      exit(0);//宇宙物质耗尽，正常退出
    }
}

void chanshengwenming()
{
    int chanshengnum=rand(0,wuqiong);//随机确认产生的数量
    for(int i=0;i<=chanshengnum;i++)
    {
      wenming *anewwm=new wenming;
      newwm(anewwm);
      anewwm->wmzhi=rand(0,wuqiong);//初始的文明值随机
      wzzlxiajiang(anewwm->wmzhi);
      anewwm->jltezheng=randjl();
      anewwm->tstezheng=erfenzhiyiquanzhong();
      anewwm->x=rand(0,yuzhoux);
      anewwm->y=rand(0,yuzhouy);
      shuchu(numorname(wmnum)+"在宇宙中产生，"+wenmingtexing(wmnum)+"位置为"+tostring(anewwm->x)+","+tostring(anewwm->y));
    }
}

void yuzhougaibian()
{
    int gaibianx=rand(-1*wuqiong,wuqiong);
    int gaibiany=rand(-1*wuqiong,wuqiong);
    yuzhoux+=gaibianx;
    yuzhouy+=gaibiany;
    if(gaibianx<0)
    {
      shuchu("宇宙横轴坍缩，目前横轴为"+tostring(yuzhoux)+"个长度单位");
      for(int i=0;i<=wmnum;i++)
      {
          if(suoyouwm[i]->x<yuzhoux)
          {wmtozero(i);}
      }
    }
    else
    {shuchu("宇宙横轴膨胀，目前横轴为"+tostring(yuzhoux)+"个长度单位");}
    if(gaibiany<=0)
    {
      shuchu("宇宙纵轴坍缩，目前纵轴为"+tostring(yuzhouy)+"个长度单位");
      for(int i=0;i<=wmnum;i++)
      {
          if(suoyouwm[i]->y<yuzhouy)
          {wmtozero(i);}
      }
    }
    else
    {shuchu("宇宙纵轴膨胀，目前纵轴为"+tostring(yuzhouy)+"个长度单位");}
}

void kelongwm(int i)
{
    wenming *anewwm=new wenming;
    *anewwm=*suoyouwm[i];
    newwm(anewwm);
    int jiazhi;
    if(erfenzhiyiquanzhong())
    {jiazhi=1;}
    else
    {jiazhi=-1;}
    anewwm->x+=jiazhi;
    if(erfenzhiyiquanzhong())
    {jiazhi=1;}
    else
    {jiazhi=-1;}
    anewwm->y+=jiazhi;
    shuchu(numorname(i)+"在"+tostring(anewwm->x)+","+tostring(anewwm->y)+"处发展出了一个分支文明");
}

void xingdong()
{
    for(int i=0;i<=wmnum;i++)
    {
      if(!wmshengsi(i))//文明值小于0先跳过
      {continue;}
      if(!wmzhengfan(i))//反物质文明也先跳过
      {continue;}

      if(suoyouwm[i]->jltezheng==gongji)//如果文明的特征是攻击
      {
          for(int a=0;a<=wmnum;a++)//文明值决定着一次能攻击的数量？
          {
              if(a==i)//先看看攻击的是不是自己
              {continue;}
              //判断是否在攻击范围内
              if(fanweipanduan(suoyouwm[i]->x,suoyouwm[i]->y,suoyouwm[a]->x,suoyouwm[a]->y,suoyouwm[i]->tansuox,suoyouwm[i]->tansuoy))
              {gongjixingwei(a,i);}
          }
      }
      if(suoyouwm[i]->jltezheng==youhao)
      {
          for(int a=0;a<=wmnum;a++)
          {
              if(a==i)
              {continue;}
              if(fanweipanduan(suoyouwm[i]->x,suoyouwm[i]->y,suoyouwm[a]->x,suoyouwm[a]->y,suoyouwm[i]->tansuox,suoyouwm[i]->tansuoy))
              {bangzhuxingwei(a,i);}
          }
      }
      if(suoyouwm[i]->jltezheng==fangyu)
      {
          for(int a=0;a<=fxwnum;a++)
          {
            if(
                suoyouwm[suoyoufxw[a]->fashewenming]->x<=suoyouwm[i]->x+suoyouwm[i]->tansuox
              &&suoyouwm[suoyoufxw[a]->fashewenming]->x>=suoyouwm[i]->x-suoyouwm[i]->tansuox
              &&suoyouwm[suoyoufxw[a]->fashewenming]->y<=suoyouwm[i]->y+suoyouwm[i]->tansuoy
              &&suoyouwm[suoyoufxw[a]->fashewenming]->y>=suoyouwm[i]->y-suoyouwm[i]->tansuoy
              &&suoyoufxw[a]->jieshouwenming==i
              &&suoyoufxw[a]->fashewenming!=i
              &&wmshengsi(suoyoufxw[a]->fashewenming))
            {
                if(suoyoufxw[a]->gaibianwmz<0)
                {gongjixingwei(suoyoufxw[a]->fashewenming,i);}
                if(suoyoufxw[a]->gaibianwmz>0)
                {bangzhuxingwei(suoyoufxw[a]->fashewenming,a);}
            }
          }
      }
      //下面是互动
      if(suoyouwm[i]->tstezheng)
      {
          if(erfenzhisanquanzhong())
          {
              suoyouwm[i]->tansuox+=suoyouwm[i]->wmzhi*tansuoxishu;
              suoyouwm[i]->tansuoy+=suoyouwm[i]->wmzhi*tansuoxishu;
              shuchu(numorname(i)+"进行了探索，目前的探索范围是横轴"+tostring(suoyouwm[i]->tansuox)+"个长度单位，纵轴"+tostring(suoyouwm[i]->tansuoy)+"个长度单位");
          }
          else
          {kelongwm(i);}
      }
      else
      {
          if(erfenzhisanquanzhong())
          {
              suoyouwm[i]->tansuox+=suoyouwm[i]->wmzhi*tansuoxishu;
              suoyouwm[i]->tansuoy+=suoyouwm[i]->wmzhi*tansuoxishu;
              shuchu(numorname(i)+"进行了探索，目前的探索范围是横轴"+tostring(suoyouwm[i]->tansuox)+"个长度单位，纵轴"+tostring(suoyouwm[i]->tansuoy)+"个长度单位");
          }
      }
      int wmzzengjia=rand(0,wuqiong);
      suoyouwm[i]->wmzhi+=wmzzengjia;
      shuchu(numorname(i)+"发展，目前的文明值是"+tostring(suoyouwm[i]->wmzhi));
      wzzlxiajiang(wmzzengjia);
    }
}

void feixing()
{
  for(int i=0;i<=fxwnum;i++)
  {
      if(fxwshengxiao(i))
      {continue;}
      suoyoufxw[i]->shengyult--;
      if(suoyoufxw[i]->shengyult<=0)
      {
          suoyouwm[suoyoufxw[i]->jieshouwenming]->wmzhi+=suoyoufxw[i]->gaibianwmz;
          if(suoyoufxw[i]->gaibianwmz>0)
          {shuchu("来自"+numorname(suoyoufxw[i]->fashewenming)+"的"+tostring(i)+"号战舰进攻"+numorname(suoyoufxw[i]->jieshouwenming)+"，目前"+numorname(suoyoufxw[i]->jieshouwenming)+"的文明值是"+tostring(suoyouwm[suoyoufxw[i]->jieshouwenming]->wmzhi));}
          else
          { shuchu("来自"+numorname(suoyoufxw[i]->fashewenming)+"的"+tostring(i)+"号交流飞船访问"+numorname(suoyoufxw[i]->jieshouwenming)+"，目前"+numorname(suoyoufxw[i]->jieshouwenming)+"的文明值是"+tostring(suoyouwm[suoyoufxw[i]->jieshouwenming]->wmzhi));}
      }
      shuchu("来自"+numorname(suoyoufxw[i]->fashewenming)+"的"+tostring(i)+"号飞行器还有"+tostring(suoyoufxw[i]->shengyult)+"轮到达"+numorname(suoyoufxw[i]->jieshouwenming));
  }
}

int main()
{
    srand((unsigned)time(NULL));//开始先设定随机种子
    int t=1;//设定回合数为1
    //决定宇宙大小
    yuzhoux=rand(0,wuqiong);
    yuzhouy=rand(0,wuqiong);
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
        t++;
        cout<<"【第一回合结束】"<<endl;//应该把时间写上
    }
}
