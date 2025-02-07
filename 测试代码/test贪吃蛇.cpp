#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	system("cls");
    for (int i = 0; i < GameSetting::window_width; i++)        cout << "#";
    cout << endl;
    for (int i = 0; i < GameSetting::window_height-2; i++)
    {
        for (int j = 0; j < GameSetting::window_width; j++)
        {
            if (i == 13 && j >= GameSetting::window_width - 29)
            {
                cout << "#";
                continue;
            }
            if (j == 0 || j == GameSetting::window_width - 29 || j == GameSetting::window_width-1)
            {
                cout << "#";
           }
           else
               cout << " ";

       }
       cout << endl;
    }
    for (int i = 0; i < GameSetting::window_width; i++)
        cout << "#";
}

