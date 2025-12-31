#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int red_portals[100001];
int blue_portals[100001];   
int dist[100001];
int res = 1e9;

int solution(int n) {
    for (int i=0;i<n;i++) dist[i] = 1e9;
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_idx = pq.top().second;
        pq.pop();

        if (red_portals[cur_idx] != -1){
            int next_idx = red_portals[cur_idx];

            if (dist[next_idx] > cur_cost) {
                dist[next_idx] = cur_cost;
                pq.push({cur_cost, next_idx});
            }

            continue;
        }
        else if (blue_portals[cur_idx] != -1) {
            int next_idx = blue_portals[cur_idx];

            if (dist[next_idx] > cur_cost) {
                dist[next_idx] = cur_cost;
                pq.push({cur_cost, next_idx});
            }
        }
        
        if (cur_idx + 1 < n) {
            int next_idx = cur_idx + 1;

            if (dist[next_idx] > cur_cost + 1) {
                dist[next_idx] = cur_cost + 1;
                pq.push({cur_cost + 1, next_idx});
            }
        }
    }

    return dist[n-1] == 1e9 ? -1 : dist[n-1];
}

int main() {
    int N, C;
    cin >> N >> C;

    memset(red_portals, -1, sizeof(red_portals));
    memset(blue_portals, -1, sizeof(blue_portals));

    int a, b, c;
    for (int i=0;i<C;i++) {
        cin >> a >> b >> c;
        if (a == 0) red_portals[b] = c;
        else blue_portals[b] = c;
    }

   cout << solution(N);

    return 0;
}
