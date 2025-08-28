#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int,int>> edge[500001];
int dis[500001];

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<M;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    fill(&dis[0], &dis[N+1], 1e9);
    
    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // cout << current << "->";

        if (dis[current] < cost) {
            continue;
        }

        for (const auto& e : edge[current]) {
            int next = e.first;
            int weight = e.second;
            // cout << next << ": " << weight <<endl;

            if (dis[next] > dis[current] + weight) {
                dis[next] = dis[current] + weight;
                pq.push({dis[next], next});
            }
        }
    }

    cout << dis[N];
    
    return 0;
}