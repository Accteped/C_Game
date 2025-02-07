#include <windows.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 20
#define TextWidth 200
#define Time1 1
#define Time2 2
#define times 1
#define NO1 1
#define NO2 2
#define ERROR 0
#define NO 0
#define OK 1
int leng=1;
#define DEFAULT 0;
HDC hdc,hdc1,hdc2;
int xw,yw;
int iGame[MAX][MAX];
POINT point;
enum {Default,Player1,Player2} play;
enum {Stop,Play,Paush} plays;
void Init(HWND hwnd);
void paint(int play,int x,int y);
void chagePlayer();
int Look(int x,int y,int play);
void over(HWND hwnd,int play);
void timechage(HWND hwnd);
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
char szClassName[ ] = "������ -WIN32��";
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil) {
	HWND hwnd;
	MSG messages;
	WNDCLASSEX wincl;
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof (WNDCLASSEX);
	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	if (!RegisterClassEx (&wincl))
		return 0;
	hwnd = CreateWindowEx (
	           1,
	           szClassName,
	           szClassName,
	           WS_OVERLAPPEDWINDOW,
	           CW_USEDEFAULT,
	           CW_USEDEFAULT,
	           800,
	           600,
	           HWND_DESKTOP,
	           NULL,
	           hThisInstance,
	           NULL
	       );
	ShowWindow (hwnd, nFunsterStil);
	while (GetMessage (&messages, NULL, 0, 0)) {
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	return messages.wParam;
}
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	static HPEN hpen,hpen1,hpen2;
	static HBRUSH hbrush,hbrush1,hbrush2;
	int x,y;
	switch (message) { /* handle the messages */
		case WM_KEYDOWN:
			switch (wParam) {
				case VK_F5:
					Init(hwnd);
					Rectangle(hdc,0,0,xw,yw);
					for(x=0; x<MAX; x++)
						for(y=0; y<MAX; y++) {
							Rectangle(hdc,x*xw/MAX,y*yw/MAX,(x+1)*xw/MAX,(y+1)*yw/MAX) ;
							iGame[x][y]=Default;
						}
					SetTimer(hwnd,Time1,times,NULL);
					leng=1;
					plays=Play;
					break;
				case VK_F1:
					break;
				case VK_F2:
					SetTimer(hwnd,Time1,times,NULL);
					leng=1;
					plays=Play;
					break;
				case VK_F3:
					if(plays==Play) {
						KillTimer(hwnd,Time1);
						plays=Paush;
					} else if(plays==Paush) {
						SetTimer(hwnd,Time1,times,NULL);
						plays=Play;
					}
					break;
			}
			break;
		case WM_TIMER:
			switch (wParam) {
				case Time1:
					timechage(hwnd);
					break;
			}
			break;
		case WM_CREATE:
			plays=Stop;
			play=Player1;
			break;
		case WM_SIZE:
			xw=LOWORD(lParam);
			yw=HIWORD(lParam);
			xw-=TextWidth;
			InvalidateRect(hwnd,NULL,TRUE);
			break;
		case WM_LBUTTONDOWN:
//��ȡ��ǰ��bai������
			point.x=LOWORD(lParam);
			point.y=HIWORD(lParam);
//��ʼ���豸DC
			Init(hwnd);
//������껻Ϊ��������
			x=(point.x)/(xw/MAX);
			y=(point.y)/(yw/MAX);
			if(plays==Stop)break;
			if(x<MAX&&y<MAX) {
				if(iGame[x][y]==Default&&plays==Play) { //�жϵ�ǰλ���Ƿ������Ӹ���
					leng=1;
					paint(play,x,y);
					if(Look(x,y,play))
						over(hwnd,play);
					chagePlayer();
				}
			}
			break;
		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);
			Init(hwnd);
			Rectangle(hdc,0,0,xw,yw);
			for(x=0; x<MAX; x++)
				for(y=0; y<MAX; y++) {
					Rectangle(hdc,x*xw/MAX,y*yw/MAX,(x+1)*xw/MAX,(y+1)*yw/MAX) ;
					paint(iGame[x][y],x,y);
				}
			EndPaint(hwnd,&ps);
			break;
		case WM_DESTROY:
			PostQuitMessage (0); /* send a WM_QUIT to the message queue */
			break;
		default: /* for messages that we don't deal with */
			return DefWindowProc (hwnd, message, wParam, lParam);
	}
	return 0;
}
void Init(HWND hwnd) {
	hdc1=GetDC(hwnd);
	hdc2=GetDC(hwnd);
//��ʼ����
	SelectObject(hdc,CreatePen(0,1,RGB(255,0,0)));
	SelectObject(hdc,CreateSolidBrush(RGB(0,0,0)));
//��ʼ���һͼ��
	SelectObject(hdc1,CreatePen(0,1,RGB(0,0,0)));
	SelectObject(hdc1,CreateSolidBrush(RGB(0,255,0)));
//��ʼ��Ҷ�ͼ��
	SelectObject(hdc2,CreatePen(0,1,RGB(0,0,0)));
	SelectObject(hdc2,CreateSolidBrush(RGB(0,0,255)));
	SetBkMode(hdc,0);
	Rectangle(hdc,xw+1,1,xw+30,yw);
	Rectangle(hdc,xw+31,29,xw+200,30);
	TextOut(hdc,xw+80,10,"������",6);
	TextOut(hdc,xw+45,100,"F2 - ��ʼ��Ϸ",13);
	TextOut(hdc,xw+45,120,"F3 - ��ͣ/������Ϸ",18);
	TextOut(hdc,xw+45,140,"F5 -���¿�ʼ��Ϸ",16);
	Rectangle(hdc,xw+31,180,xw+200,181);
	TextOut(hdc,xw+49,189," �����ĵ� ",15);
	TextOut(hdc,xw+45,210,"*������󻯴�����Ϸ",19);
	TextOut(hdc,xw+45,240," 1) �� F2������Ϸ",18);
	TextOut(hdc,xw+45,260," 2) ���������",17);
	TextOut(hdc,xw+30,320,"ע�⣺������Ϊ����ʱ��",22);
}
void timechage(HWND hwnd) {
	if(play==Player1) {
		Rectangle(hdc1,xw+1,leng++,xw+30,yw);
		TextOut(hdc1,xw+33,30,"��ǰ��������Ȩ�����һ",22);
		if(leng>yw) {
			KillTimer(hwnd,Time1);
			MessageBox(NULL,"ʱ�䵽�����һ�����ˣ�","TimeOver",0);
			SendMessage(hwnd,WM_KEYDOWN,VK_F5,NULL);
			KillTimer(hwnd,Time1);
		}
	} else {
		TextOut(hdc2,xw+33,30,"��ǰ��������Ȩ����Ҷ�",22);
		Rectangle(hdc2,xw+1,leng++,xw+30,yw);
		if(leng>yw) {
			KillTimer(hwnd,Time1);
			MessageBox(NULL,"ʱ�䵽����Ҷ������ˣ�","TimeOver",0);
			SendMessage(hwnd,WM_KEYDOWN,VK_F5,NULL);
			KillTimer(hwnd,Time1);
		}
	}
}
void paint(int play,int x,int y) { //������
	switch (play) {
		case Player1:
			if(iGame[x][y]!=Default) ;
			Ellipse(hdc1,x*xw/MAX,y*yw/MAX,(x+1)*xw/MAX,(y+1)*yw/MAX) ;
			iGame[x][y]=Player1;
			break;
		case Player2:
			if(iGame[x][y]!=Default) ;
			Ellipse(hdc2,x*xw/MAX,y*yw/MAX,(x+1)*xw/MAX,(y+1)*yw/MAX) ;
			iGame[x][y]=Player2;
			break;
	}
}
void chagePlayer() { //�ı����
	if(play==Player1) play=Player2;
	else
		play=Player1;
}
int Look(int x,int y,int play) { // ���ģ��
	int i,tempx,tempy;
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempy--,i++);
	if(i>=5) return OK; //���Ϻ˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempy++,i++);
	if(i>=5) return OK; //���º˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempx--,i++);
	if(i>=5) return OK; //����˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempx++,i++);
	if(i>=5) return OK; //���Һ˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempx--,tempy--,i++);
	if(i>=5) return OK; //�����Ϻ˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempx++,tempy--,i++);
	if(i>=5) return OK; //�����Ϻ˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempx--,tempy++,i++);
	if(i>=5) return OK; //�����º˶�
	tempx=x;
	tempy=y;
	for(i=0; i<5&&iGame[tempx][tempy]==play; tempx++,tempy++,i++);
	if(i>=5) return OK; //�����º˶�
	return NO;
}
void over(HWND hwnd,int play) {
	switch(play) {
		case Player1:
			KillTimer(hwnd,Time1);
			MessageBox(hwnd,"��ϲ���һ���ʤ��","ʤ��",0);
			SendMessage(hwnd,WM_KEYDOWN,VK_F5,NULL);
			KillTimer(hwnd,Time1);
			plays=Stop;
			break;
		case Player2:
			KillTimer(hwnd,Time1);
			MessageBox(hwnd,"��ϲ��Ҷ����ʤ��","ʤ��",0);
			SendMessage(hwnd,WM_KEYDOWN,VK_F5,NULL);
			KillTimer(hwnd,Time1);
			plays=Stop;
			break;
	}
}
