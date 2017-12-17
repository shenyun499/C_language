#include<stdio.h>
#define MAX_VERTEX_NUM 20
typedef struct vertex_ {
	//��Ϊ���鶥���ŵ���Ϣ��Ҫô��Ȩ��Ҫô��0��1 
	char vexValue[MAX_VERTEX_NUM];
	
	//ͼ�Ķ������ͱ��� 
	int vexnum,arcnum;
	 
	//��ά�����ڽӾ����ȡͼ 
	int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}vertex; 

//typedef struct {
//	
//	
//	//һά�����Ŷ�����Ϣ
//	char vrtype[MAX_VERTEX_NUM];
//	
//	//
//}MGraph;

//ʹ��������Ӧ���ڽӾ���Ķ�ά���� 
int getIndexOfVexs(char c1) {
	return c1-'a';
}
//��ʼ���ڽӾ����ͼ�Ķ��㡢���� 
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
//����ͼ 
void createVertexGroup(vertex *G) {
	//i������¼������� 
	int i = 0;
	printf("��ֱ������ڽӾ���Ķ���ͱߣ�������3��4��:");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	
	//�Զ�����Ϣ��ֵ 
	while (i != G->vexnum) { 
		printf("�������%d�������ֵ(char):",i+1);
		if(i == 0) {
			getchar();
		}
		scanf("%c",&G->vexValue[i++]);
		getchar();
	} 
	
	//�������ڵı� 
	i = 0;
	while (i != G->arcnum) {
		//������ʱ��������ڶ���ı���
		char vexValue1,vexValue2;
		
		//������ʱ���Ȩֵ�ı���
		int vertexQ; 
		printf("��������ʼ���㣨char):");
		scanf("%c",&vexValue1);
		getchar();
		 
		printf("�������յ㶥�㣨char):");
		scanf("%c",&vexValue2);
		getchar();
		
		if ('a' <= vexValue1 <= 'z' && 'a' <= vexValue2 <= 'z') {
			printf("������Ȩֵ��int):");
			scanf("%d",&vertexQ); 
			G->adjMatrix[getIndexOfVexs(vexValue1)][getIndexOfVexs(vexValue2)] = vertexQ;
			i++;
			printf("\n");
			getchar();
		} else {
			printf("���������Ϣ�����ټ���");
			break;
		}
	}
}

//��ӡ�ڽӾ���
void printVertexGroup(vertex *G) {
	if ((G->arcnum && G->vexnum) != 0) {
		printf("�ڽӾ���Ϊ:\n");
		int i,j;
		for (i = 0; i < G->vexnum; i++) {
			for (j = 0; j < G->vexnum ; j++) {
				printf("%d ", G->adjMatrix[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("�ڽӾ��󲻴��ڣ��봴��֮���ڽ��д˲���!\n");
	}
} 

//��ӡ������Ϣ
void printVexValue (vertex *G) {
	if ((G->arcnum && G->vexnum) != 0) {
		int i,j;
		for (i = 0; i < G->vexnum; i++) {
			printf("��%d������:%c\n",i+1, G->vexValue[i]);
		}
	} else {
		printf("���㲻���ڣ��봴��֮���ڽ��д˲���!\n");
	}
}
main() {
	vertex G;
	//��ʼ�� 
	initVertexGroup(&G);
	//����ͼ 
	createVertexGroup(&G);
	//��ӡͼ���� 
	printVexValue(&G);
	//��ӡ�ڽӾ��� 
	printVertexGroup(&G);
	
}
