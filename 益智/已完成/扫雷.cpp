#include<iostream>
#include<fstream>
#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<thread>
using namespace std;
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define R  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
//9*9(初级)，16*16(中级)，16*30(高级) 初级为10个，中du级为40个，高级为99个
int maxn=999999999,life,time1,time4,mapn[600][600]={},f1[400][400],f[600][600]={},h,l,x[100]={12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72},y[100]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int nd,le,tle,flagg;
void GotoXy(int,int);
void time2(){
    while(1){
        W;
        time4=time1;
        if(flagg==1){
//          GotoXy(5,h+1);
//          cout<<"                                        ";
            break;  
        }
        if(flagg==2){
            GotoXy(5,h+1);
            cout<<"                                        ";
            break;  
        }
        Sleep(1000);
        time1++;
        GotoXy(5,h+1);
        cout<<"                           ";
        GotoXy(5,h+1);
        cout<<time1;
        if(flagg==1){
//          GotoXy(5,h+1);
//          cout<<"                                        ";
            break;  
        }
        if(flagg==2){
            GotoXy(5,h+1);
            cout<<"                                        ";
            break;  
        }
    }
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
    for(int i=0;i<100;++i)cout<<"                                                                                                                                                                                                                                                                                                                                                                          "<<endl;
    GotoXy(0,0);
}
void hide(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(handle, &CursorInfo);
}
int check(int x,int y){
    int yd[10][2]={{0,-1},{0,1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}},gs=0;//行，列 
    for(int i=0;i<8;++i){
        if(x+yd[i][0]>=0&&x+yd[i][0]<=h&&y+yd[i][1]>=0&&y+yd[i][1]<=l){
            if(mapn[x+yd[i][0]][y+yd[i][1]]==-1){
                gs++;
            }
        }
    }return gs;
}
void init(int nd){
    int t;
    ifstream fin,fin1,fin2;
    if(nd==1){
		fin.open("初级.txt");
        fin>>maxn;
        h=l=9;
        le=tle=10;
        t=71;
        life=1;
    }
    if(nd==2){
		fin1.open("中级.txt");
        fin1>>maxn;
        life=2;
        h=l=16;
        le=tle=40;
        t=216;
    }
    if(nd==3){
		fin2.open("高级.txt");
        fin2>>maxn;
        life=3;
        h=16;l=30;
        le=tle=99;
        t=381;
    }
    if(maxn<=0){
        maxn=999999999;
    }
    srand((unsigned)time(NULL));
    for(int j=0;j<le;j++){ 
        Lab2:
        int a=rand()%h,b=rand()%l;
        if(mapn[a][b]==0)mapn[a][b]=-1;
        else goto Lab2;
    }
    for(int i=0;i<h;++i){
        for(int j=0;j<l;++j){
            if(mapn[i][j]!=0)continue;
            mapn[i][j]=check(i,j);
        }
    }
}
void num(int i,int j,int b){//行,列 
    int yd[10][2]={{0,-1},{0,1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};//行，列
    if(mapn[i][j]==0){
//      if(f1[i][j]==-1)return;
        cout<<"  ";
        for(int k=0;k<8;++k){
//          if(f1[i+yd[k][0]][j+yd[k][1]]==-1)return;
            if(i+yd[k][0]>=0&&i+yd[k][0]<h&&j+yd[k][1]>=0&&j+yd[k][1]<l&&f1[i+yd[k][0]][j+yd[k][1]]!=-1&&!f[i+yd[k][0]][j+yd[k][1]]){
                if(mapn[i+yd[k][0]][j+yd[k][1]]!=-1){
                    f[i+yd[k][0]][j+yd[k][1]]=1;
                    if(mapn[i+yd[k][0]][j+yd[k][1]]==0){
                        f1[i+yd[k][0]][j+yd[k][1]]=-1;
                        GotoXy(x[j+yd[k][1]],y[i+yd[k][0]]);
                        cout<<"  ";
                        num(i+yd[k][0],j+yd[k][1],b+1);
                    }else if(mapn[i+yd[k][0]][j+yd[k][1]]!=-1){
                        f1[i+yd[k][0]][j+yd[k][1]]=-1;
                        GotoXy(x[j+yd[k][1]],y[i+yd[k][0]]);
                        cout<<mapn[i+yd[k][0]][j+yd[k][1]]<<' ';
                    }
                }
            }
        }
    }else{
        f[i][j]=1;
        f1[i][j]=-1;
        cout<<mapn[i][j]<<' ';
    }
}
void find(int a,int b){
    for(int i=0;i<l;++i){
        for(int j=0;j<h;++j){
            if((a==x[i]||a==x[i]+1)&&b==y[j]&&f1[j][i]!=1){
                GotoXy(x[i],y[j]);
                if(mapn[j][i]==-1){
                    R;
                    GotoXy(x[i],y[j]);
                    cout<<"  ";
                    Sleep(100);
                    GotoXy(x[i],y[j]);
                    cout<<"■";
                    Sleep(100);
                    GotoXy(x[i],y[j]);
                    cout<<"  ";
                    Sleep(100);
                    GotoXy(x[i],y[j]);
                    cout<<"■";
                    Sleep(100);
                    W;GotoXy(x[i],y[j]);
                    cout<<"■";
                    life--;
                    GotoXy(5,h+2);
                    cout<"                   ";
                    cout<<life;
                    if(life>0)continue;
                    clear();
                    W;
                    GotoXy(0,0);
                    for(int i=0;i<h;++i){
                        for(int j=0;j<l;++j){
                            switch(mapn[i][j]){
                                case 0:cout<<"0 ";break;
                                case -1:R;cout<<"* ";W;break;
                                default:
                                cout<<mapn[i][j]<<' ';
                            }
                        }cout<<endl;
                    }flagg=1;
                    cout<<"GAME OVER\n";
                    cout<<"用时:"<<time4<<'s';
                    getch();
                    exit(0);
                }else{
                    num(j,i,0);
                }
            }
        }
    }
}
void draw(){
    W;
    cout<<"mine clearance/扫雷 控制台版"<<endl;
    cout<<"         ********\n         *1.初级*\n         *2.中级*\n         *3.高级*\n         ********";
    cr:
    char c=getch();
    if(c!='1'&&c!='2'&&c!='3')goto cr;
    clear();
    init(c-'0');
    for(int i=0;i<h;++i){
        cout<<"            "; 
        for(int j=0;j<l;++j){
            cout<<"■";
        }cout<<endl;
    }cout<<"剩余雷(玩家,非真正的):"<<le<<endl<<"时间:"<<time1<<endl<<"生命:"<<life<<endl;
//  for(int i=0;i<h;++i){
////        cout<<"            "; 
//      for(int j=0;j<l;++j){
//          W;
//          switch(mapn[i][j]){
//              case -1:R;cout<<"* ";break;
//              case 0:W;cout<<"  ";break;
//              default: cout<<mapn[i][j]<<' ';
//          }
//      }cout<<endl;
//  }
}
void game(){
    W;
    cout<<"     ********mine clearance/扫雷 控制台版**********";
    cout<<endl<<"            开始游戏"<<endl<<"            退出游戏"<<endl<<"            关于作者与帮助(必看)";
}
void zz(){
    cout<<"作者:Accteped\nCSDN:https://blog.csdn.net/Accteped?spm=1000.2115.3001.5343\nQQ:暂无\n洛谷:Accteped,https://www.luogu.com.cn/user/368851\n这是作者第5个游戏";
    cout<<endl<<"\n\n帮助:\n扫出这些雷!!\n用鼠标点击扫雷\n右键可对可疑的方块进行标记\n请将窗口调大,并调成插入模式,具体方法请看\nhttps://blog.csdn.net/Accteped/article/details/109686246\nHave a good time!";
    getch();
    clear();
}
void find1(int x2,int y2){
    int x1,y1;
    for(int i=0;i<h;++i){
        for(int j=0;j<l;++j){
            if((x2==x[j]||x2==x[j]+1)&&y2==y[i]&&f1[i][j]!=-1){
                if(f1[i][j]==0){
                    if(mapn[i][j]==-1)le--;
                    tle--;
                    GotoXy(22,h);
                    cout<<"              ";GotoXy(22,h);
                    cout<<tle;
                    f1[i][j]=1;
                    GotoXy(x[j],y[i]);
                    cout<<"P ";return;
                }
                if(f1[i][j]==1){
                    if(mapn[i][j]==-1)le++;
                    tle++;
                    GotoXy(22,h);
                    cout<<"              ";
                    GotoXy(22,h);
                    cout<<tle;
                    f1[i][j]=0;
                    GotoXy(x[j],y[i]);
                    cout<<"■";
                }return ;
            }
        }
    }

}
void find3(int a,int b){
    int yd[10][2]={{0,-1},{0,1},{1,0},{-1,0}};
    for(int i=0;i<h;++i){
        for(int j=0;j<l;++j){
            if((a==x[j]||a==x[j]+1)&&b==y[i]&&f1[i][j]!=-1&&mapn[i][j]!=0){
                for(int k=0;k<4;++k){
                    int nx=yd[k][0]+i,ny=yd[k][1]+j;
                    if(nx<h&&nx>=0&&ny<l&&ny>=0&&mapn[nx][ny]==mapn[i][j]&&mapn[nx][ny]!=0&&f1[nx][ny]!=-1){
                        f1[nx][ny]=-1;cout<<mapn[nx][ny]<<' ';
                        GotoXy(x[ny],y[nx]);
                        
                    }
                }
            }
        }
    }
}
int main(){
    SetConsoleTitle("mine clearance");
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
                B;
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
        if(mouseRec.Event.MouseEvent.dwMousePosition.X>=12&&mouseRec.Event.MouseEvent.dwMousePosition.X<=31&&mouseRec.Event.MouseEvent.dwMousePosition.Y==3){
            if(!f3){
                f3=1;
                GotoXy(12,3);
                B;
                cout<<"关于作者与帮助(必看)";
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
            cout<<"关于作者与帮助(必看)";
        }
    }
    clear();
    srand(time(0));
    draw();
    thread time3(time2);
    while(1){
        if(le==0&&tle>=-1){
            clear();
            cout<<"难度:";
            if(l==9){
                cout<<"初级";
            }
            if(l==16) {
                cout<<"中级";
            }
            if(l==30){
                cout<<"高级";
            }
            cout<<"\nYou Win!\n";
            flagg=2;
            GotoXy(1,1);cout<<"用时:"<<time4<<'s';
            if(time4<maxn){
            	ofstream fout("初级.txt"),fout1("中级.txt"),fout2("高级.txt");
                cout<<endl<<"恭喜你打破了最高记录!";
                if(l==9){
                    fout<<time4;
                }
                if(l==16) {
                    fout1<<time4;
                }
                if(l==30){
                    fout2<<time4;
                }
            }else{
                cout<<endl;
                cout<<"最高记录为:"<<maxn<<"s";
                cout<<endl<<"你可以打破最高记录的,加油!";
            }
            getch();
            exit(0);
        }
        ReadConsoleInput(hIn, &mouseRec, 1, &res);
        if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
            int x1=mouseRec.Event.MouseEvent.dwMousePosition.X,y1=mouseRec.Event.MouseEvent.dwMousePosition.Y;
            if(mouseRec.Event.MouseEvent.dwEventFlags==DOUBLE_CLICK){  
                find3(x1,y1);
            } 
        } 
        if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
            int x1=mouseRec.Event.MouseEvent.dwMousePosition.X,y1=mouseRec.Event.MouseEvent.dwMousePosition.Y;
            find(x1,y1);
        } 
        else if(mouseRec.Event.MouseEvent.dwButtonState==RIGHTMOST_BUTTON_PRESSED){
            int x1=mouseRec.Event.MouseEvent.dwMousePosition.X,y1=mouseRec.Event.MouseEvent.dwMousePosition.Y;
            find1(x1,y1);
        }
    }
}
