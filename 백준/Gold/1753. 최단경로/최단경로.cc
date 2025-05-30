#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 20010
#define INF 987654321

using namespace std;

int v, e, s;
int dis[MAX];
vector<pair<int, int>> edge[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e >> s;
	
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edge[a].push_back(make_pair(b,w));
	}
	
	// 최단 거리 초기화
	for (int i = 1; i <= v; i++) {
		dis[i] = INF;
	}

	// 시작 노드 세팅
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[s] = 0;
	pq.push(make_pair( 0, s ));

	while (!pq.empty()) {

		int topDis = pq.top().first;
		int topId = pq.top().second;
		pq.pop();
		if (dis[topId] < topDis)
			continue;

		// top에 연결된 간선을 이용해 최단거리 갱신
		for (int i = 0; i < edge[topId].size(); i++) {
			int oppo = edge[topId][i].first;
			int value = edge[topId][i].second;

			if (dis[oppo] > topDis + value) {
				dis[oppo] = topDis + value;
				pq.push(make_pair(topDis + value, oppo));
			}
			
		}
	}
	
	for (int i = 1; i <= v; i++) {
		if (dis[i] == INF)
			cout << "INF\n";
		else
			cout << dis[i] << '\n';
			
	}

}

