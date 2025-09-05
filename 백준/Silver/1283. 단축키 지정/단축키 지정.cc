#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N;
int isUsed[27];

void print(string str, int idx) {
    for(int i=0;i<str.length();i++) {
        if(i == idx) cout << "[";
        cout << str[i];
        if(i == idx) cout << "]";
    }
    cout << "\n";
}

void vector_print(const vector<string>& v, int a) {
    for(int i =0;i<v.size();i++) {
        if(i == a) {
            print(v[i], 0);
        }
        else {
            print(v[i], -1);
        }
    }
}

int main() {
    cin >> N;
    cin.ignore();
    while(N--) {
        string str;
        getline(cin, str);

        bool flag = false;
        int found_idx = -1;

        if(!isUsed[tolower(str[0]) - 'a']) {
            found_idx = 0;
        }
        else {
            for(int i=1;i<str.length();i++) {
                if(str[i-1] == ' ' && !isUsed[tolower(str[i])-'a']) {
                    found_idx = i;
                    break;
                }
            }
        }

        // 1. 단어 첫 마디 찾기
        if(found_idx != -1) {
            isUsed[tolower(str[found_idx]) - 'a'] = true;
            flag = true;
        }
        // 2. 순서대로 조회
        else {
            for(int i=0;i<str.length();i++) {
                if(str[i] != ' ' && !isUsed[tolower(str[i]) - 'a']) {
                    found_idx = i;
                    isUsed[tolower(str[i]) - 'a'] = true;
                    flag = true;
                    break;
                }
            }
        }

        if(flag) {
            for(int i=0;i<str.length();i++) {
                if(i == found_idx) {
                    cout << "[" << str[found_idx] << "]";
                }
                else {
                    cout << str[i];
                }
            }
            cout << "\n";
        }
        else {
            cout << str << "\n";
        }
    }
    
    return 0;
}