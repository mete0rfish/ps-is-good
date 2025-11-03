#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int res;
vector<string> arr;
int px[4] = {-1,1,0,0};
int py[4] = {0,0,-1,1};

int vst[1001][1001];

void dfs(int x, int y) {
	if (vst[x][y]==1) {
		res++;
		return;
	}

	vst[x][y] = 1;

	int nx, ny;
	if (arr[x][y] == 'U') {
		nx = px[0]+x;
		ny = py[0]+y;
	} else if (arr[x][y] == 'D') {
		nx = px[1]+x;
		ny = py[1]+y;
	} else if (arr[x][y] == 'L') {
		nx = px[2]+x;
		ny = py[2]+y;
	} else if (arr[x][y] == 'R') {
		nx = px[3]+x;
		ny = py[3]+y;
	}
	
	if (vst[nx][ny]!=2) {
		dfs(nx,ny);
	}

	vst[x][y] = 2;
}

int main() {
	cin >> N >> M;
	for(int i=0;i<N;i++) {
		string str; cin >> str;
		arr.push_back(str);
	}

	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(!vst[i][j]) {
				dfs(i, j);
			}
		}
	}
	cout << res;
}