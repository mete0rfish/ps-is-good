#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

stack<string> stk;
vector<pair<int, string>> v;
map<string, int> mp; // name, 남은 시간

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    for(int i=0;i<plans.size();i++) {
        string name = plans[i][0];
        int start_time = stoi(plans[i][1].substr(0, 2))*60 + stoi(plans[i][1].substr(3,2));
        int do_time = stoi(plans[i][2]);
        
        v.push_back({start_time, name});
        mp[name] = do_time;
    }
    
    sort(v.begin(), v.end());
    
    int cur_time = v[0].first;
    
    for(int i=0;i<v.size();i++) {
        int cur_start = v[i].first;
        string cur_name = v[i].second;
        
        int time_gap = cur_start - cur_time;
        
        if (time_gap > 0) {
            while(!stk.empty() && time_gap > 0) {
                string tmp_name = stk.top();
                int remain_time = mp[tmp_name];
                
                if(remain_time <= time_gap) {
                    time_gap -= remain_time;
                    cur_time += remain_time;
                    answer.push_back(tmp_name);
                    stk.pop();
                } else {
                    mp[tmp_name] -= time_gap;
                    cur_time += time_gap;
                    time_gap = 0;
                    break; 
                }
            }
        }
        
        stk.push(cur_name);
        cur_time = cur_start;
    }
    
    while(!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }
    
    return answer;
}