#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
using namespace std;
void SetPos(int x,int y)
{
    COORD pos;pos.X=y*2,pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Color(int a)
{
    if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
}
int Se,Tx,X=7,K,T,SS,xt,H=3,Wu,Mk;
int m[10001];
void Sheng()
{
    int R=rand()%10,RR=rand()%100;
    if(R==0) SS=rand()%3-1;K++;
    if(RR==0)
    {
        int rr=rand()%4+2;
        for(int i=1;i<=rr;i++) m[K+i+20]=2;
    }
    else if(m[K+20]==0) m[K+20]=SS;
}
void Map(int a)
{
    Color(0);
    if(a==1)
    {
        for(int i=0;i<=7;i++) SetPos(i,1),cout<<' ';
        SetPos(X,1);Color(Se+1);if(Wu!=0&&T%3==0) Color(4);
        if(X==7&&m[K+1]==2&&Wu<=0) SetPos(8,1);cout<<"●";
    }
    if(a==2)
    {
        SetPos(8,0);
        for(int i=K;i<=K+20;i++) {if(m[i]!=2) Color(m[i]+1),cout<<"■";else cout<<"  ";if(T==1) Sleep(30);}
    }
    if(a==3)
    {
        Color(3);if(Wu!=0&&T%3==0) Color(4);
        SetPos(3,15);for(int i=0;i<H;i++) cout<<"■";Color(0);
        SetPos(1,15),cout<<T/5;if(T/5>=Mk) Mk=T/5;SetPos(2,17),cout<<Mk;
    }
    Color(0);
}
void Start()
{
    Color(0);
    SetPos(2,5);cout<<"变  色  小  跳  龙";
    SetPos(3,14);cout<<"(1.5)";
    SetPos(5,9);cout<<"作者：胎神大大！";
    SetPos(7,6);cout<<"按 y 开始游戏!";
    A:char y=_getch();if(y!='y') goto A;
    else
    {
        system("cls");
        SetPos(1,2);cout<<"变色小跳龙游戏规则：";
        SetPos(3,1);cout<<"↑跳跃   不能踩在与自己",Color(1),cout<<"颜色不同",Color(0),cout<<"的块上";
        SetPos(4,1);cout<<"         开局与减血后会",Color(4),cout<<"无敌",Color(0),cout<<"一段时间";
        SetPos(5,1);cout<<"↓变色   无敌时会",Color(3),cout<<"自动变色",Color(0),cout<<"!";
        SetPos(7,2);cout<<"移动速度会越来越快，努力取得高分吧！";
        SetPos(8,2);Color(2),cout<<"按任意键开始游戏！";y=_getch();
    }
}
int main()
{
    system("mode con cols=42 lines=10");
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));
    Start(); system("cls");
    Re: Se=T=SS=xt=0;Tx=4;X=7;H=3;K=-5;
    memset(m,0,sizeof(m));
    for(int i=0;i<=15;i++) m[i]=-1;
    for(int i=1;i<=5;i++) Sheng();
    KK: Wu=100;system("cls");
    SetPos(1,12),Color(0),cout<<"Score:     ";
    SetPos(2,12),Color(0),cout<<"MaxScore:     ";
    SetPos(3,12),Color(0),cout<<"Life:           ";
    while(!(m[K+1]!=Se&&m[K+1]!=-1&&X==7&&Wu==0))
    {
        T++; if(X==7) xt=0;
        if(Wu>0) {Wu--;if(m[K+1]==0||m[K+1]==1) Se=m[K+1];}
        if(K==90||K==480||K==970||K==1460||K==2100) SetPos(5,10),Color(3),cout<<"Warning!! LEVEL UP!";
        if(K==110||K==520||K==1030||K==1540||K==2250) SetPos(5,10),cout<<"                   ";
        if(kbhit())
        {
            char g=_getch();
            if(g==72&&xt<2) {if(X==7) X--;Tx=4,xt++;}
            if(g==80&&Wu<=0) Se=(Se+1)%2,Map(2);
        }
        if(T%4==0) {if(Tx>0) {Tx--;if(X>=2) X--;}else if(X<7) X++;Map(1);}
        if(K<=100&&T%7==0) Sheng(),Map(2);
        if(K<500&&K>=100&&T%5==0) Sheng(),Map(2);
        if(K<1000&&K>=500&&T%4==0) Sheng(),Map(2);
        if(K<1500&&K>=1000&&T%3==0) Sheng(),Map(2);
        if(K<2200&&K>=1500&&T%2==0) Sheng(),Map(2);
        if(K>=2200) Sheng(),Map(2);
        Map(3);Sleep(10);
    }system("color 4F");
    if(H>0) {H--,Sleep(10),Se=(Se+1)%2,system("color 0F");goto KK;}
    SetPos(5,10),Sleep(1000),Color(0),system("pause");SetPos(5,10),cout<<"                      ";
    system("color 0F"); goto Re;
    return 0;
}
