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
	printf("�������%d������Ӧ��Ԫ��,������Ϊ0�����ʾ���Ϊ��:",h->l+1);
	scanf("%d",&data);
	while (data != -1) {
		h->data[h->l] = data;
		if (h->data [h->l] != 0) {
			h->length++;
		}
		h->l++;
		printf("�������%d������Ӧ��Ԫ��:",h->l+1);
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
	printf("�������Ľڵ���Ϊ:");
	printf("%d\n",h->length);
}

void treeDeep(Tree *h) {
	int i = 0;
	int deep = h->l + 1;
	while (deep /2 != 0) {
		i++;
		deep = deep / 2;
	}
	printf("�����������Ϊ:%d",i); 
}
main()
{
	Tree *h;
	
	h = createTree(h);
	
	treeOutput(h);
	
	treeNumber(h);
	
	treeDeep(h);
}

