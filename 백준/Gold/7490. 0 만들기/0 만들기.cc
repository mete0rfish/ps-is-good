#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

char ch[3] = {' ', '+', '-'};

void func(int n, string str, int num) {
    if (num == n) {
        string tmp = "";
        for (int i=0;i<str.length();i++) {
            if (str[i] != ' ') tmp += str[i];
        }

        int sum = 0;
        int sign = 1;
        int cur_num = 0;
        for (int i=0;i<tmp.length();i++) {
            if ('0' <= tmp[i] && tmp[i] <= '9') {
                cur_num = cur_num * 10 + (tmp[i] - '0');
            }
            else {
                sum += sign * cur_num;
                cur_num = 0;
                sign = (tmp[i] == '+') ? 1 : -1;
            }
        }
        sum += sign * cur_num;

        if (sum != 0) return;

        cout << str << '\n';
        return;
    }

    for (int i=0;i<3;i++) {
        func(n, str+ch[i]+to_string(num+1), num+1);
    }

}

int main() 
{
    int T;
    cin >> T;

    for (int i=0;i<T;i++) {
        int N;
        cin >> N;
        func(N, "1", 1);
        cout << "\n";
    }

    return 0;
}

