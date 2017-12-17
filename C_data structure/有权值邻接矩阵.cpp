#include<stdio.h>
#define MAX_VERTEX_NUM 20
typedef struct vertex_ {
	//以为数组顶点存放的信息，要么是权，要么是0和1 
	char vexValue[MAX_VERTEX_NUM];
	
	//图的顶点数和边数 
	int vexnum,arcnum;
	 
	//二维数组邻接矩阵存取图 
	int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}vertex; 

//typedef struct {
//	
//	
//	//一维数组存放顶点信息
//	char vrtype[MAX_VERTEX_NUM];
//	
//	//
//}MGraph;

//使顶点变成相应的邻接矩阵的二维坐标 
int getIndexOfVexs(char c1) {
	return c1-'a';
}
//初始化邻接矩阵和图的顶点、边数 
void initVertexGroup(vertex *G) {
	int i,j;
	for (i = 0; i < MAX_VERTEX_NUM; i++) {
		for (j = 0; j < MAX_VERTEX_NUM; j++) {
			G->adjMatrix[i][j] = 0;
		}
	}
	
	G->vexnum = 0;
	G->arcnum = 0;
}
//创建图 
void createVertexGroup(vertex *G) {
	//i用来记录顶点个数 
	int i = 0;
	printf("请分别输入邻接矩阵的顶点和边（如输入3，4）:");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	
	//对顶点信息赋值 
	while (i != G->vexnum) { 
		printf("请输入第%d个顶点的值(char):",i+1);
		if(i == 0) {
			getchar();
		}
		scanf("%c",&G->vexValue[i++]);
		getchar();
	} 
	
	//给出相邻的边 
	i = 0;
	while (i != G->arcnum) {
		//定义临时存放两相邻顶点的变量
		char vexValue1,vexValue2;
		
		//定义临时存放权值的变量
		int vertexQ; 
		printf("请输入起始顶点（char):");
		scanf("%c",&vexValue1);
		getchar();
		 
		printf("请输入终点顶点（char):");
		scanf("%c",&vexValue2);
		getchar();
		
		if ('a' <= vexValue1 <= 'z' && 'a' <= vexValue2 <= 'z') {
			printf("请输入权值（int):");
			scanf("%d",&vertexQ); 
			G->adjMatrix[getIndexOfVexs(vexValue1)][getIndexOfVexs(vexValue2)] = vertexQ;
			i++;
			printf("\n");
			getchar();
		} else {
			printf("你输入的信息有误，再见！");
			break;
		}
	}
}

//打印邻接矩阵
void printVertexGroup(vertex *G) {
	if ((G->arcnum && G->vexnum) != 0) {
		printf("邻接矩阵为:\n");
		int i,j;
		for (i = 0; i < G->vexnum; i++) {
			for (j = 0; j < G->vexnum ; j++) {
				printf("%d ", G->adjMatrix[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("邻接矩阵不存在，请创建之后在进行此操作!\n");
	}
} 

//打印顶点信息
void printVexValue (vertex *G) {
	if ((G->arcnum && G->vexnum) != 0) {
		int i,j;
		for (i = 0; i < G->vexnum; i++) {
			printf("第%d个顶点:%c\n",i+1, G->vexValue[i]);
		}
	} else {
		printf("顶点不存在，请创建之后在进行此操作!\n");
	}
}
main() {
	vertex G;
	//初始化 
	initVertexGroup(&G);
	//创建图 
	createVertexGroup(&G);
	//打印图顶点 
	printVexValue(&G);
	//打印邻接矩阵 
	printVertexGroup(&G);
	
}
