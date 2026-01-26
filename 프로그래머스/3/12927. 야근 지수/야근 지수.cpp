#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<long long> pq;
    for(int w: works) {
        pq.push(w);
    }
    
    for(int i=0;i<n;i++) {
        if (pq.empty()) break;
        
        long long tmp  = pq.top() - 1;
        pq.pop();
        
        if (tmp == 0) continue;
        pq.push(tmp);
    }
    
    while(!pq.empty()) {
        if (pq.top() == 0) break;
        
        answer += pow(pq.top(),2);
        pq.pop();
    }
    
    return answer;
}