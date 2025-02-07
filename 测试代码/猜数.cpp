#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Menu(){  //打印菜单
	printf("************************\n");
	printf("           1.开始游戏         \n");
	printf("           0.退出游戏         \n");
	printf("************************\n");
	printf("请输入你的选择!");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//计算机产生一个随机整数(1-100)
void Game(){    //void表示没有返回值
	printf("进入游戏!\n");
	int result = rand() % 100 + 1;
	while (1){
		printf("请输入数字!\n");
		int num = 0;
		scanf("%d", &num);
		if (num < result){
			printf("低了!\n");
		}else if (num>result){
			printf("高了!\n");
		}else{
			printf("恭喜你答对了!\n");
			break;
		}
	}
}
int main(){
		//创建一个循环
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}else if (choice == 0){
			printf("游戏退出\n");
			break;  //用户退出,结束循环
		}else{
			printf("输入有误\n");
		}
	}
	system("pause");
	return 0;
}
