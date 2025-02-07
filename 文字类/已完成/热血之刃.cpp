#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<thread> 
using namespace std;
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define R  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
#define G  SetConsoleTextAttribute(hStdOutHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define P  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
string name;
fstream file;
int mony=600,jb=5,ts,r=0,wait1=400,wait2=500,gc=1,jy1[100]={-1,25,200,350,460,600,850,1000,1500,2187,2898},djj[100]={0,10,15,25,30,40,45,60,70,85,100},dj=0,jy=0,year=0,day=0,month,tyear,tday,tmonth;
time_t now=time(0);
tm *ltm=localtime(&now);
double xn=20,dx,zx,xx,sx=20,fy=1,gj=4,cd,tcd;
ifstream fin("2.txt"); 
string wq=",",d="Accteped",hj=",",tzh,mm,tmm;
bool f=0,sl=1,party_11=0;
void print(string s){
    for(int i=0;i<s.size();++i){
        cout<<s[i];
        Sleep(70);
    }
}
void save(){
	while(1){
		cd=((((int(xn+gj+fy)%100+(int(xx+zx+dx)*2)%100+(jb+mony*2)%100+(jy+dj)%100)+(day+month*32+year*100+ts*100)%100)%100))<<3;
		file.open(name.c_str(), ios::out | ios::trunc);
        file<<year<<' '<<month<<' '<<day<<' '<<ts<<' '<<cd<<' '<<dj<<' '<<jy<<' '<<hj<<' '<<name<<' '<<mony<<' '<<xn<<' '<<gc<<' '<<sx<<' '<<gj<<' '<<fy<<' '<<jb<<' '<<xx<<' '<<zx<<' '<<dx<<' '<<r<<' '<<wq<<' '<<mm;
		file.close();
		Sleep(5000);
	}
}
void Hwnd(HWND &hWnd){
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE     );
}
void qp(){
    system("cls");
}
void jsdj(){
	int tdj=dj;
	if(tdj>=10)return ;
	for(int i=dj;i<=10;++i){
		if(jy>=jy1[i])dj=i;
		else break;
	}
	if(dj>tdj){
		for(int i=tdj;i<=dj;++i){
			xn+=djj[i];
			sx+=djj[i];
			gj+=int(djj[i]/((rand()%2)+2));
			fy+=0.5;
		}
		xn=sx;
	}
}
void cg(){
	qp();
	int dgj=gc*4+(rand()%4),dxn=gc*6+(rand()%10),dfy=rand()%2+1,cst=1+rand()%2,cs=0;
	cout<<"是否购买不死金身(800)1(是)/任意(否)";
	cout<<"\n我方血量:"<<xn<<"     "<<"敌方血量:"<<dxn<<endl<<"我方攻击:"<<gj<<"     "<<"敌方攻击:"<<dgj<<endl<<"我方防御:"<<fy<<"     "<<"敌方防御:"<<dfy<<endl;
	int txn;
	bool jsxn;
	int ss;
	cin>>ss;
	if(ss==1){
		if(mony>=800){
			jsxn=true;
			txn=xn;
			mony-=800;
			cout<<"购买成功";
		}else{
			cout<<"金币不足";
		}
	}else{
		jsxn=false;
	}
	Sleep(1000);
	qp();
    cout<<"第"<<gc<<"关"<<endl;
	for(int i=1;1;++i){
		ks:
		jsdj();
		cs++;
        cout<<"我方血量:"<<xn<<"     "<<"敌方血量:"<<dxn<<endl<<"我方攻击:"<<gj<<"     "<<"敌方攻击:"<<dgj<<endl<<"我方防御:"<<fy<<"     "<<"敌方防御:"<<dfy<<endl;
        string t="攻击",tdg="攻击",dfs="防御",fs="防御";
        int kx=gj,dkx=dgj,tdf=dfy,tf=fy;
        if(rand()%4==0){
            tdg="暴击";
            dkx+=rand()%5;
        }
        if(rand()%3==0){
            t="暴击";
            kx+=rand()%5;
        }
        if(rand()%4==0){
            tdf+=rand()%3+1;
            dfs="铁壁";
        }
        if(rand()%3==0){
            tf+=rand()%3+1;
            fs="铁壁";
        }
        cout<<"我方使用"<<t<<",敌方使用"<<dfs<<"抵消"<<tdf<<"点血"<<"      "<<"我方扣除敌方";
        dxn-=(kx-tdf);
        if(kx-tdf<=0){
            cout<<0<<endl;
        } 
        else{
            cout<<kx-tdf<<endl;
        }
        if(dxn<=0){
        	int jyjj=(rand()%13+5);
        	jy+=jyjj;
			Sleep(1000);
        	qp();
        	gc++;
            int jjjjj=260+rand()%40,jjx=rand()%10;
            cout<<"敌方剩余血量为"<<dxn<<'\n'<<"我方胜利!!\n"<<"恭喜你获得"<<jjjjj<<"金币     "<<jyjj<<"点经验\n"<<"你还剩"<<xn<<"滴血\n";
            mony+=jjjjj;
            if(xn+jjx>=sx)xn=sx; 
            else xn+=jjx;
            if(jsxn){
            	sjs:
	            cout<<"\n是否开启金身(1是,0否)";
	            char sjd=getch();
	            if(sjd=='1')xn=txn;
	            else if(sjd=='0')mony+=600;
	            else goto sjs;
	            jsxn=false;
			}
            cout<<"\n1.下一关\n0.退出";dd:char z;
            Sleep(1000);
            z=getch();
			if(z=='1'){
				qp();
			    dgj=gc*(3+rand()%4),dxn=gc*(5+rand()%10),dfy=rand()%2+1;
			    cout<<"是否购买不死金身(800)1(是)/任意(否)";
				cout<<"\n我方血量:"<<xn<<"     "<<"敌方血量:"<<dxn<<endl<<"我方攻击:"<<gj<<"     "<<"敌方攻击:"<<dgj<<endl<<"我方防御:"<<fy<<"     "<<"敌方防御:"<<dfy<<endl;
				cin>>ss;
				if(ss==1){
					if(mony>=800){
						jsxn=true;
						txn=xn;
						mony-=800;
						cout<<"购买成功";
					}else{
						cout<<"金币不足";
					}
				}else{
					jsxn=false;
				}
				Sleep(1000);
				qp();
				cout<<"第"<<gc<<"关"<<endl;
			    goto ks;
			}if(z=='0'){
				goto tct;
			}else{
				goto dd;
			}
        }Sleep(1000);
        cout<<"敌方使用"<<tdg<<",我方使用"<<fs<<"抵消"<<tf<<"点血"<<"      "<<"敌方扣除我方";
        if(dkx-tf<=0){
            cout<<0<<endl;
        }
        else{
            cout<<dkx-tf<<endl;
            xn-=(dkx-tf);
        }
        if(xn<=0){
    		qp();
    		if(jsxn){
    			xn=txn;
    			cout<<"金身已开启";
			}
    		else{
    			xn=5;
    			cout<<"血量不足\n已逃跑\n";
			}
    		goto tct;
        }Sleep(700);
    }
    tct:
    getch();
}
void sd(){
    while(1){
        qp();
        cout<<name<<":\n您现在有"<<mony<<"个金币"<<endl;
        cout<<"药水:\n1.小型药水(300,30滴血)\n2.中型药水(500,60滴血)\n3.大型药水(650,100滴血)\n装备:\n武器:\n4.木剑(500)\n5.铁剑(1300)\n6.钻石剑(2000)\n护甲:\n7.皮革甲(650)\n8.铁甲(1500)\n9.钻石甲(2300)\n0.退出\n";
        int t;
        cin>>t;
        bool fe=1;
        switch(t){
            case 1:
                if(mony>=300){
                    mony-=300;
                    xx++;cout<<"购买成功!!";Sleep(1000);
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 2:
                if(mony>=500){
                    mony-=500;
                    zx++;cout<<"购买成功!!";Sleep(1000);
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 3:
                if(mony>=650){
                    mony-=650;
                    dx++;cout<<"购买成功!!";
                    Sleep(1000);
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 4:
                if(mony>=500){
                    mony-=500;
                    wq+="木剑,";
                    sx+=10;
                    xn+=10;
                    jy+=4;
                    gj+=10;cout<<"购买成功!!";Sleep(1000);
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 5:
                if(mony>=1300){
                    mony-=1300;
                    wq+="铁剑,";
                    sx+=20;
                    jy+=9;
                    xn+=20;
                    gj+=30;cout<<"购买成功!!";Sleep(1000);
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 6:
                if(mony>=2000){
                    mony-=2000;
                    wq+="钻石剑,";
                    sx+=30;
                    jy+=11;
                    xn+=30;
                    cout<<"购买成功!!";Sleep(1000);
                    gj+=60;
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 7:
                if(mony>=650){
                    mony-=650;
                    hj+="皮革甲,";
                    sx+=20;
                    xn+=20;
                    jy+=6; 
                    cout<<"购买成功!!";Sleep(1000);
                    fy+=7;
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 8:
                if(mony>=1500){
                    mony-=1500;
                    hj+="铁甲,";
                    sx+=30;
                    xn+=30;
                    jy+=11;
                    cout<<"购买成功!!";Sleep(1000);
                    fy+=15;
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 9:
                if(mony>=2300){
                    mony-=2300;
                    hj+="钻石甲,";
                    sx+=40;
                    xn+=40;
                    jy+=14;
                    cout<<"购买成功!!";Sleep(1000);
                    fy+=25;
                }else{
                    cout<<"钱不够";Sleep(1000);
                }break;
            case 0:
                fe=0;
                break;
        }
        if(fe==0)break;
        qp();
    }
}
void zt(){
    qp();
    cout<<"等级:"<<dj<<endl;
    cout<<"血量:";printf("%.1lf    ",xn);cout<<"血量上限:";printf("%.1lf\n",sx);
    cout<<"钱数:"<<mony<<endl;
    cout<<"防御:";printf("%.1lf\n",fy);
    cout<<"装备:\n武器:";
    if(wq==","||wq=="  ")cout<<"无"<<endl;
    else cout<<wq<<endl;
    cout<<"护甲:";
    if(hj==",")cout<<"无"<<endl;
    else cout<<hj<<endl; 
    cout<<"攻击力:"<<gj<<endl;
    cout<<"按任意键退出"<<endl;
    system("pause>nul");
}
void bl(){
    qp();
    long long qs=time(0);
    cout<<"正在捕猎中...\n提示:越久收获越多!\n按任意键结束\n";
    while(1){
        if(kbhit()){
            break;
        }else{
            if(time(0)-qs>200+rand()%40){
                cout<<"你已经筋疲力尽了.."<<endl;
                getch();
                break;
            }
        }
    }
    long long zz=time(0)-qs,hd=0;
    if(gj<=50){
        hd=zz/7;
    }
    else if(gj<=500){
        hd=zz/6;
    }else{
        hd=zz/5;
    }
    r+=hd;
    qp();
    cout<<"您捕到了"<<hd<<"块肉"<<endl;Sleep(1000);
    system("pause>nul");
}
void zd(){
    sd:
    qp();
	int fw;
    int dxn,dgj,dfy=1+rand()%2;
    cout<<"1.扫荡\n2.闯关\n3.状态\n0.返回\n";
    char c=getch();
    if(c=='3'){
        zt();
        goto sd;
    }
    if(c=='2'){
    	cg();
    	if(sl==0){
    		return ;
		}
    	goto sd;
	}
    if(c=='0'){
    	return ;
    }
    else if(c!='1'){
        goto sd;
    }
    int jjj=0;
    dfy=1+rand()%2;
    if(sx<=50){
    	jjj=5;
        dxn=rand()%100+1;dgj=rand()%50+5;
        if(gj>=dxn||fy>=dgj){
        	jjj=1;
		}
    }else if(sx>50&&sx<100||gj>50&&gj<=100){
    	jjj=10;
        dxn=rand()%150+50;dgj=rand()%80+5;
        if(gj>=dxn||fy>=dgj){
        	jjj=7;
		}
    }
    else if(sx>100&&sx<=250||gj>100&&gj<=250){
    	jjj=19;
        dxn=rand()%280+100;dgj=rand()%140+50;
        if(gj>=dxn||fy>=dgj){
        	jjj=10;
		}
    }else if(sx>250&&sx<500){
    	jjj=25;
        dxn=rand()%600+300,dgj=rand()%220+20;
        if(gj>=dxn||fy>=dgj){
        	jjj=12;
		}
    }
    else if(sx<1000){
    	jjj=30;
        dxn=rand()%1400+300,dgj=rand()%420+70;
        if(gj>=dxn||fy>=dgj){
        	jjj=15;
		}
	}else{
		jjj=45;
        dxn=rand()%4000+300,dgj=rand()%620+100;
        if(gj>=dxn||fy>=dgj){
        	jjj=21;
		}
	}
	qp();
    string dr[3]={"路人","警察","疯子"},drzt[3]={"冲了过来","扑了过来","拿着棍子打了过来"};int dr_num=rand()%3,drzt_num=rand()%3; 
    cout<<dr[dr_num]<<drzt[drzt_num]<<endl;
	cout<<"我方血量:"<<xn<<"     "<<"敌方血量:"<<dxn<<endl<<"我方攻击:"<<gj<<"     "<<"敌方攻击:"<<dgj<<endl<<"我方防御:"<<fy<<"     "<<"敌方防御:"<<dfy<<endl;
	cout<<"\n1.逃跑\n2.战斗\n";
    csss:
    char d=getch();
    if(d=='1'){
    	goto sd;
    }
    else if(d=='2')qp();
    else goto csss;
    for(int i=1;1;++i){
    	jsdj();
        cout<<"我方血量:"<<xn<<"     "<<"敌方血量:"<<dxn<<endl<<"我方攻击:"<<gj<<"     "<<"敌方攻击:"<<dgj<<endl<<"我方防御:"<<fy<<"     "<<"敌方防御:"<<dfy<<endl;
        cout<<"    ***********   "<<endl;
        cout<<"    ***第"<<i<<"次***   "<<endl;
        cout<<"    ***********   "<<endl;
		Sleep(1000);
        string t="攻击",tdg="攻击",dfs="防御",fs="防御";
        int kx=gj,dkx=dgj,tdf=dfy,tf=fy;
        if(rand()%3==0){
            tdg="暴击";
            dkx+=rand()%5;
        }
        if(rand()%2==0){
            t="暴击";
            kx+=rand()%5;
        }
        if(rand()%4==0){
            tdf+=rand()%3+1;
            dfs="铁壁";
        }
        if(rand()%3==0){
            tf+=rand()%3+1;
            fs="铁壁";
        }
        cout<<"我方使用";
        if(t=="暴击")R;
        cout<<t;
        W;
		cout<<",敌方使用";
		if(dfs=="铁壁")B;
		cout<<dfs;
		W;
		cout<<"抵消"<<tdf<<"点血"<<"      "<<"我方扣除敌方";
        if(kx-tdf<=0){
            cout<<0<<endl;
        } 
        else{
			dxn-=(kx-tdf);
            cout<<kx-tdf<<endl;
        }
        if(dxn<=0){
        	jy+=(jjj+rand()%5);
            int jjjjj=200+rand()%40,jjx=rand()%10;
            cout<<dr[dr_num]<<"倒在了地上";
            cout<<"\n"<<"我方胜利!!\n"<<"恭喜你获得"<<jjjjj<<"金币,增加2点血量上限\n"<<"你还剩"<<xn<<"滴血\n";
            mony+=jjjjj,sx+=2;
            if(xn+jjx>=sx)xn=sx; 
            else xn+=jjx;
            cout<<"按任意键退出\n";
            system("pause>nul");
            goto sd;
        }Sleep(500);
        cout<<"敌方使用";
        if(tdg=="暴击")R;
        cout<<tdg;
        W;
		cout<<",我方使用";
		if(fs=="铁壁")B;
		cout<<fs;
		W;
		cout<<"抵消"<<tf<<"点血"<<"      "<<"敌方扣除我方";
        if(dkx-tf<=0){
            cout<<0<<endl;
        }
        else{
            cout<<dkx-tf<<endl;
            xn-=(dkx-tf);
        }
        if(xn<=0){
            qp();
            cout<<"我方剩余血量为0\n"<<dr[dr_num]<<"踩了你一脚,不屑的瞪了你一眼,走了\n"<<dr[dr_num]<<"还剩"<<dxn<<"滴血\n";
            cout<<"已逃跑";
			xn=3; 
			goto sd;
        } 
    }
    system("pause>nul");
}
void hx(){
    while(1){
        cs:
        f=0;
        qp();
        cout<<name<<"\n您现在的血量为";
        printf("%.1lf",xn);
        cout<<','<<"血量上限为:";
        printf("%.1lf\n",sx);
        cout<<"您有:"<<endl;
        cout<<"1.小型药水(30):"<<xx<<endl; 
        cout<<"2.中型药水(60):"<<zx<<endl; 
        cout<<"3.大型药水(100):"<<dx<<endl; 
        cout<<"4.肉(1):"<<r<<endl; 
        cout<<"0.退出"<<endl; 
        int n;
        cin>>n;
        if(xn==sx&&n!=0){
            cout<<"您是满血,无法回血";
            Sleep(1000);
            continue;
        }
        switch(n){
            case 1:
                if(xx==0){
                    qp();
                    cout<<"数量不够!!!";
                    system("pause>nul");break;
                }
                if(xx>0){
                    xx--;
                    if(xn+30>sx)xn=sx;
                    else xn+=30;break;
                }break;
            case 2:
                if(zx==0){
                    qp();
                    cout<<"数量不够!!!";
                    system("pause>nul");break;
                }
                if(zx>0){
                    zx--;
                    if(xn+60>sx)xn=sx;
                    else xn+=60;break;
                }break;
            case 3:
                if(dx==0){
                    qp();
                    cout<<"数量不够!!!";
                    system("pause>nul");break;
                }
                if(dx>0){
                    dx--;
                    if(xn+100>sx)xn=sx;
                    else xn+=100;break;
                }break;
            case 4:
                if(r==0){
                    qp();
                    cout<<"数量不够!!!";
                    system("pause>nul");break;
                }else{
                    r--;
                    if(xn+1>sx)xn=sx;
                    else xn+=1;break;
                }
            case 0:
                f=1;
                break;
            default:goto cs;
        }if(f)break;
    }
}
void bm(){
    long long qs=time(0);
    cout<<"正在挖矿中...\n提示:越久收获越多!\n按任意键结束\n";
    while(1){
        if(kbhit()){
            break;
        }else{
        	if(time(0)-qs>250+rand()%70){
                cout<<"你已经筋疲力尽了.."<<endl;
                getch();
                break;
            }
        }
    }
    long long zz=time(0)-qs,hd=0;
    if(zz>=2){
        hd=zz/2*3;
        mony+=hd;
    }
    qp();
    cout<<"您挖到了"<<hd<<"元"<<endl;Sleep(1000);
    getch();
} 
void jjb(int &a){
    qp();
    cout<<"是否使用?(y or n)";
    char ch=getche();
    qp();
    if(ch=='y'){
        if(a>0){
            cout<<"救济成功!!";
            mony+=300; 
            a--;
        }else{
            cout<<"次数不足!";
        }   
    }cout<<endl;
    system("pause");
}
void rz(){
	qp();
	cout<<"1.1:修复BUG\n1.5:更新存档功能\n1.6:更新账号密码功能\n1.7:增加闯关修复BUG\n1.8:增加等级和经验功能\n1.8.5:增加签到功能,修复已知BUG\nAccteped\n";
	system("pause>nul");
	qp();
}
void jsgame(){
	qp();
    cout<<"您的得分是:"<<sx*5+gj*6+mony*2+fy*3<<endl;
    cout<<"欢迎下次再来!";
    Sleep(1000);
    exit(0);
}
void store(){
	while(1){
		qp();
		cout<<name<<":\n您现在有"<<mony<<"个金币"<<endl;
		if(party_11){
			
		}
		
		if(party_11){
			cout<<"1.凋零剑("<<"原价5500,现价"<<5500*0.8<<")\n2.附魔剑("<<"原价7000,现价"<<5550<<")\n\n3.凋零骷髅头("<<"原价9000,现价"<<7200<<")\n0.退出\n";
		}else cout<<"1.凋零剑(5500)\n2.附魔剑(7000)\n\n3.凋零骷髅头(9000)\n0.退出\n";
		int t;
	    cin>>t;
	    bool fe=1;
	    switch(t){
	    	int jg;
	        case 1:
	        	jg=5500;
	        	if(party_11){
	        		jg=int(5500*0.8);
				}
	            if(mony>=jg){
	                mony-=jg;
	                wq+="凋零剑,";
	                sx+=70;
	                xn+=70;
	                jy+=20;
	                gj+=100;cout<<"购买成功!!";Sleep(1000);
	            }else{
	                cout<<"钱不够";Sleep(1000);
	            }break;
	        case 2:
	        	jg=7000;
	        	if(party_11){
	        		jg=5550;
				}
	            if(mony>=jg){
	                mony-=jg;
	                wq+="附魔剑,";
	                sx+=90;
	                xn+=90;
	                jy+=30;
	                gj+=150;cout<<"购买成功!!";Sleep(1000);
	            }else{
	                cout<<"钱不够";Sleep(1000);
	            }break;
	        case 3:
	        	jg=9000;
	        	if(party_11){
	        		jg=7200;
				}
	            if(mony>=jg){
	                mony-=jg;
	                hj+="凋零骷髅头,";
	                sx+=90;
	                xn+=90;
	                fy+=100;
	                jy+=50;
	                gj+=10;
	                cout<<"购买成功!!";Sleep(1000);
	            }else{
	                cout<<"钱不够";Sleep(1000);
	            }break;
	        case 0:
	        	fe=0;
	        	break;
	    }if(fe==0)break;
	}
    qp();
}
void qds(){
	if(rand()%5==0){
		if(rand()%100==35){
			cout<<"获得了铁剑";
			wq+="铁剑,";
			sx+=20;
            xn+=20;
            gj+=30;
		}else if(rand()%300==118){
			cout<<"获得了铁甲";
			hj+="铁甲,";
			sx+=30;
            xn+=30;
            fy+=10;
		}else{
			int xz=rand()%7,jjd=1,jjx=3,jjz=2,jjr=10;
			cout<<"获得了";
			if(xz==0){
				jjd+=rand()%2;
				cout<<jjd<<"个大型药水";
				dx+=jjd;
			}else if(xz<3){
				jjz+=rand()%2;
				cout<<jjz<<"个中型药水";
				zx+=jjz;
			}else if(xz<5){
				jjx+=rand()%2;
				cout<<jjx<<"个小型药水";
				xx+=jjx;
			}else{
				jjr+=rand()%4;
				cout<<jjr<<"块肉";
				r+=jjr;
			}
		}
	}else if(rand()%3==0){
		int jjjy=13+rand()%9;
		if(rand()%25==0){
			jjjy=25+rand()%15+rand()%7;
		}
		cout<<"获得了"<<jjjy<<"点经验";
		jy+=jjjy;
	}else{
		int jjjb=350+rand()%200;
		cout<<"获得了"<<jjjb<<"个金币";
		mony+=jjjb;
	}cout<<endl;
}
void qd(bool &f,int &ts){
	if(tyear>year||tmonth>month||tday>day){
		cout<<"签到成功!"<<endl;
		qds();
		f=1;ts++;jb+=rand()%2;
		cout<<"上次签到时间为:";
		if(year==0)cout<<"无";
		else printf("%d年%d月%d日",1900+year,1+month,day);
		year=tyear,month=tmonth,day=tday;
	}else{
		cout<<"今日已签到\n要一步一个脚印,不要心急\n";
		cout<<"上次签到时间为:";
		if(year==0)cout<<"无";
		else printf("%d年%d月%d日",1900+year,1+month,day);
	}Sleep(500);cout<<"\n按任意键退出";system("pause>nul");
}
void GotoXy(int x,int y){//x列,y行 
    HANDLE hout;
    COORD coord;
    coord.X=x;
    coord.Y=y;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout,coord);
}
int main(){
	W;
	SetConsoleTitle("The blade of blood 1.8.5");
	bool hs=0;
    int ks,js,ks1,js1;
    srand(time(0));
    int feee=1,d=115;mony=500;
    print("热血之刃1.8.5:\n作者:Accteped\n按任意键开始\n请不要在名字内输入空格,后果自负(记得点保存)");
    system("pause>nul");
    cw:
    qp();
    v:
    printf("1.新建存档\n2.加载存档\n");
    char c=getch();
    qp();
    if(c=='1'){
    	cout<<"0.退出";
		char sbs=getch();
		if(sbs=='0'){
			goto cw;
		}qp();
    	jy=0,dj=0;
        qp();jb=5;
        printf("请输入您的账号名:");
        cin>>name;mony=500;
        printf("请输入您的密码:");
        cin>>mm;
        file.open(name.c_str(), ios::out | ios::trunc);
        file<<year<<' '<<month<<' '<<day<<' '<<ts<<' '<<cd<<' '<<dj<<' '<<jy<<' '<<hj<<' '<<name<<' '<<mony<<' '<<xn<<' '<<gc<<' '<<sx<<' '<<gj<<' '<<fy<<' '<<jb<<' '<<xx<<' '<<zx<<' '<<dx<<' '<<r<<' '<<wq<<' '<<mm;
		file.close();
        getch();
    }
    else if(c=='2'){
    	sb:
    	qp();
    	cout<<"0.退出";
		char sbs=getch();
		if(sbs=='0'){
			goto cw;
		}qp();
		printf("请输入您的账号名:");cin>>tzh;
		printf("请输入您的密码:");cin>>tmm;
		file.open(tzh.c_str(), ios::in);
		file>>year>>month>>day>>ts>>cd>>dj>>jy>>hj>>name>>mony>>xn>>gc>>sx>>gj>>fy>>jb>>xx>>zx>>dx>>r>>wq>>mm;
		tcd=((((int(xn+gj+fy)%100+(int(xx+zx+dx)*2)%100+(jb+mony*2)%100+(jy+dj)%100)+(day+month*32+year*100+ts*100)%100)%100))<<3;
		if(!file.is_open()){
			cout<<"未找到存档"<<endl;
			getch();
			goto sb;
		}
		if(tmm!=mm){
			cout<<"密码错误"<<endl;
			getch();
			file.close();
			goto sb;
		}
		if(tcd!=cd){
			qp();
			cout<<"有疑似作弊行为,登录失败"<<endl;
			system("pause");
			file.close();
			goto cw;
		}
		cout<<"登入成功!";
		getch(); 
		file.close();
	}else{
		goto cw;
	}
    if(name=="Accteped"&&c!='2'){
        qp();
        printf("你竟想冒犯作者!!");
        mony=0;
        getch();
    }
    qp();
    print("欢迎你:");
    print(name);
   	printf("\n");
	ltm=localtime(&now);
	tday=ltm->tm_mday;
	tyear=ltm->tm_year;
	tmonth=ltm->tm_mon;
	if(tday==11&&tmonth+1==11){
		MessageBox(NULL,TEXT("今天是双十一(有促销活动)"),TEXT("游戏提示"),MB_OK);
		party_11=true;
	}thread save1(save);
    while(1){
    	jsdj();
        qp();
        bool jls=0;
        cout<<name<<"请问你要干什么\n"<<"您现在的等级是:"<<dj<<"  经验是:"<<jy;
        if(dj>=10)cout<<"您已满级";
        else cout<<"(离下一级还差"<<jy1[dj+1]-jy<<')';
        cout<<endl;
        cout<<"1.战斗  2.商店  3.回血  4.状态  5.金币救助(还剩"<<jb<<"次)  6.挖矿  7.捕猎\n8.保存  0.更新版本特性  e.签到  t.结束游戏  d.查看原文地址";
        if(dj>=3){
        	cout<<"  h.黑市";
			hs=1;
		}
        cout<<endl;
        cs:
        char c=getch();
        switch(c){
        	case 'd':
        		qp();
        		cout<<"版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。\n本文链接：https://blog.csdn.net/Accteped/article/details/109686246\n";
        		Sleep(1000);
        		system("pause");
        		system("start https://blog.csdn.net/Accteped/article/details/109686246");
        		system("pause");
        		break;
        	case 'e':
        		qp();
        		ltm=localtime(&now);
        		tday=ltm->tm_mday;
        		tyear=ltm->tm_year;
        		tmonth=ltm->tm_mon;
        		qd(jls,ts);
        		break;
        	case '2':sd();break;
        	case 'h':
				if(hs)store();
				break;
            case '1':
                sl=1;
                zd();
                if(sl==0){
                    shu:
                    cout<<"1.重玩\n0.退出\n";
                    char d2=getch();
                    if(d2=='1')goto cw;
                    else if(d2=='0'){
                        qp();
                        cout<<"欢迎下次再来!";
                        feee=0;
                        break;
                    }
                    else goto shu;
                }
                break;
            
            case '3':hx();break;
            case '4':zt();break;
            case '8':break;
            case '7':js=time(0);if(js-ks>=400){bl();ks=js;}else{qp();cout<<"你筋疲力尽"<<endl<<"还剩"<<400-(js-ks)<<"秒\n";getch();qp();};break;
            case '6':qp();js1=time(0);if(js1-ks1>=260){bm();ks1=js1;}else{qp();cout<<"你筋疲力尽"<<endl<<"还剩"<<260-js1+ks1<<"秒\n";;getch();qp();};break;
            case '5':jjb(jb);break;
            case '0':rz();break;
            case 't':
				qp();
				cout<<"是否结束(y(是) or 任意键(否)";
				char tts=getchar();
				if(tts=='y')jsgame();
				else break;
				break;
            goto cs;
        }if(!feee)break;
        if(c=='8'){
        	cd=((((int(xn+gj+fy)%100+(int(xx+zx+dx)*2)%100+(jb+mony*2)%100+(jy+dj)%100)+(day+month*32+year*100+ts*100)%100)%100))<<3;
            file.open(name.c_str(), ios::out | ios::trunc);
	        file<<year<<' '<<month<<' '<<day<<' '<<ts<<' '<<cd<<' '<<dj<<' '<<jy<<' '<<hj<<' '<<name<<' '<<mony<<' '<<xn<<' '<<gc<<' '<<sx<<' '<<gj<<' '<<fy<<' '<<jb<<' '<<xx<<' '<<zx<<' '<<dx<<' '<<r<<' '<<wq<<' '<<mm;
			file.close();
            qp();
            cout<<"保存成功!!";
            SetFileAttributes("2.txt",FILE_ATTRIBUTE_HIDDEN);
            Sleep(1000);
        }
    }
}
