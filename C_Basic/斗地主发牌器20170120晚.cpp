#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void begin(); 
void mix();
void show();
int a[54];
main()
{
	srand((unsigned)time(0));//��ʼ��
	begin();
	mix();
	show();
	getchar();
}
void begin()//����1 ������ 
{
	for(int i=0;i<54;i++)//
	a[i]=i;
 } 
void mix()//����2 ������ 
{
	for(int i=0;i<60;i++)
	{
		int c=rand()%54,b=rand()%54,t;
		t=a[c];
		a[c]=a[b];
		a[b]=t;
	 } 
}

void show()//����3 ,���� 
{
	char b[4][8]={"��","��","÷","��"};
	char c[13][3]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	for(int i=0;i<54;i++)
	{
		if(i==0)
		printf("���1������Ϊ:\n\t     ");
		else if(i==17) 
		printf("\n���2������Ϊ:\n\t     ");
		else if(i==34) 
		printf("\n���3������Ϊ:\n\t     ");
		else if(i==51)
		printf("\n������Ϊ:\n\t     ");
		if(a[i]==52)
		printf("С�� ");
		else if(a[i]==53)
		printf("���� ");
		else
		printf("%s%s  ",b[a[i]/13],c[a[i]%13]);
	}
	
}
