#include<bits/stdc++.h>
#include<windows.h>
#include <conio.h>
using namespace std;
string s="���ֲ�����Ϸ\n����:hxx\n",nd;
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
	cout<<"������";	
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
	cout<<"��k����ʼ";
	a:
	char c=_getch();
	if(c!='k')goto a;
	qp();
	sleep();
	qp();
	cout<<"����������!";
	dd(1000);
	cw:
	qp(); 
	sr:
	cout<<"�����뷶Χ(��ʽ:a 100<=��Χ<=10000)"<<endl;
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
		cout<<"�������!";
		dd(1000); 
		qp();
		goto sr;
	}
	int ans=rand()%a+1,dans,cs;
	z:
	qp();
	cout<<"1.��("<<csc<<"��)\n2.��ͨ("<<csc-1<<"��)\n3.����("<<csc-2<<"��)\n0.����\n";
	char d=_getch();
	switch(d){
		case '1':cs=csc;nd="��";break;
		case '2':cs=csc-1;nd="��ͨ";break;
		case '3':cs=csc-2;nd="����";break;
		case '0':goto cw;break;
		default:cout<<"�������!";goto z;
	}qp();
	bool sl=0;
	int first=1;
	while(cs>0){
		cout<<nd<<":\n��ʼ����(��Χ"<<first<<"~"<<a<<",ƫ��"<<pc<<")\n";
		cout<<"����ʣ��:"<<cs<<endl;
		cin>>dans;
		cout<<"��µ�����:"<<dans;
		if(abs(dans-ans)<=pc||dans==ans){
			sl=1;
			break;
		}else if(dans<ans){
			cout<<"�´���\nС��";
			if(first<dans)first=dans;
			dd(2000);
		}else if(dans>ans){
			if(a>dans)a=dans;
			cout<<"�´���\n����";
			dd(2000);
		}qp();cs--;
	}
	qp();
	if(sl){
		system("color 18");
		cout<<"��ϲ������!\n�����˲µ�����"<<ans<<"\n��ĵ÷�:"<<cs;
		if(cs>jminn&&nd=="��"){
			jminn=cs;
		}
		if(cs>pminn&&nd=="��ͨ"){
			pminn=cs;
		}
		if(cs>nminn&&nd=="����"){
			nminn=cs;
		}
		if(nd=="��")cout<<nd<<"\n��ߵ÷�:"<<jminn;
		if(nd=="��ͨ")cout<<nd<<"\n��ߵ÷�:"<<pminn;
		if(nd=="����")cout<<nd<<"\n��ߵ÷�:"<<nminn;
		cout<<"\n��c���� ��0�˳�";
		ssr:
		char t=getch();
		if(t=='c'){
			system("color 0f");
			goto cw;	
		}
		if(t=='0'){
			system("color 0f");
			qp();
			cout<<"��ӭ�´�����!"; 
			Sleep(2000);
			system("pause>nul");
			exit(0);
		}else{
			goto ssr;
		}
	}
	cout<<"ʧ��!�����˲µ�����:"<<ans<<"\n����������!\n0.����\n1.�˳�\n"; 
	Sleep(2000);
	char b=getch();
	if(b=='0')goto cw;
	if(b=='1') {
		qp();
		cout<<"��ӭ�´�����!"; 
		system("pause>nul");
		exit(0);
	}
	cout<<ans;
}
