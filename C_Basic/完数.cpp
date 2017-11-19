#include<stdio.h>
#include<malloc.h>
#define OK 1
#define FALSE 0
#define MAX 10000
//�������ӵ����� 
int factor[MAX];
//��ʼ������
void Inti() {
	int i;
	for (i = 0; i < MAX; i++) {
		factor[i] = 0;
	} 
} 
//������ ,�������鱣�� 
void getFactor(int n) {
	int i = 1,j = 0;
	for (i; i < n; i++) {
		if (n % i == 0) {
			factor[j] = i;
			j++;
		}
	}
}

//�ж��Ƿ�Ϊ������һ����������Ϊ�����������Ӻ� 
int isFactor(int n) {
	int sum = 0,i;
	for (i = 0; factor[i] != 0; i++) {
		sum += factor[i];
	}
	if (sum == n) {
		return OK;
	} else {
		return FALSE;
	}
}

//���ø�ʽ�������
void output(int n) {
	int i = 0;
	printf("%d=",n);
	for (i = 0; factor[i] != 0; i++) {
		printf("%d",factor[i]);
		if (factor[i+1] != 0) {
			printf("+");
		}
	}
	printf("\n");
}
 
main() {
//	��ʼ��������������Χ 
	int start,stop; 
	
	printf("��������ʼ�������ķ�Χ:");
	scanf("%d%d",&start,&stop);
	for (; start < stop; start++) {
//		���ú���start�Ļ������ 
		getFactor(start);
//		���ú����ж�start�Ƿ�Ϊ����
		if (isFactor(start)) {//�Ǿ���� 
		 	output(start);
		 }
//		 ��ʼ�� 
		 Inti();
		
	}
}
