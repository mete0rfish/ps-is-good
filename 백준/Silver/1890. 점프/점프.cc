#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n;
int px[2] = {0,1};
int py[2] = {1,0};
ll dp[101][101];
int arr[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = 1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j] == 0)  continue;

            int nx = i + arr[i][j];
            int ny = j + arr[i][j];

            if(nx < n) {
                dp[nx][j] += dp[i][j];
            }
            if(ny < n) {
                dp[i][ny] += dp[i][j];
            }
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}
