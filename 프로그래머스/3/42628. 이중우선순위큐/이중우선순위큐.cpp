#include <string>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <functional>
#include <map>

using namespace std;

/*
-45  
*/
priority_queue<int,vector<int>, greater<int>> mn_pq;
priority_queue<int> mx_pq;
map<int, int> m;

void clean() {
    while(!mx_pq.empty() && m[mx_pq.top()] == 0) {
        mx_pq.pop();
    }
    
    while(!mn_pq.empty() && m[mn_pq.top()] == 0) {
        mn_pq.pop();
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
    int mx_cnt = 0, mn_cnt=0;
    
    for(string o : operations) {
        if (o[0] == 'I') {
            string sub = o.substr(2);
            int num = stoi(sub);
            mn_pq.push(num);
            mx_pq.push(num);
            m[num]++;
            
        } else {
            clean();
            
            if (o[2] == '1') {
                if (mx_pq.empty()) continue;
                m[mx_pq.top()]--;
                mx_pq.pop();
            } else {
                if (mn_pq.empty()) continue;
                
                m[mn_pq.top()]--;
                mn_pq.pop();
            }
        }
    }
    
    clean();
    if (!mn_pq.empty()) answer[1] = mn_pq.top();
    if (!mx_pq.empty()) answer[0] = mx_pq.top();
    return answer;
}