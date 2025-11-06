#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> es[17];
bool vst[18];
int answer;

void dfs(vector<int>& info, vector<int> gotos, int idx, int cnt0, int cnt1) {
    if (info[idx] == 0) cnt0 = cnt0 + 1;
    else cnt1 = cnt1 + 1;
    
    if (cnt1 >= cnt0) return;
    
    cout << gotos.size() << " ";
    cout << idx << endl;
    answer = max(answer, cnt0);
    
    gotos.insert(gotos.begin(), es[idx].begin(), es[idx].end());
    auto iter = find(gotos.begin(), gotos.end(), idx);
    if(iter != gotos.end()) {
        gotos.erase(iter);
    }
    
    for(auto g : gotos) {
        dfs(info, gotos, g, cnt0, cnt1);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto e : edges) {
        es[e[0]].push_back(e[1]);
    }
    
    vst[0] = true;
    vector<int> gotos;
    dfs(info, gotos, 0, 0, 0);
    
    return answer;
}