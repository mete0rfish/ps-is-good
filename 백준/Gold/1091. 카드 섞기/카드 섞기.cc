#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n;
int p[49];
int s[49];
int before[49];
int after[49];

bool check() {
    for(int i=0;i<n;i++) {
        if(before[i] != p[i])
            return false;
    }
    return true;
}

void init() {
    for(int i=0;i<n;i+=3) {
        for(int j=0;j<3;j++) {
            before[i+j] = j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> p[i];
    }
    for(int i=0;i<n;i++) {
        cin >> s[i];
    }

    init();

    int res = -1;
    for(int cnt =0;cnt<=1e7;cnt++) {
        if(check()) {
            res = cnt;
            break;
        }

        for(int i=0;i<n;i++) {
            //cout << "s[i]: " << s[i] << " before[s[i]]: " << before[s[i]] << endl;
             after[i] = before[s[i]];
        }
        for(int i=0;i<n;i++) {
            before[i] = after[i];
        }
    }

    cout<<res;

    return 0;
}
