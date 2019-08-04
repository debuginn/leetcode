#include "stdio.h"
#include "math.h" 
int main(){
	int r;
	double P;
	P = atan(1.0)*4;
	double s;
	scanf("%d",&r);
	s = r*r*P;
	printf("%.7f",s);
	return 0;
}
