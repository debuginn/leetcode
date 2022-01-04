#include "stdio.h"
int main(){
	int max = -10000;
	int min = 10000;
	int sum = 0;
	int n, m, i;
	scanf("%d",&n);
	if(n>=1 && n<=10000){
		for(m=1; m<=n; m++){
			scanf("%d",&i);
			if(i>max){
				max = i;
			}
			if(i<min){
				min = i;
			}
			sum += i;	
		}
		printf("%d\n%d\n%d\n", max, min, sum);
	}else{
		printf("error");
	} 
	return 0;
}
