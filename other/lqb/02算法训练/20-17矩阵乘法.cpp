#include "stdio.h"
int a[35][35];
int b[35][35];
int t[35][35];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    if(m==0)//�����0����Ϊ��λ����
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
        return 0;
    }
    if(m==1)//�����1����Ϊ������
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        return 0;
    }
    while(m>=2)//����2����������Ҫ������
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                int k=n;
                while(k)
                {
                    t[i][j]+=b[i][k-1]*a[k-1][j];
                    k--;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                b[i][j]=t[i][j];
                t[i][j]=0;
            }
        }
        m--;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    return 0;
}
