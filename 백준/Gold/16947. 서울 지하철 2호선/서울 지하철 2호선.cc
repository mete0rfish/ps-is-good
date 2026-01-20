#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<int> edges[3001];
bool vst[3001];
bool isCycle[3001];
int dist[3001];


// -2 사이클 찾고 종료, -1 사이클 못 찾음, 0 이상 사이클 시작 노드
int find_cycle(int curr, int prev) {
    
    vst[curr] = true;

    for (int next : edges[curr]) {
        if (next == prev) continue;

        if (vst[next]) {
            isCycle[curr] = true;
            return next;
        }

        int res = find_cycle(next, curr);

        if (res == -2) return -2;
        if (res >= 0) {
            isCycle[curr] = true;
            if (curr == res) return -2;
            return res;
        }
    }

    return -1;
}

int main() 
{
    cin >> N;
    for (int i=0;i<N;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    find_cycle(1, 0);

    // 사이클노드를 bfs돌면서 거리 측정
    queue<int> q;
    
    for (int i=1;i<=N;i++) {
        if (isCycle[i]) {
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = -1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : edges[cur]) {
            if (dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    for (int i=1;i<=N;i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
