#include<cstdio>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int x[100]={3,7,11,15,19,23,27,31,35,39,43,47,51},y[100]={0,2,4,6,8,10,12,14,16,18,20,22,24},a[150][150];
int p1[500][500],p2[500][500],p1_i,p2_i;//p1��,p2�� 
const int _x=22,_y=5;
string s[2]={"����","����"}; 
#define Ye  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define W1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6f);
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define Bl  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x60);
void mapn(){
	const int _x=13;
	Ye;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6e);
	for(int j=0;j<_x;++j){
		cout<<"  ";
		for(int i=0;i<_x;++i)cout<<"��  ";
		cout<<endl<<"                                                      "<<endl;
	} 
	W;
	printf("**����**\n�������������������ã������ֵ�");
	B;
	printf("����");
}
void GotoXy(int x,int y){//x��,y�� 
    HANDLE hout;
    COORD coord;
    coord.X=x;
    coord.Y=y;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout,coord);
}
void win(string s){
	GotoXy(0,28);
	cout<<s<<"WIN!\n";
	W;
	system("pause");
	exit(0);
}
void clear(){
	GotoXy(0,0);
	for(int i=0;i<29;++i)cout<<"                                                                                                                                                   "<<endl;
	GotoXy(0,0);
}
void find(int x_,int y_,bool &f,bool &d){
	bool sss=1;
	for(int i=0;i<13;++i) 
		for(int j=0;j<13;++j) 
			if(a[y[i]][x[j]]!=0){
				sss=0;break;
			}
	if(x_>=0&&x_<=7&&y_==26&&!sss){
		W;
		GotoXy(8,26);
		cout<<"1.��/0.��";
		char c=getch();
		if(c=='1'){
			if(f==1){
				p2_i--;
				GotoXy(p2[p2_i][1],p2[p2_i][0]);
				a[p2[p2_i][0]][p2[p2_i][1]+1]=0;
				p2[p2_i][0]=p2[p2_i][1]=0;
			}else if(f==0){
				p1_i--;
				GotoXy(p1[p1_i][1],p1[p1_i][0]);
				a[p1[p1_i][0]][p1[p1_i][1]+1]=0;
				p1[p1_i][0]=p1[p1_i][1]=0;
			}SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6e);cout<<"��";
			d=1;
		}
		GotoXy(8,26);
		W;
		cout<<"                  ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6e);
		Sleep(100);
		return ;
	}
	bool t=0;
	int h=0,l=-1;
	for(int i=0;i<13;++i){
		if(x_==x[i]||x_==x[i]+1||x_==x[i]-1){
			h=x[i];
			break;
		}
	}
	for(int j=0;j<13;++j){
		if(y_==y[j]&&a[y[j]][h]==0){
			l=y[j];
			break;
		}
	}
	if(a[l][h]==0&&h!=0&&l!=-1){
		GotoXy(h-1,l);
		int js=0;
		if(f==1){
			p1[p1_i][0]=l;//y;
			p1[p1_i][1]=h-1;//x;
			p1_i++;
			a[l][h]=1;
			W1;
			cout<<"��";
			for(int i=0;i<13;++i){
				if(a[l][x[i]]==1)js++;
				else js=0;
				if(js==5)win("����");
			}
			js=0;
			for(int i=0;i<13;++i){
				if(a[y[i]][h]==1)js++;
				else js=0;
				if(js==5)win("����");
			}
			for(int i=0;i<13;i++)
				for(int j=0;j<13;j++){
					if((a[y[i]][x[j]]!=0&&a[y[i]][x[j]]==1&&a[y[i+1]][x[j+1]]==1&&a[y[i+2]][x[j+2]]==1&&a[y[i+3]][x[j+3]]==1&&a[y[i+4]][x[j+4]]==1)||(a[y[i]][x[j+4]]!=0&&a[y[i]][x[j+4]]==a[y[i+1]][x[j+3]]&&a[y[i]][x[j+4]]==a[y[i+2]][x[j+2]]&&a[y[i]][x[j+4]]==a[y[i+3]][x[j+1]]&&a[y[i]][x[j+4]]==a[y[i+4]][x[j]]))win("����");
				}
		}else{
			p2[p2_i][0]=l;//y;
			p2[p2_i][1]=h-1;//x;
			p2_i++;
			js=0;
			a[l][h]=2;
			Bl;
			cout<<"��";
			for(int i=0;i<13;++i){
				if(a[l][x[i]]==2)js++;
				else js=0;
				if(js==5)win("����");
			}
			js=0;
			for(int i=0;i<13;++i){
				if(js==5)win("����");
				if(a[y[i]][h]==2)js++;
				else js=0;
			}
			for(int i=0;i<13;i++)
				for(int j=0;j<13;j++){
					if((a[y[i]][x[j]]!=0&&a[y[i]][x[j]]==2&&a[y[i+1]][x[j+1]]==2&&a[y[i+2]][x[j+2]]==2&&a[y[i+3]][x[j+3]]==2&&a[y[i+4]][x[j+4]]==2)||(a[y[i]][x[j+4]]!=0&&a[y[i]][x[j+4]]==a[y[i+1]][x[j+3]]&&a[y[i]][x[j+4]]==a[y[i+2]][x[j+2]]&&a[y[i]][x[j+4]]==a[y[i+3]][x[j+1]]&&a[y[i]][x[j+4]]==a[y[i+4]][x[j]]))win("����");
				}
		}d=1;
	}else d=0;
}
void hide(){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
void game(){
	W;
	cout<<"     ********";
	B;
	cout<<"Gobang";
	W;
	cout<<"**********";
	cout<<endl<<"            ��ʼ��Ϸ"<<endl<<"            �˳���Ϸ"<<endl<<"            �������������(�ؿ�)"<<endl<<endl;
	Ye;
	cout<<"   *********���ȵ�������ģʽ*********";
}
void zz(){
	cout<<"����:Accteped\nCSDN:https://blog.csdn.net/Accteped?spm=1000.2115.3001.5343\nQQ:����\n���:Accteped,https://www.luogu.com.cn/user/368851\n�������ߵ�4����Ϸ";
	cout<<endl<<"\n\n����:\n�����������\n�����л����ʶ,���������1��0\n�뽫���ڵ���,�����ɲ���ģʽ,���巽���뿴\nhttps://blog.csdn.net/Accteped/article/details/113341770\nHave a good time!";
	getch();
	clear();
}
int main(){
	SetConsoleTitle("Gobang/������");
	hide();
	game();
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
				B;
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
				B;
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
		if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=31&&mouseRec.Event.MouseEvent.dwMousePosition.Y==3){
			if(!f3){
				f3=1;
				GotoXy(12,3);
				B;
				cout<<"�������������(�ؿ�)";
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
			cout<<"�������������(�ؿ�)";
		}
	}
	clear();
	mapn();
	bool b=0;
	while(1){
		Sleep(110); 
		ReadConsoleInput(hIn, &mouseRec, 1, &res);
		if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
			int xs=mouseRec.Event.MouseEvent.dwMousePosition.X,ys=mouseRec.Event.MouseEvent.dwMousePosition.Y;
			bool d=0;
			find(xs,ys,b,d);
			if(d==1){
				if(b==0){
					b=1;
					W;
				}
				else{
					b=0;
					B;
				}
				GotoXy(34,27);
				cout<<s[b]; 
			}
			bool sss=1;
			for(int i=0;i<13;++i) 
				for(int j=0;j<13;++j) 
					if(a[y[i]][x[j]]==0){
						sss=0;break;
					}
			if(sss){
				clear();
				cout<<"�þ�Ϊ�;�\n";
				system("pause"); 
				exit(0);
			}
		}
	}
}

