#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int T, N, D, C;

void calc(vector<int> dst) {
    int sum = 0;
    int cnt = 0;
    for(int i=1;i<=N;i++) {
        if(dst[i] != 1e9) {
            cnt++;
            sum = max(sum, dst[i]);
        }
    }
    cout << cnt << " " << sum << "\n";
}

void dijkstra(int start, vector<pair<int, int>> edge[]) {
    vector<int> dst(N+1, 1e9);
    priority_queue<pair<int, int>> pq;

    dst[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur_dst = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for(int i=0;i<edge[cur_node].size(); i++) {
            int nxt_dst = cur_dst + edge[cur_node][i].second;
            int nxt_node = edge[cur_node][i].first;

            if(nxt_dst < dst[nxt_node]) {
                dst[nxt_node] = nxt_dst;
                pq.push(make_pair(-nxt_dst, nxt_node));
            }
        }
    }
    calc(dst);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while(T--) {
        vector<pair<int, int>> edge[10001];
        cin >> N >> D >> C;
        for(int i=0;i<D;i++) {
            int a, b, s;
            cin >> a >> b >> s;
            edge[b].push_back(make_pair(a, s));
        }
        dijkstra(C, edge);
    }
}
