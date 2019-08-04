#include "stdio.h"
int main(){
	int year;
	scanf("%d",&year);
	if(year>=1990 && year<=2050){
		if((year%4==0 && !(year%100==0)) || year%400==0){
			printf("yes");
		}else{
			printf("no");
		}
	}else{
		printf("no");
	}
	return 0;
}
