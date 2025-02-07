#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int player[20];
int p[20]={0,3,1,4,4,4,4,4,4,4,4,4,4,4};
string c[20]={" ","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int sx[5],putcardsx[4]={1,2,3};//出牌顺序 1:玩家，2:电脑1 3:电脑2 
struct STD{
	int num[20];
}com[4];
void rand_player(){
	for(int i=1;i<=16;++i){
		cs:
		int t=rand()%13+1;
		if(p[t])player[t]++,p[t]--;
		else goto cs;
	}
}
void rand_c(){
	for(int j=1;j<=2;++j){
		for(int i=1;i<=16;++i){
			cs:
			int t=rand()%13+1;
			if(p[t])com[j].num[t]++,p[t]--;
			else goto cs;
		}
	}
}
void put(){
	cout<<"Your cards:\n"; 
	for(int i=3;i<=13;++i){
		for(int j=1;j<=player[i];++j)cout<<c[i]<<' ';
		if(!player[i])continue;
	}
	for(int j=1;j<=player[1];++j)cout<<'A'<<' ';
	for(int j=1;j<=player[2];++j)cout<<'2'<<' ';
	cout<<endl;
}
void cls(){
	system("cls");
}
void computer(string s,int i){
	;
}
bool putcard(string s,int a,int id){
	if(a==1){
		if(s.size()>17)return 0;
		if(s.size()>=5){
			bool f=1;
			for(int i=s.size()-1;i>0;--i){
				if(s[i]=='0'&&s[i-1]=='1'){
					if(!player[10]){
						f=0;
						break;
					}
					if(i-2>=0&&s[i-2]!='9'){
						f=0;
						break;
					}
					i--;
					continue;
				}
				if(s[i]=='2'){
					f=0;
					break;
				}
				if(s[i]<='9'&&s[i]>='3'&&player[s[i]-'0']&&s[i]==s[i-1]+1)continue;
				else if(s[i]=='A'&&player[1]&&s[i-1]=='K')continue;
				else if(s[i]=='J'&&player[11]&&s[i-1]=='0')continue;
				else if(s[i]=='Q'&&player[12]&&s[i-1]=='J')continue;
				else if(s[i]=='K'&&player[13]&&s[i-1]=='Q')continue;
				f=0;
				break;
			}
			if(f){
				for(int i=0;i<s.size();++i){
					if(s[i]=='1'&&player[10])player[10]--,i++;
					else if(s[i]<='9'&&s[i]>='2'&&player[s[i]-'0'])player[s[i]-'0']--;
					else if(s[i]=='A'&&player[1])player[1]--;
					else if(s[i]=='J'&&player[11])player[11]--;
					else if(s[i]=='Q'&&player[12])player[12]--;
					else if(s[i]=='K'&&player[13])player[13]--;
				}
			}
		}
		if(s.size()==1||(s[0]=='1'&&s.size()==2)){
			if(s[0]=='1'&&player[10])player[10]--;
			else if(s[0]<='9'&&s[0]>='2'&&player[s[0]-'0'])player[s[0]-'0']--;
			else if(s[0]=='A'&&player[1])player[1]--;
			else if(s[0]=='J'&&player[11])player[11]--;
			else if(s[0]=='Q'&&player[12])player[12]--;
			else if(s[0]=='K'&&player[13])player[13]--;
		}else if(s.size()==2||(s[0]=='1'&&s.size()==4)){
			if(s[0]=='1'&&s[2]=='1'&&player[10]>=2)player[10]-=2;
			else if(s[0]<='9'&&s[1]==s[0]&&s[0]>='2'&&player[s[0]-'0']>=2)player[s[0]-'0']-=2;
			else if(s[0]=='A'&&s[1]=='A'&&player[1]>=2)player[1]-=2;
			else if(s[0]=='J'&&s[1]=='J'&&player[11]>=2)player[11]-=2;
			else if(s[0]=='Q'&&s[1]=='Q'&&player[12]>=2)player[12]-=2;
			else if(s[0]=='K'&&s[1]=='K'&&player[13]>=2)player[13]-=2;
		}else if((s.size()==4||s.size()==5||s.size()==7||s.size()==8)&&s[0]!=s[3]&&s[2]!=s[3]||s.size()==3||s.size()==6){
			if(s.size()==3||s[0]=='1'){
				if(s[0]=='1'){
					if(player[10]>=3)player[10]-=3;
					return 1;
				}
				if(s[0]!=s[1]||s[1]!=s[2]||s[0]!=s[2]){
					return 0;
				}
				if((s[0]<='9'&&s[0]>='3'&&player[s[0]-'0']<3))return 0;
				else if((s[0]=='A'&&player[1]<3))return 0;
				else if((s[0]=='J'&&player[11]<3))return 0;
				else if((s[0]=='Q'&&player[12]<3))return 0;
				else if((s[0]=='K'&&player[13]<3))return 0;
				if(s[0]<='9'&&s[0]>='2'&&player[s[0]-'0']>=3)player[s[0]-'0']-=3;
				else if(s[0]=='A'&&player[1]>=3)player[1]-=3;
				else if(s[0]=='J'&&player[11]>=3)player[11]-=3;
				else if(s[0]=='Q'&&player[12]>=3)player[12]-=3;
				else if(s[0]=='K'&&player[13]>=3)player[13]-=3;
			}
			else if(s.size()>=4&&s.size()<=5){
				if(s[0]!=s[1]||s[1]!=s[2]||s[0]!=s[2]){
					return 0;
				}
				if(s[0]=='2'){
					return 0;
				}
				if((s[0]<='9'&&s[0]>='3'&&player[s[0]-'0']<3))return 0;
				else if((s[0]=='A'&&player[1]<3))return 0;
				else if((s[0]=='J'&&player[11]<3))return 0;
				else if((s[0]=='Q'&&player[12]<3))return 0;
				else if((s[0]=='K'&&player[13]<3))return 0;
				if((s[3]<='9'&&s[3]>='3'&&!player[s[3]-'0']))return 0;
				else if((s[3]=='A'&&!player[1]))return 0;
				else if((s[3]=='J'&&!player[11]))return 0;
				else if((s[3]=='Q'&&!player[12]))return 0;
				else if((s[3]=='K'&&!player[13]))return 0;
				if(s.size()==5){
					if((s[4]<='9'&&s[4]>='3'&&!player[s[4]-'0']))return 0;
					else if((s[4]=='A'&&!player[1]))return 0;
					else if((s[4]=='J'&&!player[11]))return 0;
					else if((s[4]=='Q'&&!player[12]))return 0;
					else if((s[4]=='K'&&!player[13]))return 0;
				}
				if(s[0]<='9'&&s[0]>='2'&&player[s[0]-'0']>=3)player[s[0]-'0']-=3;
				else if(s[0]=='A'&&player[1]>=3)player[1]-=3;
				else if(s[0]=='J'&&player[11]>=3)player[11]-=3;
				else if(s[0]=='Q'&&player[12]>=3)player[12]-=3;
				else if(s[0]=='K'&&player[13]>=3)player[13]-=3;
				if(s[3]<='9'&&s[3]>='2'&&player[s[3]-'0'])player[s[3]-'0']--;
				else if(s[3]=='A'&&player[1])player[1]--;
				else if(s[3]=='J'&&player[11])player[11]--;
				else if(s[3]=='Q'&&player[12])player[12]--;
				else if(s[3]=='K'&&player[13])player[13]--;
				if(s.size()==5){
					if(s[4]<='9'&&s[4]>='2'&&player[s[4]-'0'])player[s[4]-'0']--;
					else if(s[4]=='A'&&player[1])player[1]--;
					else if(s[4]=='J'&&player[11])player[11]--;
					else if(s[4]=='Q'&&player[12])player[12]--;
					else if(s[4]=='K'&&player[13])player[13]--;
				}
			}else{
				if(s[0]=='1'&&s[2]=='1'&&s[4]=='1'&&s[1]=='0'&&s[3]=='0'&&s[5]=='0'){
					if(player[10]<3)return 0;
					if((s[6]<='9'&&s[6]>='3'&&player[s[6]-'0']))return 0;
					else if((s[6]=='A'&&player[1]))return 0;
					else if((s[6]=='J'&&player[11]))return 0;
					else if((s[6]=='Q'&&player[12]))return 0;
					else if((s[6]=='K'&&player[13]))return 0;
					if(s.size()==8){
						if((s[7]<='9'&&s[7]>='3'&&player[s[7]-'0']))return 0;
						else if((s[7]=='A'&&player[1]))return 0;
						else if((s[7]=='J'&&player[11]))return 0;
						else if((s[7]=='Q'&&player[12]))return 0;
						else if((s[7]=='K'&&player[13]))return 0;
					}
					player[10]-=3;
					if(s[6]<='9'&&s[6]>='2'&&player[s[6]-'0'])player[s[6]-'0']--;
					else if(s[6]=='A'&&player[1])player[1]--;
					else if(s[6]=='J'&&player[11])player[11]--;
					else if(s[6]=='Q'&&player[12])player[12]--;
					else if(s[6]=='K'&&player[13])player[13]--;
					if(s.size()==8){
						if(s[7]<='9'&&s[7]>='2'&&player[s[7]-'0'])player[s[7]-'0']--;
						else if(s[7]=='A'&&player[1])player[1]--;
						else if(s[7]=='J'&&player[11])player[11]--;
						else if(s[7]=='Q'&&player[12])player[12]--;
						else if(s[7]=='K'&&player[13])player[13]--;
					}
				}else{
					if(s[3]=='1'&&s[5]!='1'||s[4]=='1'&&s[3]!='1'){
						if(player[10]){
							if(s[3]=='1'){
								if((s[3]<='9'&&s[3]>='3'&&player[s[3]-'0']))return 0;
								else if((s[3]=='A'&&player[1]))return 0;
								else if((s[3]=='J'&&player[11]))return 0;
								else if((s[3]=='Q'&&player[12]))return 0;
								else if((s[3]=='K'&&player[13]))return 0;
							}
							else{
								if((s[4]<='9'&&s[5]>='3'&&player[s[5]-'0']))return 0;
								else if((s[4]=='A'&&player[1]))return 0;
								else if((s[4]=='J'&&player[11]))return 0;
								else if((s[4]=='Q'&&player[12]))return 0;
								else if((s[4]=='K'&&player[13]))return 0;
							}
						}
					}else if(s[5]=='1'&&s[3]=='1'){
						if(player[10]>1){
							if((s[0]<='9'&&s[0]>='3'&&player[s[0]-'0']<3))return 0;
							else if((s[0]=='A'&&player[1]<3))return 0;
							else if((s[0]=='J'&&player[11]<3))return 0;
							else if((s[0]=='Q'&&player[12]<3))return 0;
							else if((s[0]=='K'&&player[13]<3))return 0;
							if(s[0]<='9'&&s[0]>='2'&&player[s[0]-'0']>=3)player[s[0]-'0']-=3;
							else if(s[0]=='A'&&player[1]>=3)player[1]-=3;
							else if(s[0]=='J'&&player[11]>=3)player[11]-=3;
							else if(s[0]=='Q'&&player[12]>=3)player[12]-=3;
							else if(s[0]=='K'&&player[13]>=3)player[13]-=3;
							player[10]-=2;
						}
					}
				}
			}
		}else if(s.size()>=4&&s.size()<=16&&s.size()%2==0){
			bool f=1;
			for(int i=0;i<s.size();i+=2){
				if(s[i]=='1'&&s[i+1]=='0'){
					if(s[i+2]=='1'&&s[i+3]=='0'&&player[10]>=2){
						i+=2;
						continue;
					}
					f=0;
					break;
				}
				if(s[i]!=s[i+1]){
					f=0;
					break;
				}
				if(s[i]<='9'&&s[i]>='3'&&player[s[i]-'0']>=2)continue;
				else if(s[i]=='A'&&player[1]>=2)continue;
				else if(s[i]=='J'&&player[11]>=2)continue;
				else if(s[i]=='Q'&&player[12]>=2)continue;
				else if(s[i]=='K'&&player[13]>=2)continue;
				f=0;
				break;
			}
			if(f){
				for(int i=0;i<s.size();i+=2){
					if(s[i]=='1'&&player[10]>=2)player[10]-=2;
					else if(s[i]<='9'&&s[i]>='3'&&player[s[i]-'0']>=2)player[s[i]-'0']-=2;
					else if(s[i]=='A'&&player[1]>=2)player[1]-=2;
					else if(s[i]=='J'&&player[11]>=2)player[11]-=2;
					else if(s[i]=='Q'&&player[12]>=2)player[12]-=2;
					else if(s[i]=='K'&&player[13]>=2)player[13]-=2;
				}
			}
		}else if((s.size()==4)&&s[0]==s[1]&&s[0]==s[2]&&s[0]==s[3]&&s[1]==s[2]&&s[1]==s[3]&&s[2]==s[3]){
			if(s[0]<='9'&&s[0]>='2'&&player[s[0]-'0']>=4)player[s[0]-'0']-=4;
			else if(s[0]=='A'&&player[1]>=4)player[1]-=4;
			else if(s[0]=='J'&&player[11]>=4)player[11]-=4;
			else if(s[0]=='Q'&&player[12]>=4)player[12]-=4;
			else if(s[0]=='K'&&player[13]>=4)player[13]-=4;
		}else if((s.size()==8&&s[0]=='1'&&s[1]=='0')){
			player[10]-=4;
		}
	}
	if(a==2){
		
	}
	if(a==3){
		
	}
}
void play(){
	int j=1;
	cs:
		int a=rand()%3+1;
		if(j==4)goto begin;
		if(sx[1]==a||sx[2]==a||sx[3]==a)goto cs;
		else sx[j]=a,j++;
		goto cs;
	begin:
	cout<<"出牌顺序为:"<<endl;
	for(int i=1;i<=3;++i){
		cout<<sx[i];
		cout<<"第"<<i<<"个:";
		if(sx[i]==1){
			cout<<"You";
		}else if(sx[i]==2){
			cout<<"电脑1";
		}else{
			cout<<"电脑2";
		}
		
		cout<<endl;
	}
	system("pause");
	cls(); 
	cout<<"开始!";
	Sleep(1000);
	while(1){
		bool f=1;
		for(int i=1;i<=13;++i)
			if(player[i]){
				f=0;
				break;
			}
		if(f){
			cls();
			cout<<"YOU WIN!";
			system("pause>nul");
			break;
		}
		cls();
		cout<<"你的牌为:"<<endl;
		put();
		for(int i=1;i<=3;++i){
			if(sx[i]==1){
				cout<<"You:";
				string s;
				cin>>s;
				putcard(s,1,putcardsx[i]);
			}else if(sx[i]==2){
				cout<<"电脑1:";
//				putcard(" ",2,i,putcardsx[i]);
				cout<<endl;
			}else{
				cout<<"电脑2:";
//				putcard(" ",3,i,putcardsx[i]);
				cout<<endl;
			}
		}
	}
}
int main(){
	srand(time(0));
	int t=rand()%2;
	if(t)rand_player(),rand_c();
	else rand_c(),rand_player();
	play();
	return 0;
}
