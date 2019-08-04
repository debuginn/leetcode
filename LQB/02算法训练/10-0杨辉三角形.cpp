#include "stdio.h"
#define MAXV 34
int a[MAXV][MAXV]; 
int main(){
	int n;
	int i, j;
	scanf("%d",&n);
	if(n>=1 && n<=34){
		for(i=0; i<n; i++){
			for(j=0; j<=i; j++){
				//判断是不是第一个并且判断是不是最后一个
				//初始第一个也是声明为1 
				if(j==0 || i==j){
					a[i][j]=1;
				}else{
					a[i][j] = a[i-1][j-1] + a[i-1][j];
				}
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<=i; j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("error");
	}	
	return 0;
} 
