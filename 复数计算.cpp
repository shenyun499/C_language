#include<stdio.h>
#include<string.h>
#include"symbol.h"
/*
 作用:实现复数的四则运算
 */ 
main()
{
	float a1,a2,b1,b2;							//a1、a2分别是实部，b1、b2分别是虚部
	int temp;
	char sign[5]="yes";									//标记 
	printf("请分别输入第一个复数的实部、虚部:");
	scanf("%f%f",&a1,&b1);
	printf("请分别输入第二个复数的实部、虚部:");
	scanf("%f%f",&a2,&b2);
	printf("请选择需要的复数运算:\n");
	printf("1、加法运算\t\t2、减法运算\t\t3、乘法运算\t\t4、除法运算\n");
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
		printf("\n继续运算请输入:yes 否则退出！\n");
		scanf("%s",sign);
		if(strcmp(sign,"yes")==0)
		{
			printf("请选择需要的复数运算:\n");
			printf("1、加法运算\t\t2、减法运算\t\t3、乘法运算\t\t4、除法运算\n");
			scanf("%d",&temp);
		}		
	}
}
