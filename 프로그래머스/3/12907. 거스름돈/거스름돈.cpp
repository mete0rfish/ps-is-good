#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0] = 1;

    // 현재 코인을 통해 만들 수 있는 금액
    for (int m : money) {
        for (int sum = m; sum <=n; sum++) {
            dp[sum] += dp[sum-m];
            dp[sum] %= 1000000007;
        }
        
        
    }
    
    return dp[n];
}