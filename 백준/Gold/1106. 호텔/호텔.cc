#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int c, n;
int cost[1001];
int person[1001];
int dp[1101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(dp, dp+1101, 1e9);

    cin >> c >> n;
    for(int i=0;i<n;i++) {
        cin >> cost[i] >> person[i];
        dp[person[i]] = min(dp[person[i]], cost[i]);
    }

    for(int i=1;i<=1100;i++) {
        for(int j=0;j<n; j++) {
            if(i > person[j]) {
                dp[i] = min(dp[i], dp[i-person[j]] + cost[j]);
                // cout << "i : " << i << ", dp[i]: " << dp[i] << endl;
            }
        }
    }

    int res = 1e9;
    for(int i=c;i<=c+100;i++) {
            res = min(res, dp[i]);
    }

    cout << res;

    return 0;
}
