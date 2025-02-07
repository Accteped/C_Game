#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define Ye  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN)
#define Ye1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e)
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07)
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x01)
#define G  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x02)
#define G1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0A)
#define R  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04)
#define P  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x05)
#define P1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0D)
#define B1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x08)
#define W1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F)
#define R1  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0C)
using namespace std;
int score,a[10][10],x[5]={0,5,10,15},y[5]={1,3,5,7},b[10][10],maxn;
ofstream fout;
bool left();
bool right();
bool up();
bool down();
void rand_num();
void draw_map();
int check();
void hide(){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
bool left(){
	int t=0,t1=0,f=0;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			int s=j;
			while(s-1>=1&&a[i][s-1]==0){
				a[i][s-1]=a[i][s];
				a[i][s]=0;                     
				f=1;
				s--;
			}
		}
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			if(a[i][j]==a[i][j-1]&&!b[i][j]&&!b[i][j-1]){
				a[i][j-1]+=a[i][j];
				b[i][j-1]=1;
				score+=a[i][j-1];
				a[i][j]=0;
				f=1;
				for(int k=3;k>=j;--k){
					swap(a[i][k+1],a[i][k]);
				}
			}
		}
	return f;
}
bool right(){
	int t=0,t1=0,f=0;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			int s=j;
			while(s+1<=4&&a[i][s+1]==0){
				a[i][s+1]=a[i][s];
				a[i][s]=0;                     
				f=1;
				s++;
			}
		}
	for(int i=1;i<=4;++i)
		for(int j=3;j>=1;--j){
			if(a[i][j]==0)continue;
			if(a[i][j]==a[i][j+1]&&!b[i][j]&&!b[i][j+1]){
				a[i][j+1]+=a[i][j];
				b[i][j+1]=1;
				score+=a[i][j+1];
				a[i][j]=0;
				f=1;
				for(int k=1;k<j;++k){
					swap(a[i][k+1],a[i][k]);
				}
			}
		}
	return f;
}
bool down(){
	int f=0;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			int s=i;
			while(s+1<=4&&a[s+1][j]==0){
				a[s+1][j]=a[s][j];
				a[s][j]=0;                     
				f=1;
				s++;
			}
		}
	for(int i=3;i>=0;--i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			if(a[i][j]==a[i+1][j]&&!b[i][j]&&!b[i+1][j]){
				b[i+1][j]=1;
				a[i+1][j]+=a[i][j];
				score+=a[i+1][j];
				a[i][j]=0;
				f=1;
				for(int k=2;k<=i;++k){
					swap(a[k-1][j],a[k][j]);
				}
			}
		}
	return f;
}
bool up(){
	int f=0;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			int s=i;
			while(s-1>=1&&a[s-1][j]==0){
				a[s-1][j]=a[s][j];
				a[s][j]=0;                     
				f=1;
				s--;
			}
		}
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0)continue;
			if(a[i][j]==a[i-1][j]&&!b[i][j]&&!b[i-1][j]){
				b[i-1][j]=1;
				a[i-1][j]+=a[i][j];
				score+=a[i-1][j];
				a[i][j]=0;
				f=1;
				for(int k=4;k>i;--k){
					swap(a[k-1][j],a[k][j]);
				}
			}
		}
	return f;
}
int check(){
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==2048){
				return 2;
			}
		}
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==0){
				return 1;
			}
		}
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(a[i][j]==a[i-1][j]||a[i][j]==a[i+1][j]||a[i][j]==a[i][j-1]||a[i][j]==a[i][j+1]){
				return 1;
			}
		}
	return 0;
}
void rand_num(){
	cs:
	int y1=rand()%4+1,x1=rand()%4+1;
	if(a[y1][x1])goto cs;
	else{
		a[y1][x1]=2;
	}
}
void draw_map(){
	if(maxn<score){
		fout.open("a.txt"); 
		fout<<score;
		fout.close();
	}
	maxn=max(maxn,score);
	cout<<"Score:"<<score<<"   Best Score:"<<maxn<<endl;
	for(int i=1;i<=4 ;++i){
		for(int j=1;j<=4;++j){
			if(a[i][j]==0){
				cout<<setw(6)<<' '; 	
				continue;
			}
			if(a[i][j]==2)Ye1;
			if(a[i][j]==4)G;
			if(a[i][j]==8)B;
			if(a[i][j]==16)P1;
			if(a[i][j]==32)B1;
			if(a[i][j]==64)R1;
			if(a[i][j]==128)Ye;
			if(a[i][j]==256)R;
			if(a[i][j]==512)G1;
			if(a[i][j]==1024)P;
			if(a[i][j]==2048)W1;
			cout<<setw(6)<<a[i][j];W;
		}
		cout<<endl<<endl;
	}
}
int main(){
	system("title 2048");
	cout<<"W A S D或上下左右操作\n";
	system("pause");
	system("cls");
	freopen("a.txt","r",stdin);
	cin>>maxn;
	fclose(stdin);
	srand(time(0));
	hide();
	rand_num();
	draw_map();
	while(1){
		memset(b,0,sizeof(b));
		cc:
		char c=getch();
		if(c=='w'||c=='W'||(int)c==72){
			if(!up())goto cc;
			up();
		}
		else if(c=='s'||c=='S'||(int)c==80){
			if(!down())goto cc;
			down();
		}
		else if(c=='a'||c=='A'||(int)c==75){
			if(!left())goto cc;
			left();
		}
		else if(c=='d'||c=='D'||(int)c==77){
			if(!right())goto cc;
			right();
		}
		else continue;
		system("cls");
		draw_map(); 
		rand_num();
		system("cls");
		draw_map();
		if(check()==0){
			MessageBox(NULL,TEXT("Game Over!"),TEXT("你输了"),MB_OK);
		}
		if(check()==2){
			MessageBox(NULL,TEXT("你赢了"),TEXT("恭喜"),MB_OK);
		}
//		fout<<maxn;
	}
	return 0;
}
