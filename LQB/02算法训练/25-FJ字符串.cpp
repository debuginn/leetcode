#include "iostream"
#include "string"
using namespace std; 
int main(){
	int i, n;
	string temp; 
	string a[26];
	a[1] = 'A';
	cin>>n;
	for(i=2; i<=n; i++){
		temp = 64+i;
		a[i] = a[i-1]+temp+a[i-1];
	} 
	cout<<a[n];
	return 0;
}
