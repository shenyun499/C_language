#include<stdio.h>
#include<string.h>
#include"symbol.h"
/*
 ����:ʵ�ָ�������������
 */ 
main()
{
	float a1,a2,b1,b2;							//a1��a2�ֱ���ʵ����b1��b2�ֱ����鲿
	int temp;
	char sign[5]="yes";									//��� 
	printf("��ֱ������һ��������ʵ�����鲿:");
	scanf("%f%f",&a1,&b1);
	printf("��ֱ�����ڶ���������ʵ�����鲿:");
	scanf("%f%f",&a2,&b2);
	printf("��ѡ����Ҫ�ĸ�������:\n");
	printf("1���ӷ�����\t\t2����������\t\t3���˷�����\t\t4����������\n");
	scanf("%d",&temp);
	while(strcmp(sign,"yes")==0)
	{
		switch(temp)
		{
			case 1:
			add(a1,b1,a2,b2);
			break;
		case 2:
			minus(a1,b1,a2,b2);
			break;
		case 3:
			plus(a1,b1,a2,b2);
			break;
		case 4:
			multiply(a1,b1,a2,b2);
			break;
		}
		printf("\n��������������:yes �����˳���\n");
		scanf("%s",sign);
		if(strcmp(sign,"yes")==0)
		{
			printf("��ѡ����Ҫ�ĸ�������:\n");
			printf("1���ӷ�����\t\t2����������\t\t3���˷�����\t\t4����������\n");
			scanf("%d",&temp);
		}		
	}
}
