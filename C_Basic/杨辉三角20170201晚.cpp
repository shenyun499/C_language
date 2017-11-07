#include<stdio.h>
#include<conio.h>
main()
{
	char ch;
	int a[20][20]={0};
	int i,j,n;
	printf("please enter n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i>1&&j>0)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
			else
			{
				a[i][i]=1;
				a[i][0]=1;
			}
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	ch=getchar(); 
	ch=getchar();
 } 
