#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int arr[1001];
int answer = 0;
int cur_server = 0;
queue<pair<int, int>> q; // 반납시간, 서버 수

int solution(vector<int> players, int m, int k) {
    int n = players.size();
    for(int i=0;i<n;i++) {
        if(!q.empty() && q.front().first == i) {
            cur_server -= q.front().second;
            q.pop();
        }
        
        if(players[i] >= m) {
            int tot_server = players[i] / m;
            if(tot_server > cur_server) {
                int add_server = tot_server - cur_server;
                cur_server += add_server;
                answer += add_server;
                q.push(make_pair(i + k, add_server));
            }
        }
    }
    
    
    
    return answer;
}