#include<stdio.h>
#include<string.h> 
#include<math.h>
int main()
{ 
	double sum=0,x;
	char a[8];
	int len,i=0;
	gets(a);
	len=strlen(a);
	while(len)
	{
		if(a[len-1]>='A'&&a[len-1]<='F')
			x=(a[len-1]-'7')*pow(16,i++);
		else
		  	x=(a[len-1]-'0')*pow(16,i++);
		sum+=x;
		len--;
	}
	printf("%.0lf",sum);
	return 0;
} 
