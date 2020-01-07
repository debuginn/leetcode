#include "stdio.h"
#define MAX 100001
int a[MAX];
int main(){
	int n, m;
	int i, j, k, result=0;
	scanf("%d",&n);
	if(n>=1 && n<=1000){
		for(m=0; m<n; m++){
			scanf("%d",&a[m]);
		}
		scanf("%d",&k);
		for(j=0; j<n; j++){
			if(k == a[j]){
				result++; 
			}	
		}
		if(result>0){
			printf("%d",result); 
		}else{
			printf("-1");
		}
		
	}else{
		printf("error");
	}
	return 0;
}
