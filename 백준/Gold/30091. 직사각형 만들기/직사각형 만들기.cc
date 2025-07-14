#include <iostream>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

int N;
ll arr[2001];


bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, cmp);

    ll tmp;
    ll max_dim = 0;
    map<ll, ll> m; // 둘레, 넓이
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            ll cir = 2*arr[i] + 2*arr[j];
            ll dim = arr[i] * arr[j];
            m[cir] += dim;
            if(m[cir] > max_dim) {
                tmp = cir;
                max_dim = m[cir];
            }
        }
    }
    cout << m[tmp];
    
    return 0;
}