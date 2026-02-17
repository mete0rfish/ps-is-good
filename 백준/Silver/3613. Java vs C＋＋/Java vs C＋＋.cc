#include <iostream>
#include <cstring>

using namespace std;

string str;
string res = "";
bool c, j, e;

int main() {
    cin >> str;

    // 기본 에러 체크
    if (str[0] == '_' || ('A' <= str[0] && str[0] <= 'Z') || str[str.length()-1] == '_') {
        cout << "Error!" << endl;
        return 0;
    }

    // 자바 C++ 검증
    for (int i=0;i<str.length();i++) {
        if (str[i] == '_') {
            c = true;
            if (i+1 < str.length() && str[i+1] == '_') e = true; 
        }
        else if ('A' <= str[i] && str[i] <= 'Z') {
            j = true;
        }
    }

    if (c && j) e = true;
    if (e) {
        cout << "Error!" << endl;
        return 0;
    }

    // 각 코드별 파싱
    if (c) {
        for (int i=0;i<str.length();i++) {
            if (str[i] == '_') {
                i++;
                res += (char)(str[i] - 'a' + 'A');
            } else {
                res += str[i];
            }
        }
    } else if (j) {
        for (int i=0;i<str.length();i++) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                res += '_';
                res += (char)(str[i] - 'A' + 'a');
            } else {
                res += str[i];
            }
        }
    } else {
        res = str;
    }

    cout << res;
    return 0;
}