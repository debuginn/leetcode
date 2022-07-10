#incloud "iostream"
using namespace std;
int n, sum;
int s[10][10];
int a[11], b[11];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			scanf("%d",&s[i][j]);
		}
	}
	sum =0;
	dfs(1);
	printf("%d\n",sum);
	return 0;
} 
