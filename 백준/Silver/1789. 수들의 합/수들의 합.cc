#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

long long S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S;
    int idx = 0;

    while(S > 0) {
        idx++;
        S-=idx;
    }
    if(S < 0) idx--;
    cout << idx;
}
