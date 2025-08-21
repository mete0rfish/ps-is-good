#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[121][121];

bool cmp(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> info, int n, int m) {
    int size = info.size();
    fill(&dp[0][0], &dp[120][120], 1e9);
    int res = 1e9;
    
    dp[0][0] = 0;    
    for(int i=1;i<=info.size();i++) {
        int a = info[i-1][0];
        int b = info[i-1][1];
        
        for(int j=0;j<m;j++) {
            // A 선택
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a);
            
            // B 선택
            if(j+b < m) {
                dp[i][j+b] = min(dp[i][j+b], dp[i-1][j]);
            }
        }
    }
    
    for(int i=0;i<m;i++) {
        res = min(res, dp[info.size()][i]);
    }
    res >= n ? res = -1 : res ;
    return res;
}