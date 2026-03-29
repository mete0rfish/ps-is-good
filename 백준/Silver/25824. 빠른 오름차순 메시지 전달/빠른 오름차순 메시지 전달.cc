#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[13][13];
int dp[13];

int main() 
{
    for (int i=1;i<=12;i++) {
        for (int j=1;j<=12;j++) {
            cin >> arr[i][j];
        }
    }

    dp[1] = arr[2][1];
    dp[2] = arr[1][2];

    for (int i=3;i<=11;i+=2) {
        dp[i] = min(dp[i-2]+ arr[i-2][i+1] + arr[i+1][i], dp[i-1]+arr[i-1][i+1]+arr[i+1][i]);
        dp[i+1] = min(dp[i-2]+arr[i-2][i]+arr[i][i+1], dp[i-1]+arr[i-1][i]+arr[i][i+1]);

    }

    cout << min(dp[11], dp[12]);

    return 0;
}