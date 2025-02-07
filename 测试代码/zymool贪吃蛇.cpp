#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<thread>
using namespace std;


string DifficultyTitle[5]={"简单","普通","困难","炒鸡困难","魔王"};
string DirectionTitle[4]={"上","左","下","右"}; 
string QspeedTitle[2]={"开启","关闭"}; 
double DifficultyDefault[5][2]={{30,0.8},{20,1.0},{15,1.2},{12,1.5},{9,2.0}};
int DirectionDefault[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char map[110][110];
int map_type[110][110];
int map_size;
int snake_len;
int direction;//0:上 1:左 2:下 3:右 
double speed;
bool died;
bool DeBug_Mode=false;
bool pause_game_type=false;
int qspeed;
bool qspeed_open;
char char_ls;
long long int_ls;
double dou_ls;
string str_ls;
int x,y;
int dx,dy;
int foodx,foody;
int difficulty;
long long score;


void init();
void lobby();
void normal_exit();
void game_init();
void difficulty_set();
void custom();
void game();
void game_display();
void thread_getinput();
void del_lastsnake(int num);
void create_food();
void helper();
int main(){
	init();
	lobby();
	return 0;
}
void init(){
	SYSTEMTIME systemtime;
    GetLocalTime(&systemtime);
    srand(systemtime.wMinute*systemtime.wSecond*systemtime.wMilliseconds);
    SetConsoleTitle("贪吃蛇 Copyright@zymooll 2020-2099");
	if(DeBug_Mode)printf("程序初始化完毕！\n");
}
void lobby(){
	system("cls"); 
	printf("欢迎来到贪吃蛇游戏！\n1:开始\n2:游戏帮助\n0:退出\n");
	char_ls=getch();
	printf("%c\n",char_ls);
	if(char_ls=='2')helper();
	else if(char_ls) game_init();
	else normal_exit();
}
void normal_exit(){
	
	if(DeBug_Mode)printf("程序退出准备完毕！\n");
	exit(0);
}
void game_init(){
	for(int i=0;i<map_size;i++){
		for(int j=0;j<map_size;j++){
			map_type[i][j]=0;
		}
	}
	score=0;
	snake_len=3;
	qspeed=1000;
	qspeed_open=false;
	memset(map,'~',sizeof(map));
	if(DeBug_Mode)printf("游戏开始前初始化完毕！\n");
	difficulty_set();
}
void difficulty_set(){
	system("cls"); 
	printf("请选定难度\n1:简单(地图大小为30*30,速度为0.8x)\n2:普通(地图大小为20*20,速度为1.0x)\n3:困难(地图大小为15*15,速度为1.2x)\n4:炒鸡困难(地图大小为12*12,速度为1.5x)\n5:魔王(地图大小为9*9,速度为2.0x)\n6:自定义(不计入排行榜)\n9:回到主菜单\n0:退出\n");
	char_ls=getch();
	difficulty=char_ls-'0';
	printf("%c\n",char_ls);
	if(char_ls>='1'&&char_ls<='5'){
		map_size=DifficultyDefault[char_ls-'0'-1][0];
		speed=floor(1/DifficultyDefault[char_ls-'0'-1][1]);
		if(DeBug_Mode)printf("难度设定完毕！\n");
		game();
	}
	if(char_ls=='6')custom();
	if(char_ls=='0')normal_exit();
	else lobby();
}
void custom(){
	do{
		printf("请输入地图大小(5-100)\n");
		cin>>int_ls;
	}while(int_ls<5||int_ls>100);
	map_size=int_ls;
	do{
		printf("请输入速度(0.5-3.0)\n");
		cin>>dou_ls;
	}while(dou_ls<0.5||dou_ls>3.0);
	speed=floor(1/dou_ls);
	if(DeBug_Mode)printf("自定义难度设定完毕！\n");
	game();
}
void game(){
	system("cls");
	thread getinput(thread_getinput);
	getinput.detach();
	died=false;
	create_food();
	snake_len=3;
	x=1+rand()%((map_size-1)-1);
	y=1+rand()%((map_size-1)-1);
	for(long long i=1;!died;i++){
		if(map[x][y]=='*'){
			create_food();
			snake_len++;
			score++;
		}
		if(map[x][y]=='@')died=true;
		map[x][y]='#';
		map_type[x][y]=i;
		del_lastsnake(i);
		game_display();
		dx=x+DirectionDefault[direction][0];
		dy=y+DirectionDefault[direction][1];
		if(dx==map_size)dx=0;
		if(dy==map_size)dy=0;
		if(dx==-1)dx=map_size-1;
		if(dy==-1)dy=map_size-1;
		map[x][y]='@';
		x=dx;
		y=dy;
		if(pause_game_type)printf("已暂停\n");
		while(pause_game_type)printf("");
		Sleep(floor(speed*qspeed));
	}
	system("cls");
	printf("游戏结束！\n得分为:%06d\n按任意键回到主菜单！\n",score);
	Sleep(50);
	getch(); 
	system("cls");
}
void game_display(){
	system("cls");
	for(int i=0;i<map_size;i++){
		for(int j=0;j<map_size;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	if(qspeed==1000)str_ls="1.0x";
	if(qspeed==500)str_ls="2.0x";
	if(qspeed==250)str_ls="4.0x";
	if(qspeed==125)str_ls="8.0x";
	printf("%s\n%s\n%s\n%s\n",("你当前的模式是:"+DifficultyTitle[difficulty-1]+"模式").c_str(),("你当前的分数是:"+to_string(score)+"分").c_str(),("你当前的方向是:"+DirectionTitle[direction]+"方向").c_str(),("你当前的快速模式开启状态是:"+QspeedTitle[qspeed==1000?1:0]+"状态("+str_ls+")").c_str());
}
void thread_getinput(){
	while(!died){
		char_ls=getch();
		//printf("%c",char_ls);
		if(char_ls=='w'||char_ls=='W'){
			if(direction!=2)direction=0;
		}
		if(char_ls=='a'||char_ls=='A'){
			if(direction!=3)direction=1;
		}
		if(char_ls=='s'||char_ls=='S'){
			if(direction!=0)direction=2;
		}
		if(char_ls=='d'||char_ls=='D'){
			if(direction!=1)direction=3;
		}
		if(char_ls==27){
			if(pause_game_type)pause_game_type=false;
			else pause_game_type=true;
			//Sleep(50);
		}
		if(char_ls==' '){
			if(qspeed_open){
				qspeed=1000;
				qspeed_open=false;
			}
			else{
				qspeed_open=true;
				qspeed/=2;
			}
		}
		if(char_ls=='+'){
			if(qspeed>125&&qspeed_open)qspeed/=2;
		}
		if(char_ls=='-'){
			if(qspeed<500&&qspeed_open)qspeed*=2;
		}
	} 
}
void del_lastsnake(int num){
	int_ls=num-snake_len;
	for(int i=0;i<map_size;i++){
		for(int j=0;j<map_size;j++){
			if(map_type[i][j]<=int_ls&&map_type[i][j]!=0){
				map_type[i][j]=0;
				map[i][j]='~';
			}
		}
	}
}
void create_food(){
	do{
		foodx=rand()%(map_size-1);
		foody=rand()%(map_size-1);
	}while(map[foodx][foody]=='@');
	map[foodx][foody]='*';
}
void helper(){
	system("cls");
	printf("首先非常感谢你游玩本游戏!(按任意键继续)\n");
	getch();
	printf("按WASD控制上下左右(按任意键继续)\n");
	getch();
	printf("按空格开关加速模式(按任意键继续)\n");
	getch();
	printf("按+-控制加速模式速度(按任意键继续)\n");
	getch();
	printf("按Esc可暂停游戏(按任意键继续)\n");
	getch();
	printf("That is all!开始游玩吧!(按任意键继续)\n");
	getch();
	lobby();
}
#pragma GCC pop_options
