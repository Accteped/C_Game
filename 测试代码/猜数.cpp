#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Menu(){  //��ӡ�˵�
	printf("************************\n");
	printf("           1.��ʼ��Ϸ         \n");
	printf("           0.�˳���Ϸ         \n");
	printf("************************\n");
	printf("���������ѡ��!");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//���������һ���������(1-100)
void Game(){    //void��ʾû�з���ֵ
	printf("������Ϸ!\n");
	int result = rand() % 100 + 1;
	while (1){
		printf("����������!\n");
		int num = 0;
		scanf("%d", &num);
		if (num < result){
			printf("����!\n");
		}else if (num>result){
			printf("����!\n");
		}else{
			printf("��ϲ������!\n");
			break;
		}
	}
}
int main(){
		//����һ��ѭ��
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}else if (choice == 0){
			printf("��Ϸ�˳�\n");
			break;  //�û��˳�,����ѭ��
		}else{
			printf("��������\n");
		}
	}
	system("pause");
	return 0;
}
