#include<cstdio>
#include<iostream>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
#define Ye  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define W1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6f);
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define Bl  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x60);
int x,y,k,life=3,score=0;
void GotoXy(int x,int y){//x¡–,y–– 
    HANDLE hout;
    COORD coord;
    coord.X=x;
    coord.Y=y;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout,coord);
}
void clear(){
	GotoXy(0,0);
	for(int i=0;i<29;++i)cout<<"                                                                                                                                                   "<<endl;
	GotoXy(0,0);
}
void hide(){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
void yd(){
	char c=_getch();
	if(c=='w'||c=='W'||c=='H'){
		while(y!=5){
			GotoXy(x,y);
			cout<<"  ";
			y-=0.5;
			GotoXy(x,y);
			cout<<"°Ú";
			Sleep(60);
		}
		while(y!=13){
			GotoXy(x,y);
			cout<<"  ";
			y++;
			GotoXy(x,y);
			cout<<"°Ú";
			Sleep(50);
		}
	}k=1;
}
int main(){
	system("mode con cols=61 lines=16");	
	SetConsoleTitle(" ");
	hide();
	GotoXy(1,1);
	cout<<"Life:°ˆ°ˆ°ˆ\nscore:0"; 
	GotoXy(3,14);
	cout<<"°Ú";
	GotoXy(0,15);
	x=3,y=13;
	k=1;
	cout<<"-------------------------------------------------------------";
	while(1){
		if(kbhit()&&k){
			k=0;
			yd();
		}
		score++;
		GotoXy(1,1);
		cout<<"Life:°ˆ°ˆ°ˆ\nscore:"<<score; 
	}
}
