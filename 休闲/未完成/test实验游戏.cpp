#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<thread>
using namespace std;
int x=10,y=4,h=4,l=5,fs,times=300;
void GotoXy(int x,int y){//x列,y行 
    HANDLE hout;
    COORD coord;
    coord.X=x;
    coord.Y=y;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout,coord);
}
void timen(){
	int i=0;
	while(1){
		GotoXy(0,22);
		cout<<"  ";
		GotoXy(0,22);
		cout<<i;
		Sleep(1000);
		i++;
	}
}
int c[20][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
void mapn(){
	for(int i=0;i<20;++i){
		for(int j=0;j<20;++j){
			switch(c[i][j]){
				case 0:cout<<'.'<<' ';break;
				case 3:cout<<'$'<<' ';break;
				case 1:cout<<"@ ";break;
			}
		}cout<<endl;
	}cout<<"分数:"<<fs;
}
void SetOut(int i,int j){
	COORD pos={i,j};
	HANDLE t=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(t,pos);
}
void hide(){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
void food(){
	int gs=rand()%5+3;
	for(int i=0;i<gs;++i){
		int fx=rand()%20,fy=rand()%20;
		if(c[fx][fy]==1||c[fx][fy]==3)fx+=(1+rand()%6);
		c[fx][fy]=3;
	}
}
void yd(){
	char d=getch();
	switch(d){
		case 'w':
			if(y==0)break; 
			if(c[h-1][l]==3){
				fs++;
				SetOut(5,20);
				cout<<fs;
				c[h-1][l]=0;
			}h--;	
			SetOut(x,y);
			cout<<".";
			y-=1;
			SetOut(x,y);
			cout<<'@';
			break;
		case 'a':
			if(x<2)break;
			if(c[h][l-1]==3){
				fs++;
				SetOut(5,20);
				cout<<fs;
				c[h][l-1]=0;
			}SetOut(x,y);
			l--;
			cout<<".";
			x-=2;
			SetOut(x,y);
			cout<<'@';
			break;
			break;
		case 's':
			if(y==19)break;
			if(c[h+1][l]==3){
				SetOut(5,20);
				fs++;
				cout<<fs;
				c[h+1][l]=0;
			}h++;SetOut(x,y);
			cout<<".";
			y+=1;
			SetOut(x,y);
			cout<<'@';
			break;
		case 'd':
			if(x>36)break;
			if(c[h][l+1]==3){
				fs++;
				SetOut(5,20);
				cout<<fs;
				c[h][l+1]=0;
			}l++;
			SetOut(x,y);
			cout<<".";
			x+=2;
			SetOut(x,y);
			cout<<'@';
			break;
	}
	
}
void qp(){
	system("cls");
}
int main(){
	
	SetFileAttributes("1.txt",FILE_ATTRIBUTE_NORMAL); 
	srand(time(0));
	hide();food();
	mapn();
	SetOut(0,21);
	cout<<"x:"<<x<<" y:"<<y;thread t(timen);
	while(1){
		if(kbhit()){
			yd();
			SetOut(0,21);
			cout<<"                                ";
			SetOut(0,21);
			cout<<"x:"<<x<<" y:"<<y;
		}
		
	}
}

