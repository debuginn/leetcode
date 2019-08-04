#include "iostream"
#include "algorithm"
using namespace std;
int a[1001], b[1001];

bool cmp(int a, int b){
	return a>b;
} 
int main(){
	int n, m;
	int l, r, k;
	int i, j;
	
	while(cin>>n){
		for(i=0; i<n; i++){
			cin >> a[i];
		}
		
		cin >> m;
		while(m--){
			cin >>l>>r>>k;
			
			for(j=l-1, i=0; j<r; ++j,++i){
				b[i] = a[j];
			}
			
			sort(b, b+i, cmp);
			cout<<b[k-1]<<endl;
		}
	}
	return 0;
}
