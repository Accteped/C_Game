
#include<stdio.h>
#include<string.h>
#include<windows.h>
//�Զ���Դ�ļ������׽ṹ�� 
//�������� 
#define ROWS 10
#define COLS 9
//�յ� 
#define white 0
//�췽���� 
#define isred (map[i][j]>0&&map[i][j]<10)
#define ju 1
#define ma 2
#define xiang 3
#define shi 4
#define shuai 5
#define pao 6
#define bing 7
//�ڷ�����
#define isblack (map[i][j]>10)
#define Ju 11
#define Ma 12
#define Xiang 13
#define Shi 14
#define Jiang 15
#define Pao 16
#define Zu 17 
//���������ɫ 
#define NONECOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7)
#define REDCOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED)
#define GREENCOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN)
//��ǰ���
#define red 1
#define black 0 

//��ͼ 
int map[ROWS][COLS]={white};
//�岽 
char step[20];

//��ʼ����ͼ 
void InitializeMap()
{
	int i,j;
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			map[i][j]=white;
		}
	}
	
/*
      0 1 2 3 4 5 6 7 8
	0������ʿ��ʿ����
	1
	2  �h          �h
	3��  ��  ��  ��  ��
	4
	5
	6��  ��  ��  ��  ��
	7  ��          ��
	8  
	9܇�R���ˎ������R܇ 
*/
	//�ڷ��������� 
	map[0][0]=Ju;
	map[0][1]=Ma;
	map[0][2]=Xiang;
	map[0][3]=Shi;
	map[0][4]=Jiang;
	map[0][5]=Shi;
	map[0][6]=Xiang;
	map[0][7]=Ma;
	map[0][8]=Ju;
	map[2][1]=Pao;
	map[2][7]=Pao;
	map[3][0]=Zu;
	map[3][2]=Zu;
	map[3][4]=Zu;
	map[3][6]=Zu;
	map[3][8]=Zu;
	//�췽��������
	map[6][0]=bing;
	map[6][2]=bing;
	map[6][4]=bing;
	map[6][6]=bing;
	map[6][8]=bing; 
	map[7][1]=pao;
	map[7][7]=pao;
	map[9][0]=ju;
	map[9][1]=ma;
	map[9][2]=xiang;
	map[9][3]=shi;
	map[9][4]=shuai;
	map[9][5]=shi;
	map[9][6]=xiang;
	map[9][7]=ma;
	map[9][8]=ju;
}

//��ӡ��ͼ
void displayMap()
{
	int i,j,k;
	printf(" ");
	for(k=0;k<COLS;k++)
	{
		printf(" %d",k);
	}
	printf("\n");
	for(i=0;i<ROWS;i++)
	{
		printf("%d ",i);
		for(j=0;j<COLS;j++)
		{
			if(map[i][j]==white)
			{
				NONECOLOR;
				printf("  ");
			}
			else
			{
				if(isred)
				{
					REDCOLOR;
				}
				else if(isblack)
				{
					GREENCOLOR;
				}
				switch(map[i][j])
				{
					case ju:
						printf("܇");
						break;
					case Ju:
						printf("��");
						break;
					case ma:
						printf("�R");
						break;
					case Ma:
						printf("��");
						break;
					case xiang:
						printf("��");
						break;
					case Xiang:
						printf("��");
						break;
					case shi:
						printf("��");
						break;
					case Shi:
						printf("ʿ");
						break;
					case shuai:
						printf("��");
						break;
					case Jiang:
						printf("��");
						break;
					case pao:
						printf("��");
						break;
					case Pao:
						printf("�h");
						break;
					case bing:
						printf("��");
						break;
					case Zu:
						printf("��");
						break;
				}	
			}
		}	
		NONECOLOR;
		printf("\n");
	}	
	/*
	char border[][3]={"��","��","��","��","��","��","��","��","һ"};
	printf("  ");
	for(k=0;k<9;k++)
	{
		printf("%s",border[k]);
	}
	*/
	printf("\n\n"); 
} 

//����x1,y1���������ƶ�����x2,y2�� 
void movePiece(int x1,int y1,int x2,int y2)
{
	map[x2][y2]=map[x1][y1];
	map[x1][y1]=white;
}

