#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

ll k, n, p, x, y;
vector<ll> v;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> p;
        ll tmp = 0;
        while(p--) {
            cin >> x >> y;
            tmp = max(tmp, x*x + y*y);
        }
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    
    cout << v[k-1] << ".00";
    
    return 0;
}