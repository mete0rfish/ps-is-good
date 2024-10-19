#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

double a, b;
bool prime[18];
double dp[19][19][19];
double res;

double func(int cnt, int a_goal, int b_goal) {
    if (cnt == 18) {
        if (prime[a_goal] || prime[b_goal]) {
            return 1;
        }
        return 0;
    }

    // 이미 계산됐으면 DP return
    if(dp[cnt][a_goal][b_goal] > 0) return dp[cnt][a_goal][b_goal];

    dp[cnt][a_goal][b_goal] += func(cnt + 1, a_goal, b_goal) * (1 - a) * (1 - b);
    dp[cnt][a_goal][b_goal] += func(cnt + 1, a_goal + 1, b_goal) * (a) * (1 - b);
    dp[cnt][a_goal][b_goal] += func(cnt + 1, a_goal, b_goal + 1) * (1 - a) * b;
    dp[cnt][a_goal][b_goal] += func(cnt + 1, a_goal + 1, b_goal + 1) * a * b;

    return dp[cnt][a_goal][b_goal];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prime[2] = true;
    prime[3] = true;
    prime[5] = true;
    prime[7] = true;
    prime[11] = true;
    prime[13] = true;
    prime[17] = true;

    cin >> a >> b;
    a /= 100;
    b /= 100;

    res = func(0, 0, 0);

    cout << res;
    return 0;
}
