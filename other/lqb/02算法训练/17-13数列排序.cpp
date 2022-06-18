#include "stdio.h"
#define MAX 200
int a[MAX];
int main(){
	int n;
	int i, j, t;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	//Ã°ÅÝÅÅÐò 
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
