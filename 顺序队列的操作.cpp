#include"stdio.h"
#include"malloc.h"
#define OK 1
#define ERROR 0
#define MAXSIZE 64
typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
int lnitQueue(SqQueue *Q){
	Q->base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q->base) return ERROR;
	Q->front=Q->rear=0;
	return OK;
}
int EnQueue(SqQueue *Q,QElemType e){
	if((Q->rear+1)%MAXSIZE==Q->front)
		return ERROR;
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}
int	DeQueue (SqQueue *Q,QElemType *e){
	if(Q->front==Q->rear)
		return ERROR;
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return OK;
}
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
void QueueTraverse(SqQueue Q){
	int i,k;
	k=QueueLength(Q);
	for(i=1;i<=k;i++){
		printf("%d",Q.base[Q.front]);
		Q.front=(Q.front+1)%MAXSIZE;
	}
}
main()
{
	int n,e,i;SqQueue q;
	lnitQueue(&q);
	printf("该循环队列最多可存放%d个元素\n",MAXSIZE-1);
	printf("请输入数据元素的个数n \n");
	scanf("%d",&n);
	printf("\n请输入%d个整数\n",n);
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		EnQueue(&q,e);
	}
	printf("q=");
	QueueTraverse(q);
		fflush(stdin);
	printf("\n请输入入队元素e\n");
	scanf("%d",&e);
	EnQueue(&q,e);
	printf("q=");
	QueueTraverse(q);
	fflush(stdin);
	printf("\n执行出队操作\n");
	DeQueue(&q,&e);
	printf("出队元素是%d\n",e);
	printf("q=");
	QueueTraverse(q);
}

