#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ll;

bool isprime(int n){
	//如果数值小于等于1并且大于二且为偶数 
	if(n<=1 || (n>2 && n%2==0)){
		return false;		
	}
	//查找最小公倍数对应的偶数序列，是否满足条件 
	for(ll i=3; i*i<=n; i+=2){
		if(n%i==0){
			return false;
		}
	}	
	return true;
}

int main(){
	for(int d = 2; d<1000; d++){
		for(ll  n = 2; n<1000; ++n){
			if(
				isprime(n)
				&& isprime(n + d)
				&& isprime(n + 2*d) 
				&& isprime(n + 3*d)
				&& isprime(n + 4*d)
				&& isprime(n + 5*d)
				&& isprime(n + 6*d)
				&& isprime(n + 7*d)
				&& isprime(n + 8*d)
				&& isprime(n + 9*d)
			){
				cout << d <<endl;
				break;
			}
		}
	}
	return 0;
}
