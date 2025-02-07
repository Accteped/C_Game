#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define R  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
using namespace std;
int piece1[100][2]={
	0,0,//車
	0,1,//馬 
	0,2,//相 
	0,3,//仕 
	0,4,//帅 
	0,5,//仕  
	0,6,//相
	0,7,//馬 
	0,8,//車
	2,1,//砲
	2,7,//砲
	3,0,//兵 
	3,2,//兵 
	3,4,//兵 
	3,6,//兵 
	3,8,//兵 
};
string s[100]{
	"車",
	"馬",
	"相",
	"仕",
	"帅",
	"仕",
	"相",
	"馬",
	"車",
	"砲",
	"砲",
	"兵",
	"兵",
	"兵",
	"兵",
	"兵",
};
int piece2[100][2]={
	9,0,//车
	9,1,//马 
	9,2,//象
	9,3,//士 
	9,4,//将 
	9,5,//士  
	9,6,//象
	9,7,//马 
	9,8,//车
	7,1,//炮
	7,7,//炮
	6,0,//卒 
	6,2,//卒 
	6,4,//卒 
	6,6,//卒 
	6,8,//卒 
};
string s1[100]{
	"车",
	"马",
	"象",
	"士",
	"将",
	"士",
	"象",
	"马",
	"车",
	"炮",
	"炮",
	"卒",
	"卒",
	"卒",
	"卒",
	"卒",
};
void mapn(){
	const int _x=13;W; 
	for(int j=0;j<5;++j){
		cout<<"  ";
		for(int i=0;i<9;++i){
			bool f=0;
			for(int k=0;k<16;++k){
				if(piece1[k][0]==j&&piece1[k][1]==i){
					cout<<s[k]<<"  ";
					f=1;
					break;
				}
			}
			if(!f)cout<<"╋  ";
		}
		if(j!=4)cout<<endl<<endl;
	}cout<<"\n ------------------------------------\n"; 
	    cout<<"         楚河       汉界            \n";
	cout<<" ------------------------------------\n";
	for(int j=5;j<10;++j){
		cout<<"  ";
		for(int i=0;i<9;++i){
			bool f=0;
			for(int k=0;k<16;++k){
				if(piece2[k][0]==j&&piece2[k][1]==i){
					cout<<s1[k]<<"  ";
					f=1;
					break;
				}
			}
			if(!f)cout<<"╋  ";
		} 
		if(j!=9)cout<<endl<<endl;
	}
}
void game(){
	W;
	cout<<"     ********Chinese chess**********";
	cout<<endl<<"            开始游戏"<<endl<<"            退出游戏"<<endl<<"            关于作者与帮助";
}
void hide(){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
void GotoXy(int x,int y){//x列,y行 
    HANDLE hout;
    COORD coord;
    coord.X=x;
    coord.Y=y;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout,coord);
}
void clear(){
	GotoXy(0,0);
	for(int i=0;i<90;++i)cout<<"                                                                                                                                                   "<<endl;
	GotoXy(0,0);
}
void zz(){
	cout<<"作者:Accteped\nCSDN:https://blog.csdn.net/Accteped?spm=1000.2115.3001.5343\nQQ:暂无\n洛谷:Accteped,https://www.luogu.com.cn/user/368851\n这是作者第5个游戏";
	cout<<endl<<"\n\n帮助:\n用鼠标点击下棋\n下面有悔棋标识,点击后输入1或0\nHave a good time!";
	getch();
	clear();
}
int main(){
	SetConsoleTitle("Chinese chess/象棋");
	game();
	hide();
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD mouseRec;
	DWORD res;
	bool f1=0,f2=0,f3=0;
	while(1){
		ReadConsoleInput(hIn, &mouseRec, 1, &res);
		if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=19&&mouseRec.Event.MouseEvent.dwMousePosition.Y==1){
			if(!f1){
				f1=1;
				GotoXy(12,1);
				R;
				cout<<"开始游戏";
			}
			if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)break;
		}else if(f1){
			f1=0;
			GotoXy(12,1);
			W;
			cout<<"开始游戏";
		}
		if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=19&&mouseRec.Event.MouseEvent.dwMousePosition.Y==2){
			if(!f2){
				f2=1;
				GotoXy(12,2);
				R;
				cout<<"退出游戏";
			}if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
				clear();
				W;
				cout<<"确定吗 1.是 0.否";
				char cc=getch();
				if(cc=='1'){
					clear();
					cout<<"退出成功\n";
					system("pause");
					exit(0);
				}
				clear();
				game();    
			}
		}else if(f2){
			f2=0;
			GotoXy(12,2);
			W;
			cout<<"退出游戏";
		}
		if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=25&&mouseRec.Event.MouseEvent.dwMousePosition.Y==3){
			if(!f3){
				f3=1;
				GotoXy(12,3);
				R;
				cout<<"关于作者与帮助";
			}if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
				clear();
				W;
				zz();
				game();
			}
		}else if(f3){
			f3=0;
			GotoXy(12,3);
			W;
			cout<<"关于作者与帮助";
		}
	}clear();
	mapn();
}
