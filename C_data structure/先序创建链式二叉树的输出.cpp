#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	//二叉树的头指针
	struct tree *near1;
	//二叉树的尾指针
	struct tree *head;
	//数据
	char data;
}Tree;

//先序创建二叉树的头结点
Tree *createTree(Tree *L) {
	//创建一个空节点
	L = (Tree*)malloc(sizeof(Tree));
	//数据输入
	char data;
	printf("请输入节点的数据:");
	scanf("%c",&data);
	L->data = data;
	L->head = NULL;
	L->near1 = NULL;
	return L;
}

//创建二叉树
void createTree2(Tree *L) {
	//临时变量
	char data;
	if (L->data != '#') {	//如果是不为空，则创建新的空间
		//给左二叉树赋值并且连接
		Tree *temp1 = (Tree*)malloc(sizeof(Tree));
		scanf("%c",&data);
		temp1->data = data;
		L->head = temp1;
		createTree2(temp1 );

		//给右二叉树赋值并且连接
		Tree *temp2 = (Tree*)malloc(sizeof(Tree));
		scanf("%c",&data);
		temp2->data = data;
		L->near1 = temp2;
		createTree2(temp2 );
	}
}

//先序遍历二叉树
void outputTree(Tree *L) {
	//先打印头结点
	printf("%c ",L->data);
	//打印左二叉树结点
	if (L->head->data != '#') 
		outputTree(L->head);
	//打印右二叉树结点
	if (L->near1->data != '#') 
		outputTree(L->near1);
}

//中序遍历二叉树
void outputTree2(Tree *L) {
	//打印左二叉树结点
	if (L->head->data != '#') 
		outputTree2(L->head);
		
	//先打印头结点
	printf("%c ",L->data);
	
	//打印右二叉树结点
	if (L->near1->data != '#') 
		outputTree2(L->near1);
}
//后序遍历二叉树
void outputTree3(Tree *L) {
	//打印左二叉树结点
	if (L->head->data != '#') 
		outputTree3(L->head);
		
	//打印右二叉树结点
	if (L->near1->data != '#') 
		outputTree3(L->near1);
		
	//先打印头结点
	printf("%c ",L->data);
	
	
}
main() {
	//定义一个二叉树的引用
	Tree *h;
	//创建一个二叉树头结点
	h = createTree(h);
	//创建二叉树
	createTree2(h);
	//先序遍历二叉树
	printf("先序遍历二叉树\n");
	outputTree(h);
	//中序遍历二叉树
	printf("\n中序遍历二叉树\n");
	outputTree2(h);
	//后序遍历二叉树
	printf("\n后序遍历二叉树\n");
	outputTree3(h); 
}
