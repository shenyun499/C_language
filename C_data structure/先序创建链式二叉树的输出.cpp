#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	//��������ͷָ��
	struct tree *near1;
	//��������βָ��
	struct tree *head;
	//����
	char data;
}Tree;

//���򴴽���������ͷ���
Tree *createTree(Tree *L) {
	//����һ���սڵ�
	L = (Tree*)malloc(sizeof(Tree));
	//��������
	char data;
	printf("������ڵ������:");
	scanf("%c",&data);
	L->data = data;
	L->head = NULL;
	L->near1 = NULL;
	return L;
}

//����������
void createTree2(Tree *L) {
	//��ʱ����
	char data;
	if (L->data != '#') {	//����ǲ�Ϊ�գ��򴴽��µĿռ�
		//�����������ֵ��������
		Tree *temp1 = (Tree*)malloc(sizeof(Tree));
		scanf("%c",&data);
		temp1->data = data;
		L->head = temp1;
		createTree2(temp1 );

		//���Ҷ�������ֵ��������
		Tree *temp2 = (Tree*)malloc(sizeof(Tree));
		scanf("%c",&data);
		temp2->data = data;
		L->near1 = temp2;
		createTree2(temp2 );
	}
}

//�������������
void outputTree(Tree *L) {
	//�ȴ�ӡͷ���
	printf("%c ",L->data);
	//��ӡ����������
	if (L->head->data != '#') 
		outputTree(L->head);
	//��ӡ�Ҷ��������
	if (L->near1->data != '#') 
		outputTree(L->near1);
}

//�������������
void outputTree2(Tree *L) {
	//��ӡ����������
	if (L->head->data != '#') 
		outputTree2(L->head);
		
	//�ȴ�ӡͷ���
	printf("%c ",L->data);
	
	//��ӡ�Ҷ��������
	if (L->near1->data != '#') 
		outputTree2(L->near1);
}
//�������������
void outputTree3(Tree *L) {
	//��ӡ����������
	if (L->head->data != '#') 
		outputTree3(L->head);
		
	//��ӡ�Ҷ��������
	if (L->near1->data != '#') 
		outputTree3(L->near1);
		
	//�ȴ�ӡͷ���
	printf("%c ",L->data);
	
	
}
main() {
	//����һ��������������
	Tree *h;
	//����һ��������ͷ���
	h = createTree(h);
	//����������
	createTree2(h);
	//�������������
	printf("�������������\n");
	outputTree(h);
	//�������������
	printf("\n�������������\n");
	outputTree2(h);
	//�������������
	printf("\n�������������\n");
	outputTree3(h); 
}
