#include<stdio.h>
int main()
{
	int i,j,n=0;
	long int a[1000][1000];
	printf("«Î ‰»Î–– ˝£∫");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{	
				a[i][0]=1;
				a[i][i]=1;
				if(i>=2&&j>=1)
				a[i][j]=a[i-1][j-1]+a[i-1][j];
				a[i][0]=1;
				a[i][i]=1;
				printf("%d\t",a[i][j]);
			 } 
			 printf("\n");
		}
 } 
