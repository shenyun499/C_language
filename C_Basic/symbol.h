#include"e2.c"
//复数计算~加法
void add(float a1,float b1,float a2,float b2)
{
	xxx(a1,b1,a2,b2,'+');				/*调用xxx函数，输出计算复数左边的表达式 */
	if((a1+a2)==0) {
			if((b1+b2)>0) {
					if((b1+b2)==1)		/*虚部相加为1时，直接打印i*/
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
//复数计算~减法 
void minus(float a1,float b1,float a2,float b2)
{
	xxx(a1,b1,a2,b2,'-');				/*调用xxx函数，输出计算复数左边的表达式 */
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
//复数计算 ~乘法
void plus(float a1,float b1,float a2,float b2)
{
	xxx(a1,b1,a2,b2,'*');				/*调用xxx函数，输出计算复数左边的表达式 */
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
//复数计算 ~除法
/*复数相除结果:(a1*a2+b1*b2)/(a2*a2+b2*b2)+(a2*b1-a1*b2)/(a2*a2+b2*b2)*/
void multiply(float a1,float b1,float a2,float b2)
{/*temp1是分母，temp2是实部，temp3是虚部*/
	float temp1=a2*a2+b2*b2,temp2=(a1*a2+b1*b2)/(a2*a2+b2*b2),temp3=(a2*b1-a1*b2)/(a2*a2+b2*b2); 
	if(temp1>0)					/*确保该除法有意义*/
		{
		xxx(a1,b1,a2,b2,'/');				/*调用xxx函数，输出计算复数左边的表达式 */
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
				printf("该除法无意义！");
		}
}

 
