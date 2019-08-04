#include "stdio.h"
#include "math.h"
int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	if(n>=1 && m<=26){
		for(i=1; i<=n; i++){
			for(j=1; j<=m;  j++){
				printf("%c", abs(i-j)+'A');
			}
			printf("\n");
		}
	}else{
		printf("error");
	} 
	return 0;
}
