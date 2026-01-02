#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
// 0 1 2 3 : 위 우 아 좌
// dp[i][j] = 현재 에너지가 j 남앗을 때 i 방향일 때

int dp[1000001][4];

int solution(int A, int B, int C, int K) {
    fill(&dp[0][0], &dp[0][0] + (1000001 * 4), 1e9);

    dp[0][0] = 0;
    int costs[3] = {A, B, C};
    int dirs[3] = {3, 1, 2};

    for (int i=1;i<=K;i++) { // 현재 에너지
        for (int d=0;d<4;d++) { // 현재 방향
            for (int j=0;j<3;j++) { // 이전 방향
                int prev_cost = i - costs[j];
                int prev_dir = (d - dirs[j] + 4) % 4;

                if (prev_cost < 0) continue;
                if (dp[prev_cost][prev_dir] == 1e9) continue;

                dp[i][d] = min(dp[i][d], dp[prev_cost][prev_dir] + 1);
            }
        }   
    }

    return dp[K][0] == 1e9 ? -1 : dp[K][0];
}

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    cout << solution(A, B, C, K);

    return 0;
}
