#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int l, i, t;
}info;

int N;
vector<int> v;
int dp[1001];

int main() {
    cin >> N;
    for (int i=0;i<N;i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    dp[0] = 1;
    for (int i=1;i<N;i++) {
        dp[i] = 1;
        for (int j=0;j<i;j++) {
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int answer = 0;
    for (int i=0;i<N;i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer;

    return 0;
}

