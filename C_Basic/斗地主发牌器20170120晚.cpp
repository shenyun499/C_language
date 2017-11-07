#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void begin(); 
void mix();
void show();
int a[54];
main()
{
	srand((unsigned)time(0));//初始化
	begin();
	mix();
	show();
	getchar();
}
void begin()//函数1 ，定义 
{
	for(int i=0;i<54;i++)//
	a[i]=i;
 } 
void mix()//函数2 ，混牌 
{
	for(int i=0;i<60;i++)
	{
		int c=rand()%54,b=rand()%54,t;
		t=a[c];
		a[c]=a[b];
		a[b]=t;
	 } 
}

void show()//函数3 ,发牌 
{
	char b[4][8]={"黑","红","梅","方"};
	char c[13][3]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	for(int i=0;i<54;i++)
	{
		if(i==0)
		printf("玩家1的手牌为:\n\t     ");
		else if(i==17) 
		printf("\n玩家2的手牌为:\n\t     ");
		else if(i==34) 
		printf("\n玩家3的手牌为:\n\t     ");
		else if(i==51)
		printf("\n地主牌为:\n\t     ");
		if(a[i]==52)
		printf("小王 ");
		else if(a[i]==53)
		printf("大王 ");
		else
		printf("%s%s  ",b[a[i]/13],c[a[i]%13]);
	}
	
}
