#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

map<string, vector<string>> mp;
map<string, vector<bool>> vst;

bool dfs(string cur, int ticket_cnt, vector<string>& path) {

    if (path.size() == ticket_cnt+1) {
        return true;
    }
    
    for (int i=0;i<mp[cur].size();i++) {
        if (vst[cur][i]) continue;
        
        string next = mp[cur][i];
        
        vst[cur][i] = true;
        path.push_back(next);
        
        if (dfs(next, ticket_cnt, path)) return true;
        
        path.pop_back();
        vst[cur][i] = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    for (auto t : tickets) {
        string from = t[0];
        string to = t[1];
        
        mp[from].push_back(to);
    }
    
    for (auto& r : mp) {
        sort(r.second.begin(), r.second.end());
        vst[r.first].assign(r.second.size(), false);
    }
    
    vector<string> path;
    path.push_back("ICN");
    dfs("ICN", tickets.size(), path);
    
    return path;
}