#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define FALSE 0
typedef struct dat {
	int data;
	struct dat *next;
}sqQueue;

//��ͷ�Ͷ�βָ�� 
typedef struct {
	sqQueue *front;	//��ͷָ�� 
	sqQueue *rear;	//��βָ�� 
}sqQueueP;

//��ʼ���ն�
void InitQueue(sqQueueP *sq) {
	sq->front = sq->rear = (sqQueue*)malloc(sizeof(sqQueue));	//����ͷ���
	sq->rear->next = NULL; 
	sq->front->next = NULL;
}

//�������� 
void CreateQueue(sqQueueP *sq) {
	int data;			//���е�Ԫ�� 
	sqQueue *p; 	
	printf("���������Ԫ��:");
	scanf("%d",&data);
	while (data != 0) {
		p = (sqQueue*)malloc(sizeof(sqQueue));
		sq->rear->next = p;
		sq->rear = p;
		sq->rear->next = NULL;
		if(p) 
			sq->rear->data = data;	
		scanf("%d",&data);
	}
}

//Ԫ����� 
void InQueue(sqQueueP *sq) {
	sqQueue *p;
	p = (sqQueue*)malloc(sizeof(sqQueue));
	int data;
	printf("��������Ҫ��ӵ�Ԫ��:");
	scanf("%d",&data);
	sq->rear->next = p;				//������� 
	sq->rear = sq->rear->next;
	sq->rear->data = data;			//��β��ֵ
	sq->rear->next = NULL;	   
}

//�жϿն�
int isEmpty(sqQueueP *sq) {
	if (sq->front == sq->rear)
		return FALSE;
	else
		return OK;
}

//Ԫ�س���
void outputQueue(sqQueueP *sq) {
	if (isEmpty(sq)) { 
		sqQueueP *sq2;
		sq2 = sq;		//�����ͷָ�� 
		int data;
		sq->front = sq->front->next; 
		data = sq->front->data;
		printf("����Ԫ��Ϊ:%d\n",data);
		free(sq2->front);
	}
	else
		printf("����Ϊ��\n");
}


main()
{
	sqQueueP *sq;
	sq = (sqQueueP*)malloc(sizeof(sqQueueP));
	int chooser;
	char sign[] = "yes";
	while (!strcmp("yes",sign)) {
		printf("1����ʼ���ն�\t\t2����������\t\t3��Ԫ�س���\t\t4��Ԫ�����\t\t5���пն�\n"); 
		printf("��ѡ����Ҫ�Ĳ���:");
		scanf("%d",&chooser);
		switch (chooser) {
			case 1:InitQueue(sq);break;			//��ʼ���ն�
			case 2:CreateQueue(sq);break;		//�������� 
			case 3:outputQueue(sq);break;
			case 4:InQueue(sq);break;
			case 5:if(isEmpty(sq)) {
				printf("���в�Ϊ��\n");
			} 
				else
					printf("����Ϊ��\n");
			break;
	}
	printf("��������������yes,�����˳�!\n");
	scanf("%s",sign);
	}	
 } 

