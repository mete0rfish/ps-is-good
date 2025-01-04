#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int N;
long res;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> str;

    for(int i=0;i<str.length();i++) {
        res += ((str[i] - 'a' + 1)*pow(31,i));
    }

    cout << res;


    return 0;
}