//��ȡ�����Ҫ�ƶ�������λ�ú��ƶ�����Ŀ��λ��
int getInput(int *x1,int *y1,int *x2,int *y2)
{
	printf("\n�������������Ŀ�����꣨ȫΪ-1ʱ��ʾ�鿴��ǰ���ף�:\n");
	scanf("%d %d %d %d",x1,y1,x2,y2);
	if((*x1)<0||(*x1)>ROWS||(*y1)<0||(*y1)>COLS||(*x2)<0||(*x2)>ROWS||(*y2<0)||(*y2)>COLS)
	{
		return 0;
	}
	else if((*x1)==(*x2)&&(*y1)==(*y2))
	{
		return 0;
	}
	return 1;
} 

//�ж��Ƿ��Ѿ�������Ϸ��-1����ʤ 0����û���� 1����ʤ�� 
int isOver()
{
	int i,j;
	//û�Ќ�ʱ��ʤ��û�Ў�ʱ��ʤ
	int haveShuai=0,haveJiang=0;
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			if(map[i][j]==shuai)
			{
				haveShuai=1;		
			}	
			else if(map[i][j]==Jiang)
			{
				haveJiang=1;
			}
		}	
	}	
	if(haveShuai==0)
	{
		return -1;
	}
	else if(haveJiang==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 

//���Ӯ�� 
void displayWinner(int winner)
{
	if(winner==1)
	{
		printf("��ʤ��\n");
	}
	else if(winner==-1)
	{
		printf("��ʤ��\n");
	}
}

//��ӡ��ǰ�غϵ����
void displayPlayer(int player)
{
	printf("=======");
	if(player==red)
	{
		printf("�췽�غ�"); 
	}
	else if(player==black)
	{
		printf("�ڷ��غ�"); 	
	}
	printf("=======");	
} 

//���浽�Է��غ� 
void exchangePlayer(int *player)
{
	if((*player)==red)
	{
		*player=black;
	}
	else if((*player)==black)
	{
		*player=red;
	}
}

//���꣨x1,y1���ϵ������Ƿ����ƶ�����x2,y2���� 
int canMove(int x1,int y1,int x2,int y2,int player)
{
	//����x2,y2��Ϊ��������ʱ��������
	if(map[x2][y2]>0&&map[x2][y2]<10&&player==red||map[x2][y2]>10&&player==black)
	{
		return 0;	
	} 
	int piece=map[x1][y1];
	int i,j;
	int start,end;
	int eye_x=-1,eye_y=-1;
	int count=0;
	switch(piece)
	{
		//܇���� 
		case ju:
		case Ju:
			if(x1==x2)
			{
				start=y1;
				end=y2;
				i=x1;
				if(y1>y2)
				{
					start=y2;
					end=y1;
				}
				for(j=start+1;j<end;j++)
				{
					if(map[i][j]!=white)
					{
						return 0;
					}
				}
			}
			else if(y1==y2)
			{
				start=x1;
				end=x2;
				j=y1;
				if(x1>x2)
				{
					start=x2;
					end=x1;
				}
				for(i=start+1;i<end;i++)
				{
					if(map[i][j]!=white)
					{
						return 0;
					}
				}
			}
			else
			{
				return 0;
			}
			break;
		case ma:
		case Ma:
			if(abs(x1-x2)==1&&y1-y2==2)
			{
				eye_x=x1;
				eye_y=y1-1;
			}
			else if(abs(x1-x2)==1&&y1-y2==-2)
			{
				eye_x=x1;
				eye_y=y1+1;
			}
			else if(abs(y1-y2)==1&&x1-x2==2)
			{
				eye_x=x1-1;
				eye_y=y1;
			}
			else if(abs(y1-y2)==1&&x1-x2==-2)
			{
				eye_x=x1+1;
				eye_y=y1;
			}
			if(eye_x==-1&&eye_y==-1)
			{
				return 0;
			}
			else if(map[eye_x][eye_y]!=white)
			{
				return 0;
			}
			break;
		case xiang:
		case Xiang:
			//�ࣨ�󣩹��� 
			if((player==red&&x2<5)||(player==black&&x2>4)) 
			{
				return 0;
			}
			else if(abs(x1-x2)==2&&abs(y1-y2)==2)
			{
				eye_x=(x1+x2)/2;
				eye_y=(y1+y2)/2;
				if(map[eye_x][eye_y]!=white)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case shi:
		case Shi:
			//���Ź�
			if(player==red&&(x2<7||y2<3||y2>5)||player==black&&(x2>2||y2<3||y2>5))
			{
				return 0;	
			} 
			//�����ߵ�бһ�� 
			else if(abs(x1-x2)!=1||abs(y1-y2)!=1)
			{
				return 0;
			}
			break;
		case shuai:
		case Jiang:
			//�ɽ�
			if((player==red&&x2<3||player==black&&x2>6)&&y1==y2)
			{
				start=x1;
				end=x2;
				j=y1;
				if(x1>x2)
				{
					start=x2;
					end=x1;	
				}	
				for(i=start+1;i<end;i++)
				{
					if(map[i][j]!=white)
					{
						return 0;
					}
				}
			} 
			else if(y2<3||y2>5||player==red&&x2<7||player==black&&x2>2||abs(x1-x2)+abs(y1-y2)!=1)
			{
				return 0;
			}
			break;
		case pao:
		case Pao:
			if(x1==x2)
			{
				start=y1;
				end=y2;
				i=x1;
				if(y1>y2)
				{
					start=y2;
					end=y1;
				}
				for(j=start+1;j<end;j++)
				{
					if(map[i][j]!=white)
					{
						count++;
					}
				}
				if(count>1)
				{
					return 0;
				}
				else if(count==1)
				{
					if(map[x2][y2]>10&&player==red||map[x2][y2]>0&&map[x2][y2]<10&&player==black)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
			else if(y1==y2)
			{
				start=x1;
				end=x2;
				j=y1;
				if(x1>x2)
				{
					start=x2;
					end=x1;
				}
				for(i=start+1;i<end;i++)
				{
					if(map[i][j]!=white)
					{
						count++;
					}
				}
				if(count>1)
				{
					return 0;
				}
				else if(count==1)
				{
					if(map[x2][y2]>10&&player==red||map[x2][y2]>0&&map[x2][y2]<10&&player==black)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
			else
			{
				return 0;
			}
			break;
		case bing:
		case Zu:
			//���Ǻ������һ�� 
			if((abs(x1-x2)+abs(y1-y2))!=1)
			{
				return 0;
			}
			//û����ʱ�������ƶ� 
			if(player==red&&x1>=5&&(abs(y1-y2)==1)||player==black&&(x1<=4)&&(abs(y1-y2)==1))
			{
				return 0;
			}
			//������ 
			else if(player==red&&(x1-x2==-1)||player==black&&(x2-x1==-1))
			{
				return 0;
			}
			break;
	}
	return 1;
} 

//����������� 
char *getPieceName(int piece)
{
	switch(piece)
	{
		case Ju:
			return "��";
		case ju:
			return "܇";
		case Ma:
			return "��";
		case ma:
			return "�R";
		case Xiang:
			return "��";
		case xiang:
			return "��";
		case Shi:
			return "ʿ";
		case shi:
			return "��";
		case Jiang:
			return "��";
		case shuai:
			return "��";
		case Pao:
			return "�h";
		case pao:
			return "��";
		case Zu:
			return "��";
		case bing:
			return "��";
	}
	return "";
}

//����岽 
void getStep(int x1,int y1,int x2,int y2,int player)
{
	//���֮ǰ�岽 
	step[0]='\0';
	char border_red[][3]={"��","��","��","��","��","��","��","��","һ"};
	char border_black[][3]={"1","2","3","4","5","6","7","8","9"};
	int i,j;
	int piece=map[x1][y1];
	int last=0,next=0;
	j=y1;
	for(i=0;i<x1;i++)
	{
		if(map[i][j]==piece)
		{
			last=1;
			break;
		}
	}
	for(i=x1+1;i<ROWS;i++)
	{
		if(map[i][j]==piece)
		{
			next=1;
			break;
		}
	}
	if(last==1&&next==1)
	{
		strcat(step,"��");
	}	
	else if(last==1)
	{
		if(player==red)
		{
			strcat(step,"��");
		}
		else
		{
			strcat(step,"ǰ");
		}
	}
	else if(next==1)
	{
		if(player==red)
		{
			strcat(step,"ǰ");
		}
		else
		{
			strcat(step,"��");
		}
	}
	strcat(step,getPieceName(map[x1][y1]));
	if(last==0&&next==0)
	{
		if(player==red)
		{
			strcat(step,border_red[y1]);
		}
		else
		{
			strcat(step,border_black[y1]);	
		}
	}
	if(x1==x2)
	{
		strcat(step,"ƽ");
		if(player==red)
		{
			strcat(step,border_red[y2]);
		}
		else
		{
			strcat(step,border_black[y2]);	
		}
		return;
	}
	int distance=x2-x1;
	switch(map[x1][y1])
	{
		case Ju:
		case Jiang:
		case Pao:
		case Zu:
			if(distance>0)
			{
				strcat(step,"��");
			}
			else
			{
				strcat(step,"��");
			}
			strcat(step,border_black[abs(distance)-1]);
			break;
		case Ma:
		case Xiang:
		case Shi:
			if(distance>0)
			{
				strcat(step,"��");
			}
			else
			{
				strcat(step,"��");
			}
			strcat(step,border_black[y2]);
			break;
		case ju:
		case shuai:
		case pao:
		case bing:
			if(distance>0)
			{
				strcat(step,"��");
			}
			else
			{
				strcat(step,"��");
			}
			strcat(step,border_red[9-abs(distance)]);
			break;
		case ma:
		case xiang:
		case shi:
			if(distance>0)
			{
				strcat(step,"��");
			}
			else
			{
				strcat(step,"��");
			}
			strcat(step,border_red[y2]);
			break;
	}
}

int main()
{
	InitializeMap();
	//���� 
	//��ʼ������ 
	//��Ϸ�Ƿ��Ѿ����� 
	int isEnd=0;
	//����
	int x1,y1,x2,y2; 
	//�����Ƿ�Ϸ�
	int inputRight; 
	//�ƶ��Ƿ�ɹ�
	int moveSuccess; 
	//��ǰ���
	int player=red; 
	while(!isEnd)
	{
		system("cls");							//����
		displayMap();							//��ӡ�������
		displayPlayer(player);					//��ǰ��һغ� 
		inputRight=getInput(&x1,&y1,&x2,&y2);	//�����������
		if(inputRight)							//����ɹ� 
		{
												//�Ƿ�ѡ�񼺷����� 
			if(map[x1][y1]>0&&map[x1][y1]<10&&player==red||map[x1][y1]>10&&player==black)
			{
												//�Ƿ�����ƶ� 
				moveSuccess=canMove(x1,y1,x2,y2,player);
				if(moveSuccess)					//�����ƶ� 
				{								//���������ƶ����� 
					getStep(x1,y1,x2,y2,player);
					printf("��ǰ�岽Ϊ-->>%s\n",step);//��ӡ��ǰ�岽 
					system("pause");
					movePiece(x1,y1,x2,y2);	
					exchangePlayer(&player);	//�ƶ��ɹ����ֵ��Է��غ�							
					isEnd=isOver();				//�ж�����Ƿ��Ѿ�����		
				}
			}	
		} 
	}
	system("cls");
	displayMap();								//��ӡ�������
	displayWinner(isEnd);
	return 0;
}


#ifndef manual_c
#define manual_c
#define MAXCOUNT 200
//���׽ṹ 
typedef struct manual
{
	int count;
	char step[MAXCOUNT][20];	
}manual;

//��ʼ������ 4
void initializeManual(manual *m)
{
	m->count=0;
}

//��ӡ���� 
void displayManual(manual m)
{
	printf("\n");
	if(m.count==0)
	{
		printf("��ǰ����Ϊ�գ�\n");	
	} 
	int i;
	for(i=0;i<m.count;i++)
	{
		if(i%2==0)
		{
			printf("%d-->>",i/2+1);
		}
		printf("%s  ",m.step[i]);
		if(i%2==1)
		{
			printf("\n");
		}
	}
	printf("\n");
	system("pause"); 
}

//����岽
void insertStep(char step[],manual *m)
{
	if(m->count>=MAXCOUNT)
	{
		return;
	}
	int i=m->count;
	strcpy(m->step[i],step);
	i++;
	m->count=i;	
} 

//ɾ���岽
void deleteStep(manual *m)
{
	int i=m->count;
	i--;
	m->count=i;	
} 

//�������� 
void saveManual(manual m,char filepath[])
{
	int i;
	FILE *fp=fopen(filepath,"w");
	for(i=0;i<m.count;i++)
	{
		fprintf(fp,"%s\n",m.step[i]);
	}
	fclose(fp);
	printf("\n���ױ���ɹ���\n");
}

//��ȡ����
void readManual(manual *m,char filepath[])
{
	int i=0;
	FILE *fp=fopen(filepath,"r");
	if(fp==NULL)
	{
		printf("�����ļ���ʧ��\n");
		return;
	}
	while(1)
	{
		if(fscanf(fp,"%s",m->step[i])==EOF)
		{
			break;
		}
		i++;
	}
	m->count=i;
	fclose(fp);	
} 
#endif

