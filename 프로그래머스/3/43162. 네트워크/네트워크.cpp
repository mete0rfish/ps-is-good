#include <string>
#include <vector>

using namespace std;

bool vst[201];

void dfs(int cur, int n, vector<vector<int>> computers) {
    for (int i=0;i<computers[cur].size();i++) {
        if (i == cur) continue;
        if (computers[cur][i] == 0) continue;        
        if (vst[i]) continue;
        
        vst[i] = true;
        dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0;i<n;i++) {
        if (vst[i]) continue;
        
        answer++;
        dfs(i, n, computers);
    }
    
    return answer;
}