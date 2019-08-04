#include "iostream"
using namespace std;
int main(){
	string a[20];
	a[0]  = "zero";
	a[1]  = "one";
	a[2]  = "two";
	a[3]  = "three";
	a[4]  = "four";
	a[5]  = "five";
	a[6]  = "six";
	a[7]  = "seven";
	a[8]  = "eight";
	a[9]  = "nine";
	a[10] = "ten";
	a[11] = "eleven";
	a[12] = "twelve";
	a[13] = "thirteen";
	a[14] = "fourteen";
	a[15] = "fifteen";
	a[16] = "sixteen";
	a[17] = "seventeen";
	a[18] = "eighteen";
	a[19] = "nineteen";
	string b[] = {"twenty", "thirty", "forty", "fifty"}; 
	
	int h, m;
	cin >> h >> m;
	int h1 = h/10;
	int h2 = h%10;
	int m1 = m/10;
	int m2 = m%10;
	//cout << h1 << " " << h2 << " " << m1 << " " << m2 << endl;
	
	if(m==0){
		if(h<20){
			cout << a[h] << " o'clock";
		}
		if(h>=20 && h2==0){
			cout << b[h1-2] << " o'clock";
		}
		if(h>=20 && h2!=0){
			cout << b[h1-2] << " " << a[h2] << " o'clock";
		}
	}else{
		if(h==0){
			if(m<20){
				cout << a[0] << " " << a[m];
			}
			if(m>=20 && m2==0){
				cout << a[0] << " " << b[m1-2];
			}
			if(m>=20 && m2!=0){
				cout << a[0] << " " << b[m1-2] << " " << a[m2];
			}
		}
		if(h!=0){
			if(m<20 && h<20){
				cout << a[h] << " " << a[m];
			}
			if(m>=20 && h<20 && h2!=0){
				cout << a[h] << " " << b[m1-2] << " " << a[m2];
			}
			if(m>=20 && h<20 && h2==0){
				cout << b[h1-2] << " " << b[m1-2] << " " << a[m2];
			}
			if(m>=20 && m2==0 && h>=20 && h2==0){
				cout << b[h1-2] << " " << b[m1-2];
			}
			if(m>=20 && m2!=0 && h>=20 && h2==0){
				cout << b[h1-2] << " " << b[m1-2] << " " << a[m2]; 
			}
			if(m>=20 && m2==0 && h>=20 && h2!=0){
				
				cout << b[h1-2] << " " << a[h2] << " " << b[m1-2];
			}
			if(m>=20 && m2!=0 && h>=20 && h2!=0){
				cout << b[h1-2] << " " << a[h2] << " " << b[m1-2] << " " << a[m2];
			}
		}
	}
	
	return 0;
}
