#include "iostream"
using namespace std;
int main(){
	// v1 兔子的速度
	// v2 乌龟的速度
	// t  兔子领先的距离
	// s  休息的时间
	// L  赛道的长度 
	int v1, v2, t, s, L;
	int s1=0, t1=0, s2=0, t2=0;
	cin>> v1 >> v2 >> t >> s >> L;
	//时间初始化第一步 
	t1 += 1;
	t2 += 1;
	//根据时间第一秒，动物分别走的距离 
	s1 = s1+v1;
	s2 = s2+v2;
	while(true){
		//当乌龟和兔子同时到达终点 
		if(s1==L && s2==L){
			cout << "D" <<endl;
			cout << t1 << endl;
			break;
		}
		//兔子到达了终点
		if(s1==L){
			cout << "R" <<endl;
			cout << t1 <<endl;
			break;
		} 
		//乌龟先到达终点
		if(s2==L){
			cout << "T" <<endl;
			cout << t2 <<endl;
			break;
		} 
		//判断逻辑语法
		//如果此时两个之间的距离大于t了 
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
			//否则按照一步一步的时间来 
		} else{
			t1 += 1;
			t2 += 1;
			s1 = s1+v1;
			s2 = s2+v2;
		}
	}
	return 0;
} 
