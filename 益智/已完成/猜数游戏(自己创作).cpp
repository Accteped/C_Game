#include<bits/stdc++.h>
#include<windows.h>
#include <conio.h>
using namespace std;
string s="二分猜数游戏\n作者:hxx\n",nd;
int jminn=0,pminn=0,nminn=0,csc;
int pc=3;
void sc(string s){
	int sum=s.size();
	for(int i=0;i<sum;++i){
		cout<<s[i];
		Sleep(100);
	}
}
void sleep(){
	cout<<"加载中";	
	for(int i=0;i<3;++i){
		cout<<'.';Sleep(1000);
	}
}
void dd(int a){
	Sleep(a);
}
void qp(){
	system("cls");
} 
int main(){
	system("mode con cols=42 lines=10");
	keybd_event(VK_CONTROL, (BYTE) 0, 0, 0);
	keybd_event(VK_SPACE, (BYTE) 0, 0, 0);
	keybd_event(VK_SPACE, (BYTE) 0, 0, 0);
	keybd_event(VK_CONTROL, (BYTE)0, KEYEVENTF_KEYUP, 0);
	srand(time(0));
	sc(s); 
	cout<<"按k键开始";
	a:
	char c=_getch();
	if(c!='k')goto a;
	qp();
	sleep();
	qp();
	cout<<"程序加载完成!";
	dd(1000);
	cw:
	qp(); 
	sr:
	cout<<"请输入范围(格式:a 100<=范围<=10000)"<<endl;
	int a;
	cin>>a;
	if(a>=1000){
		pc=100;csc=8;
	}
	if(a<200&&a>=150){
		pc=5;csc=6;
	}
	if(a>200&&a<1000){
		pc=10;csc=7;
	}
	if(a>=100&&a<150){
		pc=4;csc=6;
	}
	if(a<100||a>10000){
		qp();
		cout<<"输入错误!";
		dd(1000); 
		qp();
		goto sr;
	}
	int ans=rand()%a+1,dans,cs;
	z:
	qp();
	cout<<"1.简单("<<csc<<"次)\n2.普通("<<csc-1<<"次)\n3.困难("<<csc-2<<"次)\n0.重玩\n";
	char d=_getch();
	switch(d){
		case '1':cs=csc;nd="简单";break;
		case '2':cs=csc-1;nd="普通";break;
		case '3':cs=csc-2;nd="困难";break;
		case '0':goto cw;break;
		default:cout<<"输入错误!";goto z;
	}qp();
	bool sl=0;
	int first=1;
	while(cs>0){
		cout<<nd<<":\n开始猜数(范围"<<first<<"~"<<a<<",偏差"<<pc<<")\n";
		cout<<"次数剩余:"<<cs<<endl;
		cin>>dans;
		cout<<"你猜的数是:"<<dans;
		if(abs(dans-ans)<=pc||dans==ans){
			sl=1;
			break;
		}else if(dans<ans){
			cout<<"猜错了\n小了";
			if(first<dans)first=dans;
			dd(2000);
		}else if(dans>ans){
			if(a>dans)a=dans;
			cout<<"猜错了\n大了";
			dd(2000);
		}qp();cs--;
	}
	qp();
	if(sl){
		system("color 18");
		cout<<"恭喜你答对了!\n机器人猜的数是"<<ans<<"\n你的得分:"<<cs;
		if(cs>jminn&&nd=="简单"){
			jminn=cs;
		}
		if(cs>pminn&&nd=="普通"){
			pminn=cs;
		}
		if(cs>nminn&&nd=="困难"){
			nminn=cs;
		}
		if(nd=="简单")cout<<nd<<"\n最高得分:"<<jminn;
		if(nd=="普通")cout<<nd<<"\n最高得分:"<<pminn;
		if(nd=="困难")cout<<nd<<"\n最高得分:"<<nminn;
		cout<<"\n按c重玩 按0退出";
		ssr:
		char t=getch();
		if(t=='c'){
			system("color 0f");
			goto cw;	
		}
		if(t=='0'){
			system("color 0f");
			qp();
			cout<<"欢迎下次再来!"; 
			Sleep(2000);
			system("pause>nul");
			exit(0);
		}else{
			goto ssr;
		}
	}
	cout<<"失败!机器人猜的数是:"<<ans<<"\n次数已用完!\n0.重玩\n1.退出\n"; 
	Sleep(2000);
	char b=getch();
	if(b=='0')goto cw;
	if(b=='1') {
		qp();
		cout<<"欢迎下次再来!"; 
		system("pause>nul");
		exit(0);
	}
	cout<<ans;
}
