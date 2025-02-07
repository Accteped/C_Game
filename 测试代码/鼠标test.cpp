//我写的一个简单地例子
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD mouseRec;
	DWORD res;

	while(1)
	{
		ReadConsoleInput(hIn, &mouseRec, 1, &res);//读取一个鼠标操作
		if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)//如果点击了左键
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)//如果是双击
			{
				break;	//退出循环
			}
			else//单击的情况
			{
				cout<<mouseRec.Event.MouseEvent.dwMousePosition.X<<" "<<mouseRec.Event.MouseEvent.dwMousePosition.Y<<endl;//输出当前鼠标的位置
			}
		}
	}
	CloseHandle(hOut);  // 关闭标准输出设备句柄  
	CloseHandle(hIn);   // 关闭标准输入设备句柄  
}

