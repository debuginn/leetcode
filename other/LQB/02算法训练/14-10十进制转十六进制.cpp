/**
��������
����ʮ�����������ڳ������ʱ����Ҫʹ�õ���һ�������ı�ʾ��ʽ������0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F��16�����ţ�
�ֱ��ʾʮ��������0��15��ʮ�����Ƶļ�����������16��1������ʮ������16��ʮ����������10����ʮ���Ƶ�17��ʮ����������11��
�Դ����ƣ�ʮ���Ƶ�30��ʮ����������1E��
��������һ���Ǹ�������������ʾ��ʮ�����Ƶ���ʽ��
�����ʽ
�����������һ���Ǹ�����a����ʾҪת��������0<=a<=2147483647
�����ʽ
����������������16���Ʊ�ʾ
��������
30
�������
1E
*/
#include "stdio.h" 
#include "stdlib.h"
char data[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//���
void Print(char *num,int n)
{
	int i;
	for(i=n-1;i>=0;i--) 
		printf("%c",num[i]);
	printf("\0");
	printf("\n");
}

//��ʮ��������ת��Ϊʮ������
int Transform(char *num,long long value)
{
	int n=0;
	while(value>=16)
	{
		num[n++]=data[value%16];
		value/=16;
	}
	num[n++]=data[value%16];
	return n;
}

int main()
{
	long long value;
	char num[10];
	int n;
	scanf("%I64d",&value);
	n=Transform(num,value);
	Print(num,n);
	return 0;
}


