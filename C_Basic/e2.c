//函数作用:将复数的左边表达式表达出来  
void xxx(float a1,float b1,float a2,float b2,char ch)
{
	if(a1==0)
		{
			if(b1!=0)
				printf("(");
		}
	else
		{
			printf("(");
			printf("%.2f",a1);
			if(b1>0)					//虚部b1大于0时,才需要打印+号 
				printf("+");
		}

	if(b1==0)							/*判断第一个复数的虚部是否为0 */
		{
			if(a1!=0)
				{
					printf(")");
					if(a2!=0||b2!=0)
						printf("%c",ch);	/*输出'+'运算符号*/
					if(a2==0&&b2==0)
						printf("=");
				} 
		}
	else
	{
		if(b1==1)						/*虚部b1为1时，直接打印i即可 */
				{
					printf("i)");
					if(a2!=0||b2!=0)
						printf("%c",ch);	/*输出'+'运算符号*/
					if(a2==0&&b2==0)
						printf("%c0=",ch);
				}
			else
				{
					printf("%.2f",b1); 
					printf("i)");
					if(a2!=0||b2!=0)
						printf("%c",ch);	/*输出'+'运算符号*/
					else
						printf("%c0=",ch);
				}
	}
	if(a1==0&&b1==0)						/*防止出现0*xx等的情况*/
		printf("0%c",ch);		
	if(a2==0)							/*判断第二个复数的实部是否为0 */ 
	{
		if(b2!=0) 
			printf("(");
	}
	else
	{
		printf("(");
			printf("%.2f",a2);
			if(b2>0)					//虚部b2大于0时,才需要打印+号 
				printf("+");
	}
	
	if(b2==0)						/*判断第二个复数的虚部是否为0 */
	{
		if(a2!=0)
				printf(")=");
	}
	else
	{
		if(b2==1)					//虚部b1为1时，直接打印i即可 
				printf("i)=");
			else
				{
					printf("%.2f",b2); 
					printf("i)=");
				}
	}
} 
