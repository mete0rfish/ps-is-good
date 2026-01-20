#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int ans=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (string t : timetable) {
        int hs = stoi(t.substr(0, 2));
        int ms = stoi(t.substr(3, 2));
        
        int m = hs*60 + ms;
        pq.push(m);
    }
    
    // pq 돌면서
    // 타임스탬프돌면서 버스 보내기
    // 만약 마지막 버스에서 자리가 남은 경우 -> 출발 시간
    // 만약 마지막 버스에서 자리가 없는 경우 -> 가장 마지막 탑승 고객 - 1
    int st = 9*60;
    int et = 9*60 + t*n;
    int bus_time = st;
    
    for (int i=0;i<n;i++) {
        int cnt = 0;
        int prev = 0;
        while(cnt < m && !pq.empty() && pq.top() <= bus_time) {
            prev = pq.top();
            pq.pop();
            cnt++;
        }
        
        if (i == n-1) {
            if (cnt < m) {
                ans = bus_time;
            }
            else {
                ans = prev - 1;
            }
        }
    
        bus_time+=t;
    }
    
    char buf[10];
    sprintf(buf, "%02d:%02d", ans/60, ans%60);
    return string(buf);
}