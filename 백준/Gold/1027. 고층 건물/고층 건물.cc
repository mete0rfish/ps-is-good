#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

ll n;
ll res;
ll b[51], cnt[51];

bool check(ll s, ll e) {
    for(ll i=s+1;i<e;i++) {
        if(
            (b[e]-b[s])*(i-s) <= (b[i]-b[s])*(e-s)
        ) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(ll i=0;i<n;i++) {
        cin >> b[i];
    }

    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            if(check(i,j)) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    cout << *max_element(cnt, cnt+50);

    return 0;
}
