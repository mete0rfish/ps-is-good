#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>

using namespace std;

int N;
int sx, sy, sd, g;
int arr[101][101];
bool vst[101][101];

int py[4] = {0,-1,0,1};
int px[4] = {1,0,-1,0};

/*
 외
*/

void dfs(vector<int>& dirs, int y, int x, int cnt, int g) {
	if(cnt > g) {
		return;
	}

	vector<int> tmp;
	for(auto dir : dirs) {
		int ny = py[dir] + y;
		int nx = px[dir] + x;

		if(nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;

		vst[ny][nx] = true;
		y = ny;
		x = nx;
 	}
}

void makeDirs(vector<int>& dirs, int g) {
	for(int i=0;i<g;i++) {
		vector<int> tmp(dirs);
		for(int i=0;i<tmp.size();i++) {
			tmp[i] = (tmp[i]+1)%4;
		}
		reverse(tmp.begin(), tmp.end());
		dirs.insert(dirs.end(), tmp.begin(), tmp.end());
	}
}

int check() {
	int sum = 0;
	for(int i=1;i<=100;i++) {
		for(int j=1;j<=100;j++) {
			if(vst[i][j] && vst[i][j-1] && vst[i-1][j] && vst[i-1][j-1]) sum++;
		}
	}
	return sum;
}

int main() {
	cin >> N;
	while(N--) {
		vector<int> dirs;
		cin >> sx >> sy >> sd >> g;

		dirs.push_back(sd);
		vst[sy][sx] = true;
		makeDirs(dirs, g);
		dfs(dirs, sy, sx, 0, g);
	}

	cout << check();
}
