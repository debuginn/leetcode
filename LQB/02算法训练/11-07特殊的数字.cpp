#include "stdio.h"
int main(){
	int i;
	int gw, sw, bw;
	for(i=100; i<=999; i++){
		gw = i%10;
		sw = i/10%10;
		bw = i/100;
		if(i == gw*gw*gw + sw*sw*sw + bw*bw*bw){
			printf("%d\n",i);
		}
	} 
	return 0;
} 
