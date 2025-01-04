#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int N, M, res;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin >> str;

    for(int i=0;i<M-2;i++) {
        int len = 0;
        if(str[i] == 'I') {
            while(str[i+1] == 'O' && str[i+2] == 'I') {
                len++;
                i+=2;
                if(len == N) {
                    len--;
                    res++;
                }
            }
        }
    }

    cout << res;

    return 0;
}