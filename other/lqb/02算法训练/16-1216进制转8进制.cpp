#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100000

void saveB(char *b,char c3,char c2,char c1,char c0,int start)
{
	b[start]=c3;
	b[start+1]=c2;
	b[start+2]=c1;
	b[start+3]=c0;
}
int htob(char *h,char *b)
{
	int i,j;
	int hl=strlen(h);
	for(i=0;i<hl;i++)
		switch(h[i])
		{
			case '0':
				{
					saveB(b,'0','0','0','0',4*i);
					break;
				}
			case '1':
				{
					saveB(b,'0','0','0','1',4*i);
					break;
				}
			case '2':
				{
					saveB(b,'0','0','1','0',4*i);
					break;
				}
			case '3':
				{
					saveB(b,'0','0','1','1',4*i);
					break;
				}
			case '4':
				{
					saveB(b,'0','1','0','0',4*i);
					break;
				}
			case '5':
				{
					saveB(b,'0','1','0','1',4*i);
					break;
				}
			case '6':
				{
					saveB(b,'0','1','1','0',4*i);
					break;
				}
			case '7':
				{
					saveB(b,'0','1','1','1',4*i);
					break;
				}
			case '8':
				{
					saveB(b,'1','0','0','0',4*i);
					break;
				}
			case '9':
				{
					saveB(b,'1','0','0','1',4*i);
					break;
				}
			case 'A':
				{
					saveB(b,'1','0','1','0',4*i);
					break;
				}
			case 'B':
				{
					saveB(b,'1','0','1','1',4*i);
					break;
				}
			case 'C':
				{
					saveB(b,'1','1','0','0',4*i);
					break;
				}
			case 'D':
				{
					saveB(b,'1','1','0','1',4*i);
					break;
				}
			case 'E':
				{
					saveB(b,'1','1','1','0',4*i);
					break;
				}
			case 'F':
				{
					saveB(b,'1','1','1','1',4*i);
					break;
				}
		}
	return 4*hl;
}
int btoo(char *b,char *o,int bl)
{
	int i,j;
	int ol;
	int value;
	if(bl%3==0)
		ol=bl/3;
	else
		ol=bl/3+1;
	j=bl-1;
	for(i=ol-1;i>=0;i--)
	{
		if(i>0)
			o[i]=b[j]-48+(b[j-1]-48)*2+(b[j-2]-48)*4+48;
		else
		{
			switch(j)
			{
				case 2:
					o[i]=b[j]-48+(b[j-1]-48)*2+(b[j-2]-48)*4+48;
					break;
				case 1:
					o[i]=b[j]-48+(b[j-1]-48)*2+48;
					break;
				case 0:
					o[i]=b[j];
					break;
			}

		}
		j=j-3;
	}
	return ol;
}
void printO(char *o,int ol)
{
	int i=0;
	if(o[0]=='0')
		i=1;
	for(;i<ol;i++)
	{
		printf("%c",o[i]);
	}
	printf("\n");
}
int main()
{
	char h[MaxSize];
	char b[4*MaxSize];
	char o[4*MaxSize/3+1];
	int n,i,bl,ol;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(h);
		bl=htob(h,b);
		ol=btoo(b,o,bl);
		
		printO(o,ol);
	}
	return 0;
}
