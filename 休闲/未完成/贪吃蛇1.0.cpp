#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
char xin=' ';
long long len=4,sd;
char head='d',ss;
char snk[101][101];
string s="欢迎来到贪吃蛇游戏1.0\n作者:何祥鑫,李岸霖\n洛谷名:Accteped,卑微LAG\nQQ:无,2135857609\n如有不足,多多指教\n";
void sc(string s,int m){
	int n=s.size();
	for(int i=0;i<n;++i){
		cout<<s[i];
		Sleep(m);
	}
}
void zt(){
	system("pause>nul");
} 

void qp(){
	system("cls");
}
void jd(){
	qp();
	string ss="----";
	cout<<"提示:wasd控制上左下右"<<endl;
	sc(ss,1000);
	qp();
	cout<<"游戏即将开始,请稍后"<<endl;
	sc(ss,1000);
	qp();
}
void start(){
	char c=' ';
	qp();
	sc("选则难度:\n1.简单\n2.困难\n其他功能还未开发\n",100);
	c=getch();
	switch(c){
		case '1':jd();break;sd=1;
		case '2':jd();break;sd=4;
		default:cout<<"输入错误!";Sleep(1000);start(); break;
	}
}
void snackRuntail(){
	switch(ss){
		case 'a':
			head='a';
			break;
		case 's':
			head='s';
			break;
		case 'd':
			head='d';
			break;
		case 'w':
			head='w';
			break;
		default:break;
	}
}
void snackRun(){
	while(1){
		snackRuntail();
	}
}
void snakmap(){
	for(int i=1;i<=50;++i){
		cout<<"- ";snk[1][i]='-';
	}
	cout<<endl;
	for(int k=2;k<=49;++k){
		cout<<'|';
		snk[k][1]='|';
		for(int j=2;j<=98;++j)cout<<' ';
		cout<<'|';
		snk[k][50]='|';
		cout<<endl;
	}
	for(int i=1;i<=50;++i){
		cout<<"- ";snk[50][i]='-';
	}
	
}
int main(){
	srand(time(0));
	system("mode con cols=101 lines=55");
	sc(s,100);
	cout<<"按k开始";
	a:xin=_getch();if(xin!='k')goto a;
	start();	
	qp();
	
	//绘制地图 
	snakmap();
	
	//隐藏控制台光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
    
}
