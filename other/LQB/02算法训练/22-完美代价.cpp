#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int j = n-1;
	int count=0;  //������¼��ֵ
	int flag = 0; //�����ж��Ƿ��Ѿ�������һ����������������ַ� 
	for(int i=0; i<j; i++){        //���������һ����ֵ����Ϊ��Ҫ���н�\o�����ų� 
		for(int k=j; k>=i; k--){   //�ӵ�һ���������Ѱ�ң�һֱ�ҵ�s[i]==s[k] 
			if(k==i){              //�����ǰû��ƥ�䵽���Ѿ�ƥ�������һ�� 
				if(n%2==0 || flag==1){ //�����ǰ�ַ���Ϊż���������Ѿ���һ����������������ַ� 
					cout << "Impossible";
					return 0;
				} 
				flag = 1;
				count += n/2 - i;
			}else if(s[k] == s[i]){ //�����ǰ�Ѿ��ҵ�����ͬ�ַ��Ļ� 
				for(int l=k; l<j; l++){ //��ʼ���ַ�����Ϊ�ԳƸ�ʽ 
					swap(s[l], s[l+1]); //�������� 
					count++;            //���� 
				}
				j--;   //����ǰ�ַ���λ��-1 
				break; //�˳���ǰѭ�� 
			}
		}
	} 
	cout << count;
	return 0;
}
