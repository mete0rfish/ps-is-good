#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K;
bool vst[101][101];
char arr[101][101];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void bfs() {
	queue<pair<int, int>> q;
	for(int j=0;j<M;j++) {
		if(arr[N-1][j] == 'x') {
			q.push({N-1, j});
			vst[N-1][j] = true;
		}
	}

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0;i<4;i++) {
			int nx = x + px[i];
			int ny = y + py[i];

			if(nx<0 ||ny<0||nx>=N||ny>=M) continue;
			if(vst[nx][ny]) continue;
			if(arr[nx][ny] != 'x') continue;

			vst[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

void drop_cluster(vector<pair<int, int>>& cluster_point) {
	if(cluster_point.empty()) return;

	for(auto p : cluster_point) {
		arr[p.first][p.second] = '.';
	}

	int min_drop = N;
	for(auto p : cluster_point) {
		int x = p.first;
		int y = p.second;
		int drop_dist = 0;

		while(x+1 < N && arr[x+1][y] == '.') {
			x++;
			drop_dist++;
		}
		min_drop = min(min_drop, drop_dist);
	}

	for(auto p : cluster_point) {
		arr[p.first + min_drop][p.second] = 'x';
	}
}

vector<pair<int, int>> find_non_cluster() {
	vector<vector<bool>> cluster_vst(N, vector<bool>(M, false));
	vector<pair<int, int>> cluster_point;

	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(arr[i][j] != 'x' || vst[i][j] || cluster_vst[i][j]) continue;

			queue<pair<int, int>> q;
			q.push({i, j});
			cluster_vst[i][j] = true;
			cluster_point.push_back({i, j});

			while(!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				
				for(int k=0;k<4;k++) {
					int nx = x + px[k];
					int ny = y + py[k];

					if(nx<0 ||ny<0||nx>=N||ny>=M) continue;
					if(cluster_vst[nx][ny]) continue;
					if(arr[nx][ny] != 'x') continue;

					cluster_vst[nx][ny] = true;
					q.push({nx, ny});
					cluster_point.push_back({nx, ny});
				}
			}
			return cluster_point;
		}
	}
	return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N >> M;
	for(int i=0;i<N;i++) {
		string str;
		cin >> str;
		for(int j=0;j<M;j++) {
			arr[i][j] = str[j];
		}
	}

	cin >> K;
	for(int i=0;i<K;i++) {
		int height;
		cin >> height;
		// 왼
		if(i%2==0) {
			for(int j=0;j<M;j++) {
				if(arr[N-height][j] == 'x') {
					arr[N-height][j] = '.';
					break;
				}
			}
		}
		else {
			for(int j=M-1;j>=0;j--) {
				if(arr[N-height][j] == 'x') {
					arr[N-height][j] = '.';
					break;
				}
			}
		}

		fill(&vst[0][0],&vst[N][M] ,false);
		bfs();
		vector<pair<int, int>> cluster_point = find_non_cluster();
		drop_cluster(cluster_point);
	}

	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
