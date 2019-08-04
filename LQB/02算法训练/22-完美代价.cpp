#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int j = n-1;
	int count=0;  //用来记录数值
	int flag = 0; //用来判断是否已经存在有一个单独的奇个数的字符 
	for(int i=0; i<j; i++){        //遍历到最后一个数值，因为需要进行将\o进行排除 
		for(int k=j; k>=i; k--){   //从第一个往后进行寻找，一直找到s[i]==s[k] 
			if(k==i){              //如果当前没有匹配到，已经匹配至最后一个 
				if(n%2==0 || flag==1){ //如果当前字符串为偶数个或者已经有一个单独的奇个数的字符 
					cout << "Impossible";
					return 0;
				} 
				flag = 1;
				count += n/2 - i;
			}else if(s[k] == s[i]){ //如果当前已经找到了相同字符的话 
				for(int l=k; l<j; l++){ //开始将字符配置为对称格式 
					swap(s[l], s[l+1]); //交换函数 
					count++;            //计数 
				}
				j--;   //将当前字符串位数-1 
				break; //退出当前循环 
			}
		}
	} 
	cout << count;
	return 0;
}
