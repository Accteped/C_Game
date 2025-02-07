#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define R  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
using namespace std;
int piece1[100][2]={
	0,0,//܇
	0,1,//�R 
	0,2,//�� 
	0,3,//�� 
	0,4,//˧ 
	0,5,//��  
	0,6,//��
	0,7,//�R 
	0,8,//܇
	2,1,//�h
	2,7,//�h
	3,0,//�� 
	3,2,//�� 
	3,4,//�� 
	3,6,//�� 
	3,8,//�� 
};
string s[100]{
	"܇",
	"�R",
	"��",
	"��",
	"˧",
	"��",
	"��",
	"�R",
	"܇",
	"�h",
	"�h",
	"��",
	"��",
	"��",
	"��",
	"��",
};
int piece2[100][2]={
	9,0,//��
	9,1,//�� 
	9,2,//��
	9,3,//ʿ 
	9,4,//�� 
	9,5,//ʿ  
	9,6,//��
	9,7,//�� 
	9,8,//��
	7,1,//��
	7,7,//��
	6,0,//�� 
	6,2,//�� 
	6,4,//�� 
	6,6,//�� 
	6,8,//�� 
};
string s1[100]{
	"��",
	"��",
	"��",
	"ʿ",
	"��",
	"ʿ",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
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
			if(!f)cout<<"��  ";
		}
		if(j!=4)cout<<endl<<endl;
	}cout<<"\n ------------------------------------\n"; 
	    cout<<"         ����       ����            \n";
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
			if(!f)cout<<"��  ";
		} 
		if(j!=9)cout<<endl<<endl;
	}
}
void game(){
	W;
	cout<<"     ********Chinese chess**********";
	cout<<endl<<"            ��ʼ��Ϸ"<<endl<<"            �˳���Ϸ"<<endl<<"            �������������";
}
void hide(){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
void GotoXy(int x,int y){//x��,y�� 
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
	cout<<"����:Accteped\nCSDN:https://blog.csdn.net/Accteped?spm=1000.2115.3001.5343\nQQ:����\n���:Accteped,https://www.luogu.com.cn/user/368851\n�������ߵ�5����Ϸ";
	cout<<endl<<"\n\n����:\n�����������\n�����л����ʶ,���������1��0\nHave a good time!";
	getch();
	clear();
}
int main(){
	SetConsoleTitle("Chinese chess/����");
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
				cout<<"��ʼ��Ϸ";
			}
			if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)break;
		}else if(f1){
			f1=0;
			GotoXy(12,1);
			W;
			cout<<"��ʼ��Ϸ";
		}
		if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=19&&mouseRec.Event.MouseEvent.dwMousePosition.Y==2){
			if(!f2){
				f2=1;
				GotoXy(12,2);
				R;
				cout<<"�˳���Ϸ";
			}if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
				clear();
				W;
				cout<<"ȷ���� 1.�� 0.��";
				char cc=getch();
				if(cc=='1'){
					clear();
					cout<<"�˳��ɹ�\n";
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
			cout<<"�˳���Ϸ";
		}
		if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=25&&mouseRec.Event.MouseEvent.dwMousePosition.Y==3){
			if(!f3){
				f3=1;
				GotoXy(12,3);
				R;
				cout<<"�������������";
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
			cout<<"�������������";
		}
	}clear();
	mapn();
}
