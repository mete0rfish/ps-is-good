#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

bool isNotPrime[250001];

void checkPrime() {
    for(int i=2;i<=250000;i++) {
        if(isNotPrime[i])  continue;

        for(int j=i+i;j<=250000;j+=i) {
            isNotPrime[j] = true;
        }
    }
}

void countPrime(int s, int e) {
    int cnt = 0;
    for(int i = s+1;i<=e;i++) {
        if (!isNotPrime[i]) cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    checkPrime();


    while(1) {
        int tmp;
        cin >> tmp;
        if(tmp == 0)    break;

        countPrime(tmp, 2*tmp);
    }
}
