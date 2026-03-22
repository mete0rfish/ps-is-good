#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long dp[50001];

int main() 
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i=4;i<=n;i++) {
        dp[i] = (dp[i-1] + dp[i-3]) % 1000000009;
    }

    cout << dp[n];

    return 0;
}