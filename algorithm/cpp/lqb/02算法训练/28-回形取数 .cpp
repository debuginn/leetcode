#include "iostream"
using namespace std;
int main(){
	//������γ������� 
	int m,n;
	cin >> m >> n;
	int a[201][201];
	//���վ������� 
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	int i=0;
	int j=0;
	// -1Ϊ��ʶ�Ѿ���ȡ��ֵ 
	for(int total = 0; total<m*n;){
		//���¶�ȡ 
		while(i<=m-1 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			//����ȡ��ֵ���Ϊ��ȡ -1
			a[i][j] = -1; 
			i++;
			total++;
		}
		//��ȥһ�� 
		i--;
		j++;
		//���Ҷ�ȡ 
		while(j<=n-1 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			a[i][j] = -1;
			j++;
			total++;
		}
		//��ȥһ��һ�� 
		i--;
		j--;
		//���϶�ȡ
		while(i>=0 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			a[i][j] = -1;
			i--;
			total++; 
		} 
		//��ȥһ�� 
		i++;
		j--;
		//�����ȡ
		while(j>=0 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			a[i][j] = -1;
			j--;
			total++;
		} 
		i++;
		j++;
	}
	return 0;
}
