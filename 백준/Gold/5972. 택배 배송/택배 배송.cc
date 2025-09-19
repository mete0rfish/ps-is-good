#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int A, B, C;
int dist[50001];
vector<pair<int ,int>> edges[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        cin >> A >> B >> C;
        edges[A].push_back(make_pair(B, C));
        edges[B].push_back(make_pair(A, C));
    }

    fill(&dist[0], &dist[50001], 1e9);
    priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int,int>>> pq;

    pq.push(make_pair(0, 1));
    dist[1] = 0;
    
    while(!pq.empty()) {
        int node_cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // 이거 주의
        if(node_cost > dist[node]) continue;

        for(auto e : edges[node]) {
            int edge_cost = e.second;
            int next_node = e.first;

            if(dist[next_node] > dist[node] + edge_cost) {
                dist[next_node] = dist[node] + edge_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    cout << dist[N];
    return 0;
}