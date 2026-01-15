#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
long long res;
long long dp[101][10][1024]; // 길이가 i일 때
long long DIV = 1000000000;
// 0 : 1
// 1 : 0 || 2 
// dp[2][0] = dp[1][1];

int main() 
{
    cin >> N;

    for (int i=1;i<10;i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i=1;i<N;i++) {
        for (int j=0;j<10;j++) {
            for (int k=0;k<1024;k++) {
                if (dp[i][j][k] == 0) continue;

                // 다음 숫자 = j-1
                if (j > 0) {
                    int next = k | (1 << (j-1));
                    dp[i+1][j-1][next] = (dp[i+1][j-1][next] + dp[i][j][k]) % DIV;
                }

                // 다움 숫자 = j+1
                if (j < 9) {
                    int next = k | (1 << (j+1));
                    dp[i+1][j+1][next] = (dp[i+1][j+1][next] + dp[i][j][k]) % DIV;
                }
            }
        }
    }

    for (int i=0;i<10;i++) {
        res = (res + dp[N][i][1023]) % DIV;
    }
    cout << res;
    return 0;
}
