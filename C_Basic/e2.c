//��������:����������߱��ʽ������  
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
			if(b1>0)					//�鲿b1����0ʱ,����Ҫ��ӡ+�� 
				printf("+");
		}

	if(b1==0)							/*�жϵ�һ���������鲿�Ƿ�Ϊ0 */
		{
			if(a1!=0)
				{
					printf(")");
					if(a2!=0||b2!=0)
						printf("%c",ch);	/*���'+'�������*/
					if(a2==0&&b2==0)
						printf("=");
				} 
		}
	else
	{
		if(b1==1)						/*�鲿b1Ϊ1ʱ��ֱ�Ӵ�ӡi���� */
				{
					printf("i)");
					if(a2!=0||b2!=0)
						printf("%c",ch);	/*���'+'�������*/
					if(a2==0&&b2==0)
						printf("%c0=",ch);
				}
			else
				{
					printf("%.2f",b1); 
					printf("i)");
					if(a2!=0||b2!=0)
						printf("%c",ch);	/*���'+'�������*/
					else
						printf("%c0=",ch);
				}
	}
	if(a1==0&&b1==0)						/*��ֹ����0*xx�ȵ����*/
		printf("0%c",ch);		
	if(a2==0)							/*�жϵڶ���������ʵ���Ƿ�Ϊ0 */ 
	{
		if(b2!=0) 
			printf("(");
	}
	else
	{
		printf("(");
			printf("%.2f",a2);
			if(b2>0)					//�鲿b2����0ʱ,����Ҫ��ӡ+�� 
				printf("+");
	}
	
	if(b2==0)						/*�жϵڶ����������鲿�Ƿ�Ϊ0 */
	{
		if(a2!=0)
				printf(")=");
	}
	else
	{
		if(b2==1)					//�鲿b1Ϊ1ʱ��ֱ�Ӵ�ӡi���� 
				printf("i)=");
			else
				{
					printf("%.2f",b2); 
					printf("i)=");
				}
	}
} 
