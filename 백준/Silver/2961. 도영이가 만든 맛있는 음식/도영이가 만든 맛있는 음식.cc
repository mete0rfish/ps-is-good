#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int res = 1e9;
vector<pair<int, int>> taste;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0;i<N;i++) {
        int s, b;
        cin >> s >> b;
        taste.push_back(make_pair(s, b));
    }

    for(int idx=1;idx<(1 << N);idx++) {
        int totalS = 1;
        int totalB = 0;

        for(int i=0;i<N;i++) {
            if(!(idx & (1<<i)))continue;
            totalS *= taste[i].first;
            totalB += taste[i].second;
        }
        
        res = min(res, abs(totalS - totalB));
    }

    cout << res;
    return 0;
}