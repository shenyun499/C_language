#include<stdio.h>
main()
{ 
  int i,j;
  for(i=1;i<=100;i++)
{ for(j=2;j<=i;j++)
  if(i%j==0)
  break;
  if(j>=i&&i<=9)
  printf("%d������\t\t",i);
  else if(j>=i&&i>9)
  printf("%d������\t",i);
  else
  printf("%d��������\t",i);
}
 } 
