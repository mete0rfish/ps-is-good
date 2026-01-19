#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int res;
set<int> s;

bool isSame(string a, string b) {
    if (a.length() != b.length()) return false;
    
    for (int i=0;i<a.length();i++) {
        if (b[i] == '*') continue;
        
        if (a[i] != b[i]) return false;
    }
    return true;
}

void dfs(int banned_idx, vector<bool> vst, vector<string> user_id, vector<string> banned_id) {
    if (banned_idx == banned_id.size()) {
        int tmp = 0;
        for (int i=0;i<vst.size();i++) {
            if (vst[i]) tmp |= (1<<i);
        }
        s.insert(tmp);
        return;
    }
    
    for (int i=0;i<user_id.size();i++) {
        if (vst[i]) continue;
        
        string user = user_id[i];
        if (!isSame(user, banned_id[banned_idx])) continue;
        
        vst[i] = true;
        dfs(banned_idx+1, vst, user_id, banned_id);
        vst[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 1;
    vector<bool> vst(user_id.size(), false);
    dfs(0, vst, user_id, banned_id);
    
    return s.size();
}