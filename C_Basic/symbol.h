#include"e2.c"
//��������~�ӷ�
void add(float a1,float b1,float a2,float b2)
{
	xxx(a1,b1,a2,b2,'+');				/*����xxx������������㸴����ߵı��ʽ */
	if((a1+a2)==0) {
			if((b1+b2)>0) {
					if((b1+b2)==1)		/*�鲿���Ϊ1ʱ��ֱ�Ӵ�ӡi*/
						printf("i");
					else
							printf("%.2fi",b1+b2);
				} else if ((b1+b2)<0)
					printf("%.2fi",b1+b2);
			else
				printf("0");
		} else {
			printf("%.2f",a1+a2);
			if((b1+b2)>0)
				{
					if((b1+b2)==1)
						printf("+i");
					else
							printf("%+.2fi",b1+b2);
				}
			else if((b1+b2)<0)
					printf("%.2fi",b1+b2);
			else
				printf("");
		}
}
//��������~���� 
void minus(float a1,float b1,float a2,float b2)
{
	xxx(a1,b1,a2,b2,'-');				/*����xxx������������㸴����ߵı��ʽ */
	if((a1-a2)==0)
		{
			if((b1-b2)>0)
				{
					if((b1-b2)==1)
						printf("i");
					else
							printf("%.2fi",b1-b2);
				}
			else if((b1-b2)<0)
					printf("%.2fi",b1-b2);
			else
				printf("0");
		}
	else
		{
			printf("%.2f",a1-a2);
			if((b1-b2)>0)
				{
					if((b1-b2)==1)
						printf("+i");
					else
							printf("%+.2fi",b1-b2);
				}
			else if((b1-b2)<0)
					printf("%.2fi",b1-b2);
			else
				printf("");
		}
}
//�������� ~�˷�
void plus(float a1,float b1,float a2,float b2)
{
	xxx(a1,b1,a2,b2,'*');				/*����xxx������������㸴����ߵı��ʽ */
	if((a1*a2-b1*b2)==0)
		{
			if((a1*b2+a2*b1)>0)
				{
					if((a1*b2+a2*b1)==1)
						printf("i");
					else
							printf("%.2fi",a1*b2+a2*b1);
				}
			else if((a1*b2+a2*b1)<0)
					printf("%.2fi",a1*b2+a2*b1);
			else
				printf("0");
		}
	else
		{
			printf("%.2f",a1*a2-b1*b2);
			if((a1*b2+a2*b1)>0)
				{
					if((a1*b2+a2*b1)==1)
						printf("+i");
					else
							printf("%+.2fi",a1*b2+a2*b1);
				}
			else if((a1*b2+a2*b1)<0)
					printf("%.2fi",a1*b2+a2*b1);
			else
				printf("");
		}
}
//�������� ~����
/*����������:(a1*a2+b1*b2)/(a2*a2+b2*b2)+(a2*b1-a1*b2)/(a2*a2+b2*b2)*/
void multiply(float a1,float b1,float a2,float b2)
{/*temp1�Ƿ�ĸ��temp2��ʵ����temp3���鲿*/
	float temp1=a2*a2+b2*b2,temp2=(a1*a2+b1*b2)/(a2*a2+b2*b2),temp3=(a2*b1-a1*b2)/(a2*a2+b2*b2); 
	if(temp1>0)					/*ȷ���ó���������*/
		{
		xxx(a1,b1,a2,b2,'/');				/*����xxx������������㸴����ߵı��ʽ */
		if(temp2==0)
			{
				if(temp3>0)
					{
						if(temp3==1)
							printf("i");
						else
							printf("%.2fi",temp3);
					}
				else if(temp3<0)
					printf("%.2fi",temp3);
				else
					printf("0");
			}
		else
			{
			printf("%.2f",temp2);
			if(temp3>0)
				{
					if(temp3==1)
						printf("+i");
					else
							printf("%+.2fi",temp3);
				}
			else if(temp3<0)
					printf("%.2fi",temp3);
			else
				printf("");
			}	
		}
	else
		{
			if((a1*a2-b1*b2)==0)
				printf("0");
			else
				printf("�ó��������壡");
		}
}

 
