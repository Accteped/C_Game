//��д��һ���򵥵�����
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
		ReadConsoleInput(hIn, &mouseRec, 1, &res);//��ȡһ��������
		if(mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)//�����������
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)//�����˫��
			{
				break;	//�˳�ѭ��
			}
			else//���������
			{
				cout<<mouseRec.Event.MouseEvent.dwMousePosition.X<<" "<<mouseRec.Event.MouseEvent.dwMousePosition.Y<<endl;//�����ǰ����λ��
			}
		}
	}
	CloseHandle(hOut);  // �رձ�׼����豸���  
	CloseHandle(hIn);   // �رձ�׼�����豸���  
}

