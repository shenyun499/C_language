#include<stdio.h>
#include<stdlib.h>
#define MAX_ADJVEX 20
typedef struct ArcNode {
	//��ָ��Ķ�����Ϣ 
	int adjvex;
	//ָ����һ������ָ�� 
	struct ArcNode *next;
}ArcNode;

typedef struct VNode {
	//ͼ�ĸ�������Ϣ 
	char data;
	//ָ��ͼ��ָ�� 
	ArcNode *nextarc;
}VNode;

typedef struct {
	VNode vexsum[MAX_ADJVEX];
	//ͼ��ǰ�Ķ������ͻ��� 
	int vexnum,arcnum;
	//ͼ�������־ 
	int kind; 
}Graph; 

//��������:ʹ��������Ӧ���ڽӾ���Ķ�ά���� 
int getIndexOfVexs(Graph *G, char c) {
	int i =0 ;
	for (i; i < G->vexnum; i++) {
		if (G->vexsum[i].data == c) {
			return i;
		}
	}
}
 
//��ʼ��ͼ�Ķ��㡢���������� 
void initGraph(Graph *G) {
	printf("�����붥�����ͱ�����:8,9\n");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	printf("����ͼ����(1:NG 2:UNG)");
	scanf("%d",&G->kind);
}

//����ͼ
void createGraph(Graph *G) {
	int i;
	printf("�����붥����Ϣ:��abcdef\n");
	getchar();
	for (i = 0; i < G->vexnum; i++) {
		scanf("%c",&G->vexsum[i].data);
		G->vexsum[i].nextarc = NULL;
	}
	getchar();
	i = 0;
	printf("������߽����:ab bd dh...\n");
	while (i < G->arcnum) {
		if (G->kind == 1) {
			char vex1,vex2;
			scanf("%c%c",&vex1,&vex2);
			int v1,v2;
			v1 = getIndexOfVexs(G, vex1);
			v2 = getIndexOfVexs(G, vex2);
			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = v2;
			p->next = G->vexsum[v1].nextarc;
			G->vexsum[v1].nextarc = p;
			
		} else if (G->kind == 2) {
			char vex1,vex2;
			scanf("%c%c",&vex1,&vex2);
			int v1,v2;
			v1 = getIndexOfVexs(G, vex1);
			v2 = getIndexOfVexs(G, vex2);
			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = v2;
			p->next = G->vexsum[v1].nextarc;
			G->vexsum[v1].nextarc = p;

			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = v1;
			p->next = G->vexsum[v2].nextarc;
			G->vexsum[v2].nextarc = p;
		} else {
			printf("ͼ�����಻����!\n");
			break; 
		}
		i++; 
		getchar();
	}
}
//����������Ϣ
void outputGraphVexnum(Graph *G) {
	int i = 0;
	VNode *p;
	for (i; i< G->arcnum; i++) {
		printf("%c ",G->vexsum[i].data);
	}
} 

//����ڽӱ�
void outputALGraph(Graph *G) {
	ArcNode *p;
	int i = 0;
	if (G->kind == 1) {
		printf("����������ڽӱ�����:adjvex,data\n");
	} else {
		printf("����������ڽӱ�����:adjvex,data\n");
	}
	for (i; i < G->vexnum; i++) {
		printf("%d,%c",i,G->vexsum[i]);
		p = G->vexsum[i].nextarc;
		while (p) {
			printf(",%d,%c",p->adjvex,G->vexsum[p->adjvex]);
			p = p->next;
		}
		printf("\n");
	}
} 
main() {
	Graph G;
	initGraph(&G);
	createGraph(&G);
	outputGraphVexnum(&G);
	outputALGraph(&G);
}
 
