/*
问题描述
　　求出区间[a,b]中所有整数的质因数分解。
输入格式
　　输入两个整数a，b。
输出格式
　　每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)
样例输入
3 10
样例输出
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
提示
　　先筛出所有素数，然后再分解。
数据规模和约定
　　2<=a<=b<=10000
*/
#include<stdio.h>
#include<math.h>
int prime(int n)  //验证素数 
{
    int i, x, t;
    t =    (int)(sqrt(n));
    for(i = 2; i <= t; i++)
        if(n%i == 0) return 1;
    return 0;
}
void primetwo(int n)  //分解质因数 
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
        if(i < k - 1) printf("*"); //最后一个没有 * 号 
    }  
    printf("\n");
}
int main()
{      
    int a, b, i;
    scanf("%d%d",&a,&b);
    for(i = a; i <= b; i++)
    {
        if(prime(i))  //不是素数 
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
