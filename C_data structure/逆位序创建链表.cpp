#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
//分别用来记录是否成功进行删除、插入
char sign1='1',sign2='1';
typedef struct data1
{
	int data;
	struct data1 *next;
 } Lianbiao;
 Lianbiao *create(Lianbiao *h)
 {
 	printf("请输入需要创建的链表元素，以0结束\n");
 	h=(Lianbiao*)malloc(sizeof(int));				/*带有头结点*/
 	h->next=NULL;
 	h->data=0;
 	//p用来申请空间，temp分别用来记录 p之前的结点 
 	Lianbiao *p;
 	p=(Lianbiao*)malloc(sizeof(int));				/*申请内存空间*/
 	if(p)											/*判断p是否为空*/
 	{
 		scanf("%d",&p->data);
		 p->next=NULL; 
	 }
	 while(p->data!=0)								/*输入0结束创建*/
	 {
	 	if(h->next==NULL)
	 		{
	 			h->next=p;
	 			h->data++;
			 }
	 	else
	 		{
	 			p->next=h->next;
	 			h->next=p;
	 			h->data++;
			 }
		p=(Lianbiao*)malloc(sizeof(int));
		
		if(p)											/*判断p是否为空*/
	 	{
	 		scanf("%d",&p->data);
			p->next=NULL; 
		 }
	  } 
	  return h; 
 }
 
 //输出函数 
 void output(Lianbiao *L)
 {
 	Lianbiao *temp=L->next;
 	while(temp)
 	{
 		printf("%d ",temp->data);
 		temp=temp->next;
	 }
 }
 
 //查找函数 
 void find(Lianbiao *L)
 {
 	int num;
 	printf("请输入你要查找的数:");
 	scanf("%d",&num);
 	int place=1,n=0;									/*i记录位置,n记录查找情况*/
 	Lianbiao *temp=L->next;
	while(temp)
	{
		if(temp->data==num)
			{
				printf("你要查找的元素在%d位\n",place++);
				temp=temp->next;
				n++;
			}
		else
			{
				temp=temp->next;
				place++;
			}
	 } 
	 if(n==0) 
	 	printf("查找失败!");
 }
 //删除函数
 void _delete(Lianbiao *L)
 {
 	int place,i=1;							/*place是指删除的位置，i是用来记录位置的*/
 	printf("请输入你要删除的位置:");
 	scanf("%d",&place);
 	while(L)
	 {
	 	if(i!=place)								/*位置不符合*/
	 		{
	 			i++;
	 			L=L->next;
			 }
		else
			{
				sign1='0'; 
				L->next=L->next->next;
				break;	
			}
	  } 
	  if(sign1=='1')
	  	{
	  		printf("删除失败!");
	  		sign1='1';
		  }
  } 
  //插入函数
  void insert(Lianbiao *L)
  {
  	int place,i=1;
  	printf("请输入需要插入的位置:");
  	scanf("%d",&place);
  	if(place<=L->data+1)
  		{
  			sign2='0';
  			Lianbiao *p=(Lianbiao*)malloc(sizeof(int));
  			printf("请输入需要插入的数:");
  			scanf("%d",&p->data);
  			while(1)
  				{
	  				if(i!=place)								/*位置不符合*/
				 		{
					 		i++;
					 		L=L->next;
						}
					else
						{
							p->next=L->next;
							L->next=p;
							break;
						}
				}
		  }
	 else
		{
			printf("插入失败!");
			sign2='1';
		}
   } 
 main()
 {
 	//指向创建好的动态指针数组,chooser为输入选项
	int chooser;
	Lianbiao *a; 
//用来作退出的判断符
	char sign[5]="yes";									
	a=create(a);									/*调用函数创建动态数组*/
	while(strcmp(sign,"yes")==0)
	{
		printf("请输入需要对数组的操作\n");
		printf("1、打印数组\t\t2、查找元素\t\t3、删除元素\t\t4、插入元素\n");
		printf("输入为:");
		scanf("%d",&chooser);
		switch(chooser)
		{
			case 1:output(a);
				break;

			case 2:	find(a);
				break;

			case 3:_delete(a);
				if(sign1=='0')
				{
					printf("删除后的数组为:");
					output(a);
				}
				break;

			case 4:insert(a);
				if(sign2=='0')
				{
					printf("插入后的数组为:");
					output(a);
				}
				break;

			default:printf("输入有误！\n");
				break;
		}
		printf("继续请输入\"yes\"，否则退出！\n");	
		scanf("%s",sign);
		printf("---------------------------------------------------------------------------------------\n");
	}
 }
 
