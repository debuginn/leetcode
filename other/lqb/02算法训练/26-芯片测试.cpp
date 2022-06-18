#include "iostream"
using namespace std;
#define A 20
int a[A][A];
int main(){
	int n;
	int i, j;
	cin >> n;
	//根据题目要求范围 
	if(n>=2 && n<=20){
		//输入数组 
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				cin>>a[i][j];
			}
		} 
		//判断逻辑		
		for(i=0; i<n; i++){
			int cun=0;
			for(j=0; j<n; j++){
				//将i！=j的筛选出来 
				if(j != i){
					cun += a[j][i];
				}
			}
			//判断并输出行号 
			if(cun >= n/2){
				cout<<i+1<<" ";
			}
		} 
		
	}
	else{
		cout<<"Error"<<endl;
	}
	return 0;
}
