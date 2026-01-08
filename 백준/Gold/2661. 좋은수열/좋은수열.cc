#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int N;

bool isValid(string s) {
    int len = s.length();
    int mx_len = s.length()/2;

    for (int i=1; i<=mx_len; i++) {
        string tail = s.substr(len-i, i);
        string front = s.substr(len-i*2, i);

        if (tail == front) {
            return false;
        }
    }
    return true;
}

string solution(int cnt, string s) {
    if (cnt == N) {
        return s;
    }

    for (int i=1;i<=3;i++) {
        string next_s = s + to_string(i);

        if (isValid(next_s)) {
            string res = solution(cnt+1, next_s);

            if (res != "") return res;
        }
    }

    return "";
}

int main() {
    cin >> N;

    cout << solution(0, "");
    return 0;
}
