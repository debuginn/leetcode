#include "iostream"
using namespace std;
int main(){
	// v1 ���ӵ��ٶ�
	// v2 �ڹ���ٶ�
	// t  �������ȵľ���
	// s  ��Ϣ��ʱ��
	// L  �����ĳ��� 
	int v1, v2, t, s, L;
	int s1=0, t1=0, s2=0, t2=0;
	cin>> v1 >> v2 >> t >> s >> L;
	//ʱ���ʼ����һ�� 
	t1 += 1;
	t2 += 1;
	//����ʱ���һ�룬����ֱ��ߵľ��� 
	s1 = s1+v1;
	s2 = s2+v2;
	while(true){
		//���ڹ������ͬʱ�����յ� 
		if(s1==L && s2==L){
			cout << "D" <<endl;
			cout << t1 << endl;
			break;
		}
		//���ӵ������յ�
		if(s1==L){
			cout << "R" <<endl;
			cout << t1 <<endl;
			break;
		} 
		//�ڹ��ȵ����յ�
		if(s2==L){
			cout << "T" <<endl;
			cout << t2 <<endl;
			break;
		} 
		//�ж��߼��﷨
		//�����ʱ����֮��ľ������t�� 
		if(s1-s2 >= t){
			t1 += s;
			for(int i=1; i<=s; i++){
				t2 += 1;
				s2 += v2;
				if(s2==L){
					cout<<"T"<<endl;
					cout<<t2<<endl;
					exit(0);
				}
			} 
			//������һ��һ����ʱ���� 
		} else{
			t1 += 1;
			t2 += 1;
			s1 = s1+v1;
			s2 = s2+v2;
		}
	}
	return 0;
} 
