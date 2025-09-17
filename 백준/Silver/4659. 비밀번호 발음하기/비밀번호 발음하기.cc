#include <iostream>
#include <cstring>

using namespace std;

int P;
int arr[21];

bool isMoum(char c) {
    if(c == 'a' || c=='e' || c == 'i' || c == 'o' || c =='u') {
        return true;
    }
    return false;
}

bool isValid(string str) {
    int moum_cnt = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<str.length();i++) {
        if (isMoum(str[i]))  {
            moum_cnt++;

            if(i!=0 && isMoum(str[i-1])) {
                cnt1++;
            }
            else {
                cnt2=0;
                cnt1++;
            }
        }
        else {
            if(i!=0 && !isMoum(str[i-1])) {
                cnt2++;
            }
            else {
                cnt1=0;
                cnt2++;
            }
        }
        
        
        if(i!=0 && str[i] == str[i-1]) {
            if(str[i] != 'e' && str[i] != 'o') return false;
        }
        
        if(cnt1 >= 3 || cnt2 >= 3) return false;
    }

    if(moum_cnt == 0) return false;
    return true;
}

int main() {
    while(1) {
        string str;
        cin >> str;
        if(str == "end") break;
        
        if (isValid(str)) {
            cout << "<" << str <<"> is acceptable.\n";
        }
        else {
            cout << "<" << str <<"> is not acceptable.\n";
        }
    }
    
    return 0;
}