#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
vector<pair<int, int>> edges[50001];
int dist[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 1. {목적지, 비용} 순서로 저장
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    fill(&dist[1], &dist[N + 1], INF);
    // greater<> 사용 (더 간결함)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    // 우선순위 큐에는 {비용, 노드} 순서로 넣는 것이 정렬에 유리
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost) {
            continue;
        }

        for (auto& e : edges[node]) {
            // 2. 저장된 순서에 맞게 값을 꺼냄
            int next_node = e.first;
            int weight = e.second;

            if (dist[next_node] > cost + weight) {
                dist[next_node] = cost + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    cout << dist[N];
    return 0;
}