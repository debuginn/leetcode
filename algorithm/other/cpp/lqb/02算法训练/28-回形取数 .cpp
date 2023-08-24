#include "iostream"
using namespace std;
int main(){
	//定义矩形长宽并接受 
	int m,n;
	cin >> m >> n;
	int a[201][201];
	//接收矩形数组 
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	int i=0;
	int j=0;
	// -1为标识已经读取数值 
	for(int total = 0; total<m*n;){
		//向下读取 
		while(i<=m-1 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			//将读取的值标记为读取 -1
			a[i][j] = -1; 
			i++;
			total++;
		}
		//减去一行 
		i--;
		j++;
		//向右读取 
		while(j<=n-1 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			a[i][j] = -1;
			j++;
			total++;
		}
		//减去一行一列 
		i--;
		j--;
		//向上读取
		while(i>=0 && a[i][j]!=-1){
			cout << a[i][j] << " ";
			a[i][j] = -1;
			i--;
			total++; 
		} 
		//减去一列 
		i++;
		j--;
		//向左读取
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
