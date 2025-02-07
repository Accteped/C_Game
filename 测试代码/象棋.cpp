
#include<stdio.h>
#include<string.h>
#include<windows.h>
//自定义源文件（棋谱结构） 
//棋盘行列 
#define ROWS 10
#define COLS 9
//空地 
#define white 0
//红方棋子 
#define isred (map[i][j]>0&&map[i][j]<10)
#define ju 1
#define ma 2
#define xiang 3
#define shi 4
#define shuai 5
#define pao 6
#define bing 7
//黑方棋子
#define isblack (map[i][j]>10)
#define Ju 11
#define Ma 12
#define Xiang 13
#define Shi 14
#define Jiang 15
#define Pao 16
#define Zu 17 
//控制输出颜色 
#define NONECOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7)
#define REDCOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED)
#define GREENCOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN)
//当前玩家
#define red 1
#define black 0 

//地图 
int map[ROWS][COLS]={white};
//棋步 
char step[20];

//初始化地图 
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
	0车马象士将士象马车
	1
	2  砲          砲
	3卒  卒  卒  卒  卒
	4
	5
	6兵  兵  兵  兵  兵
	7  炮          炮
	8  
	9車馬相仕帥仕相馬車 
*/
	//黑方子力配置 
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
	//红方子力配置
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

//打印地图
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
						printf("車");
						break;
					case Ju:
						printf("车");
						break;
					case ma:
						printf("馬");
						break;
					case Ma:
						printf("马");
						break;
					case xiang:
						printf("相");
						break;
					case Xiang:
						printf("象");
						break;
					case shi:
						printf("仕");
						break;
					case Shi:
						printf("士");
						break;
					case shuai:
						printf("帥");
						break;
					case Jiang:
						printf("將");
						break;
					case pao:
						printf("炮");
						break;
					case Pao:
						printf("砲");
						break;
					case bing:
						printf("兵");
						break;
					case Zu:
						printf("卒");
						break;
				}	
			}
		}	
		NONECOLOR;
		printf("\n");
	}	
	/*
	char border[][3]={"九","八","七","六","五","四","三","二","一"};
	printf("  ");
	for(k=0;k<9;k++)
	{
		printf("%s",border[k]);
	}
	*/
	printf("\n\n"); 
} 

//将（x1,y1）的棋子移动到（x2,y2） 
void movePiece(int x1,int y1,int x2,int y2)
{
	map[x2][y2]=map[x1][y1];
	map[x1][y1]=white;
}

//获取玩家需要移动的棋子位置和移动到的目标位置
int getInput(int *x1,int *y1,int *x2,int *y2)
{
	printf("\n输入棋子坐标和目的坐标（全为-1时表示查看当前棋谱）:\n");
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

//判断是否已经结束游戏（-1：黑胜 0：还没结束 1：红胜） 
int isOver()
{
	int i,j;
	//没有將时红胜，没有帥时黑胜
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

//输出赢家 
void displayWinner(int winner)
{
	if(winner==1)
	{
		printf("红胜！\n");
	}
	else if(winner==-1)
	{
		printf("黑胜！\n");
	}
}

//打印当前回合的玩家
void displayPlayer(int player)
{
	printf("=======");
	if(player==red)
	{
		printf("红方回合"); 
	}
	else if(player==black)
	{
		printf("黑方回合"); 	
	}
	printf("=======");	
} 

//交替到对方回合 
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

//坐标（x1,y1）上的棋子是否能移动到（x2,y2）上 
int canMove(int x1,int y1,int x2,int y2,int player)
{
	//当（x2,y2）为己方棋子时，不可以
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
		//車、车 
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
			//相（象）过河 
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
			//出九宫
			if(player==red&&(x2<7||y2<3||y2>5)||player==black&&(x2>2||y2<3||y2>5))
			{
				return 0;	
			} 
			//不是走的斜一格 
			else if(abs(x1-x2)!=1||abs(y1-y2)!=1)
			{
				return 0;
			}
			break;
		case shuai:
		case Jiang:
			//飞将
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
			//不是横或纵走一格 
			if((abs(x1-x2)+abs(y1-y2))!=1)
			{
				return 0;
			}
			//没过河时便左右移动 
			if(player==red&&x1>=5&&(abs(y1-y2)==1)||player==black&&(x1<=4)&&(abs(y1-y2)==1))
			{
				return 0;
			}
			//往后退 
			else if(player==red&&(x1-x2==-1)||player==black&&(x2-x1==-1))
			{
				return 0;
			}
			break;
	}
	return 1;
} 

//获得棋子名字 
char *getPieceName(int piece)
{
	switch(piece)
	{
		case Ju:
			return "车";
		case ju:
			return "車";
		case Ma:
			return "马";
		case ma:
			return "馬";
		case Xiang:
			return "象";
		case xiang:
			return "相";
		case Shi:
			return "士";
		case shi:
			return "仕";
		case Jiang:
			return "將";
		case shuai:
			return "帥";
		case Pao:
			return "砲";
		case pao:
			return "炮";
		case Zu:
			return "卒";
		case bing:
			return "兵";
	}
	return "";
}

//获得棋步 
void getStep(int x1,int y1,int x2,int y2,int player)
{
	//清空之前棋步 
	step[0]='\0';
	char border_red[][3]={"九","八","七","六","五","四","三","二","一"};
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
		strcat(step,"中");
	}	
	else if(last==1)
	{
		if(player==red)
		{
			strcat(step,"后");
		}
		else
		{
			strcat(step,"前");
		}
	}
	else if(next==1)
	{
		if(player==red)
		{
			strcat(step,"前");
		}
		else
		{
			strcat(step,"后");
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
		strcat(step,"平");
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
				strcat(step,"进");
			}
			else
			{
				strcat(step,"退");
			}
			strcat(step,border_black[abs(distance)-1]);
			break;
		case Ma:
		case Xiang:
		case Shi:
			if(distance>0)
			{
				strcat(step,"进");
			}
			else
			{
				strcat(step,"退");
			}
			strcat(step,border_black[y2]);
			break;
		case ju:
		case shuai:
		case pao:
		case bing:
			if(distance>0)
			{
				strcat(step,"退");
			}
			else
			{
				strcat(step,"进");
			}
			strcat(step,border_red[9-abs(distance)]);
			break;
		case ma:
		case xiang:
		case shi:
			if(distance>0)
			{
				strcat(step,"退");
			}
			else
			{
				strcat(step,"进");
			}
			strcat(step,border_red[y2]);
			break;
	}
}

