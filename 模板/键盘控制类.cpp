#include<cstdio>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
#define Ye  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define W1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6f);
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define Bl  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x60);
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
int main(){
	SetConsoleTitle("");
	hide();
}
