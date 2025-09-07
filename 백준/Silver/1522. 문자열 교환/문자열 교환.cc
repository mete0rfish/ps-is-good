#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string str;
int N;
int res = 1e9;
int cnt;

void finds() {
    int b_cnt = 0;
    for(int i=0;i<cnt;i++) {
        if(str[i] == 'b'){
            b_cnt++;
        }
    }

    res = b_cnt;
    
    for(int i=1;i<N;i++) {
        if(str[i-1] == 'b') b_cnt--;
        if(str[i+cnt-1] == 'b') b_cnt++;
        
        res = min(res, b_cnt);
    }
}

int main() {
    cin >> str;
    N = str.length();
    
    for(int i=0;i<str.length();i++) {
        if(str[i] == 'a') {
            cnt++;
        }
    }

    if(cnt == 0) {
        cout << 0;
        return 0;
    }

    str += str;
    
    finds();

    cout << res;
    
    return 0;
}