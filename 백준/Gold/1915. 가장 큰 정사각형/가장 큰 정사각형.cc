#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
char arr[1001][1001];
int dp[1001][1001];
int res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == '0') {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                res = max(dp[i][j], res);
            }
        }
    }

    cout << res*res;

    return 0;
}
