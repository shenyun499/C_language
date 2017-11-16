#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
typedef struct tree {
	int data[MAX];
	int length;
	int deep;
	int l;
}Tree; 
Tree *createTree(Tree *h) {
	h =  (Tree*)malloc (sizeof(Tree));
	h->length = 0;
	h->l = 0;
	int data;
	printf("请输入第%d个结点对应的元素,若输入为0，则表示结点为空:",h->l+1);
	scanf("%d",&data);
	while (data != -1) {
		h->data[h->l] = data;
		if (h->data [h->l] != 0) {
			h->length++;
		}
		h->l++;
		printf("请输入第%d个结点对应的元素:",h->l+1);
	scanf("%d",&data);
	}
	return h;
}

void treeOutput(Tree *h ) {
	int i=0;
	for (i; i < h->l; i++) {
		printf("%d ",h->data[i]);
	} 
	printf("\n");
}

void treeNumber(Tree *h) {
	printf("二叉树的节点数为:");
	printf("%d\n",h->length);
}

void treeDeep(Tree *h) {
	int i = 0;
	int deep = h->l + 1;
	while (deep /2 != 0) {
		i++;
		deep = deep / 2;
	}
	printf("二叉树的深度为:%d",i); 
}
main()
{
	Tree *h;
	
	h = createTree(h);
	
	treeOutput(h);
	
	treeNumber(h);
	
	treeDeep(h);
}

