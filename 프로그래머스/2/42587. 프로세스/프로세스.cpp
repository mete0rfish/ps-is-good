#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<int> v;
    for(int i=0;i<priorities.size();i++) {
        v.push_back(priorities[i]);
    }
    
    sort(v.begin(), v.end(), greater());
    
    queue<pair<int, int>> q;
    for(int i=0;i<priorities.size();i++) {
        q.push({priorities[i], i});
    }
    
    int v_idx = 0;
    while (!q.empty()) {
        int cur_priority = q.front().first;
        int cur_idx = q.front().second;
        q.pop();
        
        if (cur_priority == v[v_idx]) {
            answer++;
            
            if(cur_idx == location) {
                return answer;
            }
            
            v_idx++;
        } else {
            q.push({cur_priority, cur_idx});
        }
    }
    
    return answer;
}