#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int res = 0;

void dfs(int cur, int cnt, vector<bool> vst, vector<vector<int>>& dungeons) {
    
    res = max(res, cnt);
    
    for (int i=0;i<N;i++) {
        if (vst[i]) continue;
        if (dungeons[i][0] > cur) continue;
        
        vst[i] = true;
        dfs(cur - dungeons[i][1], cnt+1, vst, dungeons);
        vst[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    N = dungeons.size();
    
    vector<bool> vst(N, false);
    dfs(k, 0, vst, dungeons);
    return res;
}