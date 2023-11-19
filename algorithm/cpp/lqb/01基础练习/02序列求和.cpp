#include "stdio.h"
int main()
{
    int n;
    long long ret = 0, tmp;
    scanf("%d", &n);
    tmp = n;
    printf("%I64d", (1+tmp) * tmp / 2);
    return 0;
}

