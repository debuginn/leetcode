#include "iostream"
using namespace std;
#define A 20
int a[A][A];
int main(){
	int n;
	int i, j;
	cin >> n;
	//������ĿҪ��Χ 
	if(n>=2 && n<=20){
		//�������� 
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				cin>>a[i][j];
			}
		} 
		//�ж��߼�		
		for(i=0; i<n; i++){
			int cun=0;
			for(j=0; j<n; j++){
				//��i��=j��ɸѡ���� 
				if(j != i){
					cun += a[j][i];
				}
			}
			//�жϲ�����к� 
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
