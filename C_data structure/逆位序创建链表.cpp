#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
//�ֱ�������¼�Ƿ�ɹ�����ɾ��������
char sign1='1',sign2='1';
typedef struct data1
{
	int data;
	struct data1 *next;
 } Lianbiao;
 Lianbiao *create(Lianbiao *h)
 {
 	printf("��������Ҫ����������Ԫ�أ���0����\n");
 	h=(Lianbiao*)malloc(sizeof(int));				/*����ͷ���*/
 	h->next=NULL;
 	h->data=0;
 	//p��������ռ䣬temp�ֱ�������¼ p֮ǰ�Ľ�� 
 	Lianbiao *p;
 	p=(Lianbiao*)malloc(sizeof(int));				/*�����ڴ�ռ�*/
 	if(p)											/*�ж�p�Ƿ�Ϊ��*/
 	{
 		scanf("%d",&p->data);
		 p->next=NULL; 
	 }
	 while(p->data!=0)								/*����0��������*/
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
		
		if(p)											/*�ж�p�Ƿ�Ϊ��*/
	 	{
	 		scanf("%d",&p->data);
			p->next=NULL; 
		 }
	  } 
	  return h; 
 }
 
 //������� 
 void output(Lianbiao *L)
 {
 	Lianbiao *temp=L->next;
 	while(temp)
 	{
 		printf("%d ",temp->data);
 		temp=temp->next;
	 }
 }
 
 //���Һ��� 
 void find(Lianbiao *L)
 {
 	int num;
 	printf("��������Ҫ���ҵ���:");
 	scanf("%d",&num);
 	int place=1,n=0;									/*i��¼λ��,n��¼�������*/
 	Lianbiao *temp=L->next;
	while(temp)
	{
		if(temp->data==num)
			{
				printf("��Ҫ���ҵ�Ԫ����%dλ\n",place++);
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
	 	printf("����ʧ��!");
 }
 //ɾ������
 void _delete(Lianbiao *L)
 {
 	int place,i=1;							/*place��ָɾ����λ�ã�i��������¼λ�õ�*/
 	printf("��������Ҫɾ����λ��:");
 	scanf("%d",&place);
 	while(L)
	 {
	 	if(i!=place)								/*λ�ò�����*/
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
	  		printf("ɾ��ʧ��!");
	  		sign1='1';
		  }
  } 
  //���뺯��
  void insert(Lianbiao *L)
  {
  	int place,i=1;
  	printf("��������Ҫ�����λ��:");
  	scanf("%d",&place);
  	if(place<=L->data+1)
  		{
  			sign2='0';
  			Lianbiao *p=(Lianbiao*)malloc(sizeof(int));
  			printf("��������Ҫ�������:");
  			scanf("%d",&p->data);
  			while(1)
  				{
	  				if(i!=place)								/*λ�ò�����*/
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
			printf("����ʧ��!");
			sign2='1';
		}
   } 
 main()
 {
 	//ָ�򴴽��õĶ�ָ̬������,chooserΪ����ѡ��
	int chooser;
	Lianbiao *a; 
//�������˳����жϷ�
	char sign[5]="yes";									
	a=create(a);									/*���ú���������̬����*/
	while(strcmp(sign,"yes")==0)
	{
		printf("��������Ҫ������Ĳ���\n");
		printf("1����ӡ����\t\t2������Ԫ��\t\t3��ɾ��Ԫ��\t\t4������Ԫ��\n");
		printf("����Ϊ:");
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
					printf("ɾ���������Ϊ:");
					output(a);
				}
				break;

			case 4:insert(a);
				if(sign2=='0')
				{
					printf("����������Ϊ:");
					output(a);
				}
				break;

			default:printf("��������\n");
				break;
		}
		printf("����������\"yes\"�������˳���\n");	
		scanf("%s",sign);
		printf("---------------------------------------------------------------------------------------\n");
	}
 }
 
