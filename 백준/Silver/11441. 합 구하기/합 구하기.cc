#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
long long dp[250001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        long long a; cin >> a;
        dp[i] = dp[i-1] + a;
    }

    cin >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        cout << dp[b] - dp[a-1] << "\n";
    }
    return 0;
}