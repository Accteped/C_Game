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
	cout<<"�Ƿ���������(800)1(��)/����(��)";
	cout<<"\n�ҷ�Ѫ��:"<<xn<<"     "<<"�з�Ѫ��:"<<dxn<<endl<<"�ҷ�����:"<<gj<<"     "<<"�з�����:"<<dgj<<endl<<"�ҷ�����:"<<fy<<"     "<<"�з�����:"<<dfy<<endl;
	int txn;
	bool jsxn;
	int ss;
	cin>>ss;
	if(ss==1){
		if(mony>=800){
			jsxn=true;
			txn=xn;
			mony-=800;
			cout<<"����ɹ�";
		}else{
			cout<<"��Ҳ���";
		}
	}else{
		jsxn=false;
	}
	Sleep(1000);
	qp();
    cout<<"��"<<gc<<"��"<<endl;
	for(int i=1;1;++i){
		ks:
		jsdj();
		cs++;
        cout<<"�ҷ�Ѫ��:"<<xn<<"     "<<"�з�Ѫ��:"<<dxn<<endl<<"�ҷ�����:"<<gj<<"     "<<"�з�����:"<<dgj<<endl<<"�ҷ�����:"<<fy<<"     "<<"�з�����:"<<dfy<<endl;
        string t="����",tdg="����",dfs="����",fs="����";
        int kx=gj,dkx=dgj,tdf=dfy,tf=fy;
        if(rand()%4==0){
            tdg="����";
            dkx+=rand()%5;
        }
        if(rand()%3==0){
            t="����";
            kx+=rand()%5;
        }
        if(rand()%4==0){
            tdf+=rand()%3+1;
            dfs="����";
        }
        if(rand()%3==0){
            tf+=rand()%3+1;
            fs="����";
        }
        cout<<"�ҷ�ʹ��"<<t<<",�з�ʹ��"<<dfs<<"����"<<tdf<<"��Ѫ"<<"      "<<"�ҷ��۳��з�";
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
            cout<<"�з�ʣ��Ѫ��Ϊ"<<dxn<<'\n'<<"�ҷ�ʤ��!!\n"<<"��ϲ����"<<jjjjj<<"���     "<<jyjj<<"�㾭��\n"<<"�㻹ʣ"<<xn<<"��Ѫ\n";
            mony+=jjjjj;
            if(xn+jjx>=sx)xn=sx; 
            else xn+=jjx;
            if(jsxn){
            	sjs:
	            cout<<"\n�Ƿ�������(1��,0��)";
	            char sjd=getch();
	            if(sjd=='1')xn=txn;
	            else if(sjd=='0')mony+=600;
	            else goto sjs;
	            jsxn=false;
			}
            cout<<"\n1.��һ��\n0.�˳�";dd:char z;
            Sleep(1000);
            z=getch();
			if(z=='1'){
				qp();
			    dgj=gc*(3+rand()%4),dxn=gc*(5+rand()%10),dfy=rand()%2+1;
			    cout<<"�Ƿ���������(800)1(��)/����(��)";
				cout<<"\n�ҷ�Ѫ��:"<<xn<<"     "<<"�з�Ѫ��:"<<dxn<<endl<<"�ҷ�����:"<<gj<<"     "<<"�з�����:"<<dgj<<endl<<"�ҷ�����:"<<fy<<"     "<<"�з�����:"<<dfy<<endl;
				cin>>ss;
				if(ss==1){
					if(mony>=800){
						jsxn=true;
						txn=xn;
						mony-=800;
						cout<<"����ɹ�";
					}else{
						cout<<"��Ҳ���";
					}
				}else{
					jsxn=false;
				}
				Sleep(1000);
				qp();
				cout<<"��"<<gc<<"��"<<endl;
			    goto ks;
			}if(z=='0'){
				goto tct;
			}else{
				goto dd;
			}
        }Sleep(1000);
        cout<<"�з�ʹ��"<<tdg<<",�ҷ�ʹ��"<<fs<<"����"<<tf<<"��Ѫ"<<"      "<<"�з��۳��ҷ�";
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
    			cout<<"�����ѿ���";
			}
    		else{
    			xn=5;
    			cout<<"Ѫ������\n������\n";
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
        cout<<name<<":\n��������"<<mony<<"�����"<<endl;
        cout<<"ҩˮ:\n1.С��ҩˮ(300,30��Ѫ)\n2.����ҩˮ(500,60��Ѫ)\n3.����ҩˮ(650,100��Ѫ)\nװ��:\n����:\n4.ľ��(500)\n5.����(1300)\n6.��ʯ��(2000)\n����:\n7.Ƥ���(650)\n8.����(1500)\n9.��ʯ��(2300)\n0.�˳�\n";
        int t;
        cin>>t;
        bool fe=1;
        switch(t){
            case 1:
                if(mony>=300){
                    mony-=300;
                    xx++;cout<<"����ɹ�!!";Sleep(1000);
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 2:
                if(mony>=500){
                    mony-=500;
                    zx++;cout<<"����ɹ�!!";Sleep(1000);
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 3:
                if(mony>=650){
                    mony-=650;
                    dx++;cout<<"����ɹ�!!";
                    Sleep(1000);
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 4:
                if(mony>=500){
                    mony-=500;
                    wq+="ľ��,";
                    sx+=10;
                    xn+=10;
                    jy+=4;
                    gj+=10;cout<<"����ɹ�!!";Sleep(1000);
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 5:
                if(mony>=1300){
                    mony-=1300;
                    wq+="����,";
                    sx+=20;
                    jy+=9;
                    xn+=20;
                    gj+=30;cout<<"����ɹ�!!";Sleep(1000);
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 6:
                if(mony>=2000){
                    mony-=2000;
                    wq+="��ʯ��,";
                    sx+=30;
                    jy+=11;
                    xn+=30;
                    cout<<"����ɹ�!!";Sleep(1000);
                    gj+=60;
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 7:
                if(mony>=650){
                    mony-=650;
                    hj+="Ƥ���,";
                    sx+=20;
                    xn+=20;
                    jy+=6; 
                    cout<<"����ɹ�!!";Sleep(1000);
                    fy+=7;
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 8:
                if(mony>=1500){
                    mony-=1500;
                    hj+="����,";
                    sx+=30;
                    xn+=30;
                    jy+=11;
                    cout<<"����ɹ�!!";Sleep(1000);
                    fy+=15;
                }else{
                    cout<<"Ǯ����";Sleep(1000);
                }break;
            case 9:
                if(mony>=2300){
                    mony-=2300;
                    hj+="��ʯ��,";
                    sx+=40;
                    xn+=40;
                    jy+=14;
                    cout<<"����ɹ�!!";Sleep(1000);
                    fy+=25;
                }else{
                    cout<<"Ǯ����";Sleep(1000);
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
    cout<<"�ȼ�:"<<dj<<endl;
    cout<<"Ѫ��:";printf("%.1lf    ",xn);cout<<"Ѫ������:";printf("%.1lf\n",sx);
    cout<<"Ǯ��:"<<mony<<endl;
    cout<<"����:";printf("%.1lf\n",fy);
    cout<<"װ��:\n����:";
    if(wq==","||wq=="  ")cout<<"��"<<endl;
    else cout<<wq<<endl;
    cout<<"����:";
    if(hj==",")cout<<"��"<<endl;
    else cout<<hj<<endl; 
    cout<<"������:"<<gj<<endl;
    cout<<"��������˳�"<<endl;
    system("pause>nul");
}
void bl(){
    qp();
    long long qs=time(0);
    cout<<"���ڲ�����...\n��ʾ:Խ���ջ�Խ��!\n�����������\n";
    while(1){
        if(kbhit()){
            break;
        }else{
            if(time(0)-qs>200+rand()%40){
                cout<<"���Ѿ���ƣ������.."<<endl;
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
    cout<<"��������"<<hd<<"����"<<endl;Sleep(1000);
    system("pause>nul");
}
void zd(){
    sd:
    qp();
	int fw;
    int dxn,dgj,dfy=1+rand()%2;
    cout<<"1.ɨ��\n2.����\n3.״̬\n0.����\n";
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
    string dr[3]={"·��","����","����"},drzt[3]={"���˹���","���˹���","���Ź��Ӵ��˹���"};int dr_num=rand()%3,drzt_num=rand()%3; 
    cout<<dr[dr_num]<<drzt[drzt_num]<<endl;
	cout<<"�ҷ�Ѫ��:"<<xn<<"     "<<"�з�Ѫ��:"<<dxn<<endl<<"�ҷ�����:"<<gj<<"     "<<"�з�����:"<<dgj<<endl<<"�ҷ�����:"<<fy<<"     "<<"�з�����:"<<dfy<<endl;
	cout<<"\n1.����\n2.ս��\n";
    csss:
    char d=getch();
    if(d=='1'){
    	goto sd;
    }
    else if(d=='2')qp();
    else goto csss;
    for(int i=1;1;++i){
    	jsdj();
        cout<<"�ҷ�Ѫ��:"<<xn<<"     "<<"�з�Ѫ��:"<<dxn<<endl<<"�ҷ�����:"<<gj<<"     "<<"�з�����:"<<dgj<<endl<<"�ҷ�����:"<<fy<<"     "<<"�з�����:"<<dfy<<endl;
        cout<<"    ***********   "<<endl;
        cout<<"    ***��"<<i<<"��***   "<<endl;
        cout<<"    ***********   "<<endl;
		Sleep(1000);
        string t="����",tdg="����",dfs="����",fs="����";
        int kx=gj,dkx=dgj,tdf=dfy,tf=fy;
        if(rand()%3==0){
            tdg="����";
            dkx+=rand()%5;
        }
        if(rand()%2==0){
            t="����";
            kx+=rand()%5;
        }
        if(rand()%4==0){
            tdf+=rand()%3+1;
            dfs="����";
        }
        if(rand()%3==0){
            tf+=rand()%3+1;
            fs="����";
        }
        cout<<"�ҷ�ʹ��";
        if(t=="����")R;
        cout<<t;
        W;
		cout<<",�з�ʹ��";
		if(dfs=="����")B;
		cout<<dfs;
		W;
		cout<<"����"<<tdf<<"��Ѫ"<<"      "<<"�ҷ��۳��з�";
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
            cout<<dr[dr_num]<<"�����˵���";
            cout<<"\n"<<"�ҷ�ʤ��!!\n"<<"��ϲ����"<<jjjjj<<"���,����2��Ѫ������\n"<<"�㻹ʣ"<<xn<<"��Ѫ\n";
            mony+=jjjjj,sx+=2;
            if(xn+jjx>=sx)xn=sx; 
            else xn+=jjx;
            cout<<"��������˳�\n";
            system("pause>nul");
            goto sd;
        }Sleep(500);
        cout<<"�з�ʹ��";
        if(tdg=="����")R;
        cout<<tdg;
        W;
		cout<<",�ҷ�ʹ��";
		if(fs=="����")B;
		cout<<fs;
		W;
		cout<<"����"<<tf<<"��Ѫ"<<"      "<<"�з��۳��ҷ�";
        if(dkx-tf<=0){
            cout<<0<<endl;
        }
        else{
            cout<<dkx-tf<<endl;
            xn-=(dkx-tf);
        }
        if(xn<=0){
            qp();
            cout<<"�ҷ�ʣ��Ѫ��Ϊ0\n"<<dr[dr_num]<<"������һ��,��м�ĵ�����һ��,����\n"<<dr[dr_num]<<"��ʣ"<<dxn<<"��Ѫ\n";
            cout<<"������";
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
        cout<<name<<"\n�����ڵ�Ѫ��Ϊ";
        printf("%.1lf",xn);
        cout<<','<<"Ѫ������Ϊ:";
        printf("%.1lf\n",sx);
        cout<<"����:"<<endl;
        cout<<"1.С��ҩˮ(30):"<<xx<<endl; 
        cout<<"2.����ҩˮ(60):"<<zx<<endl; 
        cout<<"3.����ҩˮ(100):"<<dx<<endl; 
        cout<<"4.��(1):"<<r<<endl; 
        cout<<"0.�˳�"<<endl; 
        int n;
        cin>>n;
        if(xn==sx&&n!=0){
            cout<<"������Ѫ,�޷���Ѫ";
            Sleep(1000);
            continue;
        }
        switch(n){
            case 1:
                if(xx==0){
                    qp();
                    cout<<"��������!!!";
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
                    cout<<"��������!!!";
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
                    cout<<"��������!!!";
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
                    cout<<"��������!!!";
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
    cout<<"�����ڿ���...\n��ʾ:Խ���ջ�Խ��!\n�����������\n";
    while(1){
        if(kbhit()){
            break;
        }else{
        	if(time(0)-qs>250+rand()%70){
                cout<<"���Ѿ���ƣ������.."<<endl;
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
    cout<<"���ڵ���"<<hd<<"Ԫ"<<endl;Sleep(1000);
    getch();
} 
void jjb(int &a){
    qp();
    cout<<"�Ƿ�ʹ��?(y or n)";
    char ch=getche();
    qp();
    if(ch=='y'){
        if(a>0){
            cout<<"�ȼóɹ�!!";
            mony+=300; 
            a--;
        }else{
            cout<<"��������!";
        }   
    }cout<<endl;
    system("pause");
}
void rz(){
	qp();
	cout<<"1.1:�޸�BUG\n1.5:���´浵����\n1.6:�����˺����빦��\n1.7:���Ӵ����޸�BUG\n1.8:���ӵȼ��;��鹦��\n1.8.5:����ǩ������,�޸���֪BUG\nAccteped\n";
	system("pause>nul");
	qp();
}
void jsgame(){
	qp();
    cout<<"���ĵ÷���:"<<sx*5+gj*6+mony*2+fy*3<<endl;
    cout<<"��ӭ�´�����!";
    Sleep(1000);
    exit(0);
}
void store(){
	while(1){
		qp();
		cout<<name<<":\n��������"<<mony<<"�����"<<endl;
		if(party_11){
			
		}
		
		if(party_11){
			cout<<"1.���㽣("<<"ԭ��5500,�ּ�"<<5500*0.8<<")\n2.��ħ��("<<"ԭ��7000,�ּ�"<<5550<<")\n\n3.��������ͷ("<<"ԭ��9000,�ּ�"<<7200<<")\n0.�˳�\n";
		}else cout<<"1.���㽣(5500)\n2.��ħ��(7000)\n\n3.��������ͷ(9000)\n0.�˳�\n";
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
	                wq+="���㽣,";
	                sx+=70;
	                xn+=70;
	                jy+=20;
	                gj+=100;cout<<"����ɹ�!!";Sleep(1000);
	            }else{
	                cout<<"Ǯ����";Sleep(1000);
	            }break;
	        case 2:
	        	jg=7000;
	        	if(party_11){
	        		jg=5550;
				}
	            if(mony>=jg){
	                mony-=jg;
	                wq+="��ħ��,";
	                sx+=90;
	                xn+=90;
	                jy+=30;
	                gj+=150;cout<<"����ɹ�!!";Sleep(1000);
	            }else{
	                cout<<"Ǯ����";Sleep(1000);
	            }break;
	        case 3:
	        	jg=9000;
	        	if(party_11){
	        		jg=7200;
				}
	            if(mony>=jg){
	                mony-=jg;
	                hj+="��������ͷ,";
	                sx+=90;
	                xn+=90;
	                fy+=100;
	                jy+=50;
	                gj+=10;
	                cout<<"����ɹ�!!";Sleep(1000);
	            }else{
	                cout<<"Ǯ����";Sleep(1000);
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
			cout<<"���������";
			wq+="����,";
			sx+=20;
            xn+=20;
            gj+=30;
		}else if(rand()%300==118){
			cout<<"���������";
			hj+="����,";
			sx+=30;
            xn+=30;
            fy+=10;
		}else{
			int xz=rand()%7,jjd=1,jjx=3,jjz=2,jjr=10;
			cout<<"�����";
			if(xz==0){
				jjd+=rand()%2;
				cout<<jjd<<"������ҩˮ";
				dx+=jjd;
			}else if(xz<3){
				jjz+=rand()%2;
				cout<<jjz<<"������ҩˮ";
				zx+=jjz;
			}else if(xz<5){
				jjx+=rand()%2;
				cout<<jjx<<"��С��ҩˮ";
				xx+=jjx;
			}else{
				jjr+=rand()%4;
				cout<<jjr<<"����";
				r+=jjr;
			}
		}
	}else if(rand()%3==0){
		int jjjy=13+rand()%9;
		if(rand()%25==0){
			jjjy=25+rand()%15+rand()%7;
		}
		cout<<"�����"<<jjjy<<"�㾭��";
		jy+=jjjy;
	}else{
		int jjjb=350+rand()%200;
		cout<<"�����"<<jjjb<<"�����";
		mony+=jjjb;
	}cout<<endl;
}
void qd(bool &f,int &ts){
	if(tyear>year||tmonth>month||tday>day){
		cout<<"ǩ���ɹ�!"<<endl;
		qds();
		f=1;ts++;jb+=rand()%2;
		cout<<"�ϴ�ǩ��ʱ��Ϊ:";
		if(year==0)cout<<"��";
		else printf("%d��%d��%d��",1900+year,1+month,day);
		year=tyear,month=tmonth,day=tday;
	}else{
		cout<<"������ǩ��\nҪһ��һ����ӡ,��Ҫ�ļ�\n";
		cout<<"�ϴ�ǩ��ʱ��Ϊ:";
		if(year==0)cout<<"��";
		else printf("%d��%d��%d��",1900+year,1+month,day);
	}Sleep(500);cout<<"\n��������˳�";system("pause>nul");
}
void GotoXy(int x,int y){//x��,y�� 
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
    print("��Ѫ֮��1.8.5:\n����:Accteped\n���������ʼ\n�벻Ҫ������������ո�,����Ը�(�ǵõ㱣��)");
    system("pause>nul");
    cw:
    qp();
    v:
    printf("1.�½��浵\n2.���ش浵\n");
    char c=getch();
    qp();
    if(c=='1'){
    	cout<<"0.�˳�";
		char sbs=getch();
		if(sbs=='0'){
			goto cw;
		}qp();
    	jy=0,dj=0;
        qp();jb=5;
        printf("�����������˺���:");
        cin>>name;mony=500;
        printf("��������������:");
        cin>>mm;
        file.open(name.c_str(), ios::out | ios::trunc);
        file<<year<<' '<<month<<' '<<day<<' '<<ts<<' '<<cd<<' '<<dj<<' '<<jy<<' '<<hj<<' '<<name<<' '<<mony<<' '<<xn<<' '<<gc<<' '<<sx<<' '<<gj<<' '<<fy<<' '<<jb<<' '<<xx<<' '<<zx<<' '<<dx<<' '<<r<<' '<<wq<<' '<<mm;
		file.close();
        getch();
    }
    else if(c=='2'){
    	sb:
    	qp();
    	cout<<"0.�˳�";
		char sbs=getch();
		if(sbs=='0'){
			goto cw;
		}qp();
		printf("�����������˺���:");cin>>tzh;
		printf("��������������:");cin>>tmm;
		file.open(tzh.c_str(), ios::in);
		file>>year>>month>>day>>ts>>cd>>dj>>jy>>hj>>name>>mony>>xn>>gc>>sx>>gj>>fy>>jb>>xx>>zx>>dx>>r>>wq>>mm;
		tcd=((((int(xn+gj+fy)%100+(int(xx+zx+dx)*2)%100+(jb+mony*2)%100+(jy+dj)%100)+(day+month*32+year*100+ts*100)%100)%100))<<3;
		if(!file.is_open()){
			cout<<"δ�ҵ��浵"<<endl;
			getch();
			goto sb;
		}
		if(tmm!=mm){
			cout<<"�������"<<endl;
			getch();
			file.close();
			goto sb;
		}
		if(tcd!=cd){
			qp();
			cout<<"������������Ϊ,��¼ʧ��"<<endl;
			system("pause");
			file.close();
			goto cw;
		}
		cout<<"����ɹ�!";
		getch(); 
		file.close();
	}else{
		goto cw;
	}
    if(name=="Accteped"&&c!='2'){
        qp();
        printf("�㾹��ð������!!");
        mony=0;
        getch();
    }
    qp();
    print("��ӭ��:");
    print(name);
   	printf("\n");
	ltm=localtime(&now);
	tday=ltm->tm_mday;
	tyear=ltm->tm_year;
	tmonth=ltm->tm_mon;
	if(tday==11&&tmonth+1==11){
		MessageBox(NULL,TEXT("������˫ʮһ(�д����)"),TEXT("��Ϸ��ʾ"),MB_OK);
		party_11=true;
	}thread save1(save);
    while(1){
    	jsdj();
        qp();
        bool jls=0;
        cout<<name<<"������Ҫ��ʲô\n"<<"�����ڵĵȼ���:"<<dj<<"  ������:"<<jy;
        if(dj>=10)cout<<"��������";
        else cout<<"(����һ������"<<jy1[dj+1]-jy<<')';
        cout<<endl;
        cout<<"1.ս��  2.�̵�  3.��Ѫ  4.״̬  5.��Ҿ���(��ʣ"<<jb<<"��)  6.�ڿ�  7.����\n8.����  0.���°汾����  e.ǩ��  t.������Ϸ  d.�鿴ԭ�ĵ�ַ";
        if(dj>=3){
        	cout<<"  h.����";
			hs=1;
		}
        cout<<endl;
        cs:
        char c=getch();
        switch(c){
        	case 'd':
        		qp();
        		cout<<"��Ȩ����������Ϊ����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӻͱ�������\n�������ӣ�https://blog.csdn.net/Accteped/article/details/109686246\n";
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
                    cout<<"1.����\n0.�˳�\n";
                    char d2=getch();
                    if(d2=='1')goto cw;
                    else if(d2=='0'){
                        qp();
                        cout<<"��ӭ�´�����!";
                        feee=0;
                        break;
                    }
                    else goto shu;
                }
                break;
            
            case '3':hx();break;
            case '4':zt();break;
            case '8':break;
            case '7':js=time(0);if(js-ks>=400){bl();ks=js;}else{qp();cout<<"���ƣ����"<<endl<<"��ʣ"<<400-(js-ks)<<"��\n";getch();qp();};break;
            case '6':qp();js1=time(0);if(js1-ks1>=260){bm();ks1=js1;}else{qp();cout<<"���ƣ����"<<endl<<"��ʣ"<<260-js1+ks1<<"��\n";;getch();qp();};break;
            case '5':jjb(jb);break;
            case '0':rz();break;
            case 't':
				qp();
				cout<<"�Ƿ����(y(��) or �����(��)";
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
            cout<<"����ɹ�!!";
            SetFileAttributes("2.txt",FILE_ATTRIBUTE_HIDDEN);
            Sleep(1000);
        }
    }
}
