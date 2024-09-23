#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define ll long long

string a;
string b;
int res = 9999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;

    for(int i=0;i<b.length();i++) {
        if(a.length() +i > b.length()) {
            break;
        }
        int diff = 0;
        for(int j=0;j<a.length();j++) {
            if(a[j] != b[i+j]) {
                diff++;
            }
        }
        res = min(res, diff);
    }
    cout << res;

    return 0;
}
