/*
��������
�����������[a,b]�������������������ֽ⡣
�����ʽ
����������������a��b��
�����ʽ
����ÿ�����һ�����ķֽ⣬����k=a1*a2*a3...(a1<=a2<=a3...��kҲ�Ǵ�С�����)(����ɿ�����)
��������
3 10
�������
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
��ʾ
������ɸ������������Ȼ���ٷֽ⡣
���ݹ�ģ��Լ��
����2<=a<=b<=10000
*/
#include<stdio.h>
#include<math.h>
int prime(int n)  //��֤���� 
{
    int i, x, t;
    t =    (int)(sqrt(n));
    for(i = 2; i <= t; i++)
        if(n%i == 0) return 1;
    return 0;
}
void primetwo(int n)  //�ֽ������� 
{
    int i, a[100], k = 0, t, sum = 1;
    t = n;
    for(i = 2 ; i <= n ; i++)
    {
        if(n % i == 0)
        {
            a[k] = i;
            sum = sum * a[k];
            n = t / sum;           
            i = 1;    k++;                   
        }  
    }
    printf("%d=",t);
    for(i = 0 ; i < k ; i++)
    {
        printf("%d",a[i]);     
        if(i < k - 1) printf("*"); //���һ��û�� * �� 
    }  
    printf("\n");
}
int main()
{      
    int a, b, i;
    scanf("%d%d",&a,&b);
    for(i = a; i <= b; i++)
    {
        if(prime(i))  //�������� 
        {      
            primetwo(i);
        }
        else
        {
            printf("%d=%d\n",i,i);         
        }
    }      
    return 0; 
}
