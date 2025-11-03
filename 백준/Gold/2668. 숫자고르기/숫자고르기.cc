#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int res_cnt;
vector<int> res;

int next_node[101];
bool vst[101];
bool finished[101]; // 사이클을 찾은 노드들

void dfs(int a) {
	vst[a] = true;
	int b = next_node[a];

	if (vst[b]) {  // 사이클 발견 -> 정답 배열에 추가
		int tmp = b;
		while (true) {
			finished[tmp] = true;
			tmp = next_node[tmp];
			if (tmp == b) break;
		}
	} else if (!finished[b]) {
		dfs(b);
	}

	vst[a] = false;
}

int main() {
	cin >> N;
	for(int i=1;i<=N;i++) {
		cin >> next_node[i];
	}

	for(int i=1;i<=N;i++) {
		if (!finished[i]) dfs(i);
	}
	
	for (int i=1;i<=N;i++) {
		if (finished[i]) res.push_back(i);
	}

	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for(int node : res) cout << node << "\n";
}