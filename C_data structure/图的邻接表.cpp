#include<stdio.h>
#include<stdlib.h>
#define MAX_ADJVEX 20
typedef struct ArcNode {
	//弧指向的顶点信息 
	int adjvex;
	//指向下一条弧的指针 
	struct ArcNode *next;
}ArcNode;

typedef struct VNode {
	//图的各顶点信息 
	char data;
	//指向图的指针 
	ArcNode *nextarc;
}VNode;

typedef struct {
	VNode vexsum[MAX_ADJVEX];
	//图当前的定点数和弧数 
	int vexnum,arcnum;
	//图的种类标志 
	int kind; 
}Graph; 

//函数作用:使顶点变成相应的邻接矩阵的二维坐标 
int getIndexOfVexs(Graph *G, char c) {
	int i =0 ;
	for (i; i < G->vexnum; i++) {
		if (G->vexsum[i].data == c) {
			return i;
		}
	}
}
 
//初始化图的顶点、边数和种类 
void initGraph(Graph *G) {
	printf("请输入顶点数和边数如:8,9\n");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	printf("输入图类型(1:NG 2:UNG)");
	scanf("%d",&G->kind);
}

//创建图
void createGraph(Graph *G) {
	int i;
	printf("请输入顶点信息:如abcdef\n");
	getchar();
	for (i = 0; i < G->vexnum; i++) {
		scanf("%c",&G->vexsum[i].data);
		G->vexsum[i].nextarc = NULL;
	}
	getchar();
	i = 0;
	printf("请输入边结点如:ab bd dh...\n");
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
			printf("图的种类不存在!\n");
			break; 
		}
		i++; 
		getchar();
	}
}
//输出顶点的信息
void outputGraphVexnum(Graph *G) {
	int i = 0;
	VNode *p;
	for (i; i< G->arcnum; i++) {
		printf("%c ",G->vexsum[i].data);
	}
} 

//输出邻接表
void outputALGraph(Graph *G) {
	ArcNode *p;
	int i = 0;
	if (G->kind == 1) {
		printf("顶点的有向邻接表如下:adjvex,data\n");
	} else {
		printf("顶点的无向邻接表如下:adjvex,data\n");
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
 
