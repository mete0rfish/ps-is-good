#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long
using namespace std;

ll T, N;

void func(ll exp) {
    ll res = 0;
    ll left = 1;
    ll right = 1000000000;
    while(left <= right) {
        ll level = (left + right) / 2;
        ll requiredExp = level * (level + 1);
        
        if(requiredExp == exp) {
            cout << level + 1 << endl;
            return;
        }
        else if (requiredExp < exp) {
            left = level + 1;
            res = max(res , level);
        }
        else {
            right = level - 1;
        }
    }
    cout << res + 1 << "\n";
}

int main() {
    cin >> T;
    
    while(T--) {
        cin >> N;
        ll exp = N * (N+1) / 2; 
        func(exp);
    }

    return 0;
}