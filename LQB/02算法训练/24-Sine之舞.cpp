#include "iostream"
using namespace std;
void An(int n){
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("sin(%d",i);
		if(i%2 != 0 && i != n)
			printf("-");
		if(i%2 ==0 && i != n)
			printf("+");
	}
	for(i = 0; i < n; i++)
		printf(")");
}
void Sn(int n){
	int i, d;
	d = n;
	for(i = 0; i < n-1; i++)
		printf("(");
	for(i = 1; i <= n; i++)
	{
		An(i);
		printf("+%d", d);
		if(d != 1)
			printf(")");
		d--;
	}
}
int main(){
	int n;
	cin >> n;
	Sn(n); 
	return 0;
} 
