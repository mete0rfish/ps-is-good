#include <iostream>
#include <algorithm>

using namespace std;

// (A)B , A길이 = i, B의 길이 = n-i-2
// dp[n] = dp[]

long long dp[5001];

void init() {
    dp[0] = 1;
    dp[2] = 1;

    for (int n=4;n<=5000;n+=2) {
        for (int i=0;i<=n-2;i+=2) {
            dp[n] = dp[n] + (dp[i] * dp[n-i-2]); 
            dp[n] %= 1000000007;
        }
    }    
}

int main() 
{
    int T, L;
    cin >> T;
    init();

    while (T--) {
        cin >> L;
        cout << dp[L] << "\n";
    }

    return 0;
}