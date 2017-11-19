#include<stdio.h>
#include<malloc.h>
#define OK 1
#define FALSE 0
#define MAX 10000
//保存因子的数组 
int factor[MAX];
//初始化数组
void Inti() {
	int i;
	for (i = 0; i < MAX; i++) {
		factor[i] = 0;
	} 
} 
//求因子 ,放入数组保存 
void getFactor(int n) {
	int i = 1,j = 0;
	for (i; i < n; i++) {
		if (n % i == 0) {
			factor[j] = i;
			j++;
		}
	}
}

//判断是否为完数，一个数的完数为它的所以因子和 
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

//运用格式输出完数
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
//	起始到结束的完数范围 
	int start,stop; 
	
	printf("请输入起始到结束的范围:");
	scanf("%d%d",&start,&stop);
	for (; start < stop; start++) {
//		调用函数start的获得因子 
		getFactor(start);
//		调用函数判断start是否为完数
		if (isFactor(start)) {//是就输出 
		 	output(start);
		 }
//		 初始化 
		 Inti();
		
	}
}
