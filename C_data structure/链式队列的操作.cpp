#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define FALSE 0
typedef struct dat {
	int data;
	struct dat *next;
}sqQueue;

//队头和队尾指针 
typedef struct {
	sqQueue *front;	//队头指针 
	sqQueue *rear;	//队尾指针 
}sqQueueP;

//初始化空队
void InitQueue(sqQueueP *sq) {
	sq->front = sq->rear = (sqQueue*)malloc(sizeof(sqQueue));	//申请头结点
	sq->rear->next = NULL; 
	sq->front->next = NULL;
}

//建立队列 
void CreateQueue(sqQueueP *sq) {
	int data;			//队列的元素 
	sqQueue *p; 	
	printf("请输入队列元素:");
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

//元素入队 
void InQueue(sqQueueP *sq) {
	sqQueue *p;
	p = (sqQueue*)malloc(sizeof(sqQueue));
	int data;
	printf("请输入需要入队的元素:");
	scanf("%d",&data);
	sq->rear->next = p;				//新增结点 
	sq->rear = sq->rear->next;
	sq->rear->data = data;			//队尾新值
	sq->rear->next = NULL;	   
}

//判断空队
int isEmpty(sqQueueP *sq) {
	if (sq->front == sq->rear)
		return FALSE;
	else
		return OK;
}

//元素出队
void outputQueue(sqQueueP *sq) {
	if (isEmpty(sq)) { 
		sqQueueP *sq2;
		sq2 = sq;		//保存队头指针 
		int data;
		sq->front = sq->front->next; 
		data = sq->front->data;
		printf("出队元素为:%d\n",data);
		free(sq2->front);
	}
	else
		printf("队列为空\n");
}


main()
{
	sqQueueP *sq;
	sq = (sqQueueP*)malloc(sizeof(sqQueueP));
	int chooser;
	char sign[] = "yes";
	while (!strcmp("yes",sign)) {
		printf("1、初始化空队\t\t2、创建队列\t\t3、元素出队\t\t4、元素入队\t\t5、判空队\n"); 
		printf("请选择你要的操作:");
		scanf("%d",&chooser);
		switch (chooser) {
			case 1:InitQueue(sq);break;			//初始化空队
			case 2:CreateQueue(sq);break;		//创建队列 
			case 3:outputQueue(sq);break;
			case 4:InQueue(sq);break;
			case 5:if(isEmpty(sq)) {
				printf("队列不为空\n");
			} 
				else
					printf("队列为空\n");
			break;
	}
	printf("继续操作请输入yes,否则退出!\n");
	scanf("%s",sign);
	}	
 } 

