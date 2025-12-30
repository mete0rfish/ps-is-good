#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2001][2001];

int func(int l, int r, int cnt, vector<int>& vec) {
    if (l > r) return 0;
    if (dp[l][r] != 0) return dp[l][r];

    int cur = max(
        func(l+1, r, cnt+1, vec)+vec[l]*cnt,
        func(l, r-1, cnt+1, vec)+vec[r]*cnt
    );

    return dp[l][r] = cur;
}

int solution(int n, vector<int> vec) {
    int answer = func(0, n-1, 1, vec);
    return answer;
}

int main() {
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    cout << solution(n, vec);

    return 0;
}
