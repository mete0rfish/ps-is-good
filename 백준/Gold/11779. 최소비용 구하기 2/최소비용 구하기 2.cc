#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

#define MAX 1010
#define INF 987654321

using namespace std;

int n, m;
int a, b, w;

vector<pair<int, int>> nodes[MAX];
int parent[MAX];
int dis[MAX];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[a] = 0;
	pq.push(make_pair(0, a));

	int cnt = 1;

	while (!pq.empty()) {
		int topDis = pq.top().first;
		int topId = pq.top().second;
		pq.pop();

		//if (topId == b)	break;

		if (dis[topId] < topDis)	continue;

		for (int i = 0; i < nodes[topId].size(); i++) {
			int oppo = nodes[topId][i].first;
			int value = nodes[topId][i].second;

			if (dis[oppo] > topDis + value) {
				dis[oppo] = topDis + value;
				pq.push(make_pair(dis[oppo], oppo));

				// 갱신되면 부모 수정
				//cout << "부모 갱신됨: " << topId << ", " << oppo << endl;
				parent[oppo] = topId;
				
			}
		}
	}

	int curr = b;
	vector<int> res;
	res.push_back(curr);
	while (parent[curr] != curr) {
		cnt++;
		res.push_back(parent[curr]);
		curr = parent[curr];
	}

	cout << dis[b] << "\n";
	cout << cnt << "\n";
	for (int i = res.size()-1; i >=0; i--)
		cout << res[i] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		nodes[a].push_back(make_pair(b, w));
	}

	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
		parent[i] = i;
	}

	cin >> a >> b;

	dijkstra();
}