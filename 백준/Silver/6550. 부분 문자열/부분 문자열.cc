#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    while(cin >> a >> b) {

        int i = 0;
        for(int j=0;i < a.length() &&j<b.length();j++) {
            if(a[i] == b[j]) {
                i++;
            }
        }

        if(i == a.length()) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}