int main()
{
	InitializeMap();
	//棋谱 
	//初始化棋谱 
	//游戏是否已经结束 
	int isEnd=0;
	//坐标
	int x1,y1,x2,y2; 
	//输入是否合法
	int inputRight; 
	//移动是否成功
	int moveSuccess; 
	//当前玩家
	int player=red; 
	while(!isEnd)
	{
		system("cls");							//清屏
		displayMap();							//打印现在棋局
		displayPlayer(player);					//当前玩家回合 
		inputRight=getInput(&x1,&y1,&x2,&y2);	//接收玩家输入
		if(inputRight)							//输入成功 
		{
												//是否选择己方棋子 
			if(map[x1][y1]>0&&map[x1][y1]<10&&player==red||map[x1][y1]>10&&player==black)
			{
												//是否可以移动 
				moveSuccess=canMove(x1,y1,x2,y2,player);
				if(moveSuccess)					//可以移动 
				{								//按照输入移动棋子 
					getStep(x1,y1,x2,y2,player);
					printf("当前棋步为-->>%s\n",step);//打印当前棋步 
					system("pause");
					movePiece(x1,y1,x2,y2);	
					exchangePlayer(&player);	//移动成功，轮到对方回合							
					isEnd=isOver();				//判断棋局是否已经结束		
				}
			}	
		} 
	}
	system("cls");
	displayMap();								//打印现在棋局
	displayWinner(isEnd);
	return 0;
}


#ifndef manual_c
#define manual_c
#define MAXCOUNT 200
//棋谱结构 
typedef struct manual
{
	int count;
	char step[MAXCOUNT][20];	
}manual;

//初始化棋谱 4
void initializeManual(manual *m)
{
	m->count=0;
}

//打印棋谱 
void displayManual(manual m)
{
	printf("\n");
	if(m.count==0)
	{
		printf("当前棋谱为空！\n");	
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

//添加棋步
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

//删除棋步
void deleteStep(manual *m)
{
	int i=m->count;
	i--;
	m->count=i;	
} 

//保存棋谱 
void saveManual(manual m,char filepath[])
{
	int i;
	FILE *fp=fopen(filepath,"w");
	for(i=0;i<m.count;i++)
	{
		fprintf(fp,"%s\n",m.step[i]);
	}
	fclose(fp);
	printf("\n棋谱保存成功！\n");
}

//读取棋谱
void readManual(manual *m,char filepath[])
{
	int i=0;
	FILE *fp=fopen(filepath,"r");
	if(fp==NULL)
	{
		printf("棋谱文件丢失！\n");
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

