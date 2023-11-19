#include "stdio.h"
#define MOD 10007
#define MAX 1000001
int i, j ,F[MAX];
int main(){
	scanf("%d",&j);
	F[1] = 1;
	F[2] = 1;
	for(i=3; i<=j; i++)
		F[i] = (F[i-1]+F[i-2]) % MOD;
	printf("%d",F[j]);
	return 0;
}
 
