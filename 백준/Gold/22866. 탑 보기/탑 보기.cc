#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
cnt[0] = 0 + 1
cnt[1] = 0 + 0
cnt[2] = 1 + 2
cnt[3] = 1 + 1
cnt[4] = 2 + 2
cnt[5] = 2 + 1
cnt[6] = 3 + 1
cnt[7] = 0

---ㄱ
7 |
----

{높이, 인덱스}
// 왼쪽 -> 오른쪽

while(!s.empty() && s.top().first<= cur)
    s.pop();

count[i] += s.size();
if(res[i].first > s.top().first) {
    res[i].first = s.top().first;
    res[i].second = s.top().second;
}
s.push(cur);
*/

int arr[100001];
int cnt[100001];
int res[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&res[0], &res[100000], 1e9);
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    stack<pair<int, int>> s;
    for(int i=0; i<N;i++) {
        int cur_height =  arr[i];
        while(!s.empty() && s.top().first<= cur_height)
            s.pop();
        
        cnt[i] += s.size();
        if(!s.empty()) {
            int t_dist = abs(i - s.top().second);
            int dist = abs(i - res[i]);
            if(dist > t_dist) {
                res[i] = s.top().second;
            }
        }
        
        s.push({cur_height, i});
    }

    stack<pair<int, int>> s2;
    for(int i=N-1; i>=0;i--) {
        int cur_height = arr[i];
        while(!s2.empty() && s2.top().first<= cur_height)
            s2.pop();
        
        cnt[i] += s2.size();
        if(!s2.empty()) {
            int t_dist = abs(i - s2.top().second);
            int dist = abs(i - res[i]);
            if(dist > t_dist) {
                res[i] = s2.top().second;
            }
        }
        
        s2.push({cur_height, i});
    }

    for(int i=0;i<N;i++) {
        cout << cnt[i] << ' ';
        if(cnt[i] != 0) {
            cout << res[i]+1;
        }
        cout << "\n";
    }
    
    return 0;
}