#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, X;
int dp[250001];

int main() {
    cin >> N >> X;
    for(int i=1;i<=N;i++) {
        int a; cin >> a;
        dp[i] = dp[i-1] + a;
    }

    int res = 0;
    int cnt = 0;
    for(int i=X; i<=N;i++) {
        int cur_sum = dp[i] - dp[i-X];

        if(cur_sum > res) {
            res = cur_sum;
            cnt=1;
        }
        else if (cur_sum == res){
            cnt++;
        }
    }
    if(res != 0) cout << res << "\n" << cnt;
    else cout << "SAD";
    return 0;
}