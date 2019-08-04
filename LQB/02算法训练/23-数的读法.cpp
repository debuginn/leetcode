#include "iostream"
#include "string"
using namespace std;
string b[10] = {"ling ", "yi ", "er ", "san ", "si ", "wu ", "liu ", "qi ", "ba ", "jiu "};
string func(string str){
	string ans;
    int lent = str.length();
    if(lent >= 4) {
        ans += b[str[0]-'0'];
        ans += "qian ";
    }
    if(lent >= 3) {
        if(str[lent-3] != '0') {
            ans += b[str[lent-3]-'0'];
            ans += "bai ";
        }
    }
    if(lent >= 2) {
        if(str[lent-2] == '1') {
            if(lent != 2) {
                ans += "yi shi ";
            } else {
                ans += "shi ";
            }
        }
        if(str[lent-2] != '0' && str[lent-2] != '1') {
            ans += b[str[lent-2]-'0'];
            ans += "shi ";
        }
    }
    if(lent >= 1) {
        if(str[lent-1] != '0') {
            ans += b[str[lent-1]-'0'];
        }
    }
    return ans;
}
int main(){
	string s;
    cin >> s;
    int len = s.length();
    string sub;
    if(len == 10) {
        sub = s.substr(0, 2);
        cout << func(sub) << "yi ";
    }
    if(len == 9) {
        sub = s.substr(0, 1);
        cout << func(sub) << "yi ";
    }
    sub = "";
    int flag = 0;
    if(len >= 5) {
        for(int i = len-8; i < len - 4; i++) {
            if(i < 0) continue;
            if(flag == 0 && s[i] == '0') {
                continue;
            }
            sub += s[i];
            flag = 1;
        }
        if(flag == 1) {
            cout << func(sub) << "wan ";
        }
        flag = 0;
        sub = "";
        for(int i = len-4; i < len; i++) {
            if(flag == 0 && s[i] == '0') {
                continue;
            }
            if((i == len-1 && s[i-1] == '0') && (i == len-2 && s[i-1] == '0') && (i == len-3 && s[i-1] == '0'))
                cout << "ling ";
            sub += s[i];
            flag = 1;
        }
    }
    if(len <= 4) {
        sub = s;
        flag = 1;
    }
    if(flag == 1) {
        cout << func(sub);
    }
	return 0;
} 


