#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int t;
string n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        int a=0, b=0;
        for(int i=0;i<n.length();i++) {
            if(n[i] != m[i]) {
                if(n[i] == '0') a++;
                else b++;
            }
        }
        cout << max(a,b) << "\n";
    }

    return 0;
}
