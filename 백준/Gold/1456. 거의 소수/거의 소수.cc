#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

ll a, b, res, range;
bool isPrime[10000001];
vector<ll> primes;

void calcPrime() {
    isPrime[1] = true;
    for(ll i=2;i<range;i++) {
        if(!isPrime[i]) {
            primes.push_back(i);
            for(ll j=i+i;j<range;j+=i) {
                isPrime[j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    range = sqrt(b)+1;
    
    calcPrime();

    for(ll p : primes) {
        for(ll i=p*p ; i<=b; i*=p) {
            if(i >= a)  res++;
            if(i > b/p)break;
        }
    }

    cout << res;
    return 0;
}
