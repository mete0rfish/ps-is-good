#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int arr[301][301];
int dp[301][301];

// dp[3][3] = dp[3][2] + dp[2][3] - dp[2][2]

int main() {
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + arr[i][j];
        }
    }

    

    cin >> K;
    while(K--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1] << "\n";
    }
    
    return 0;
}