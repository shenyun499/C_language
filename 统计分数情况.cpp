#include<stdio.h>
main()
{
	int grade,altor1=0,altor2=0,altor3=0,altor4=0,n=0;
	printf("please enter grade��");
	scanf("%d",&grade); 
	while(grade!=0)
	{                                                 
	switch(grade/10)
	{
		case 10:
			case 9:  ++altor1;
					  ++n;
					  break;
		case 8:
			case 7:   ++altor2;
					  ++n;
					  break;
		case 6:       ++altor3;
					  ++n;
					  break;
		default:      ++altor4;
					  ++n;
					  break;
	 } 
	 scanf("%d",&grade); 
   }
   	 printf("������\t��������\t��������\t��������\t����������\n");
	 printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",n,altor1,altor2,altor3,altor4);
}
