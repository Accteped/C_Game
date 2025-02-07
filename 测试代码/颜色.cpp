#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define R  SetConsoleTextAttribute(hStdOutHandle, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define G  SetConsoleTextAttribute(hStdOutHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define P  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
void Color(int a){
    if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
}
int main(){
	cout << "Yellow  " << flush;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY );
    cout << "Yellow  " << endl;
 
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
//                            BACKGROUND_GREEN |
//                            BACKGROUND_BLUE); 

//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED |BACKGROUND_GREEN |BACKGROUND_INTENSITY);cout<<1223<<flush;
//	Color(0);cout<<12234;
//	for(int i=0;i<5;++i){
//		Color(i);
//		cout<<'.'<<endl;
//	}Color(0);cout<<12234;
}

