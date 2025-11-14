#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<string> arr;
pair<int, int> red;
pair<int, int> blue;
bool vst[11][11][11][11];
int px[4] = {-1, 0, 1, 0};
int py[4] = {0, -1, 0, 1};

typedef struct info{
	int rx, ry, bx, by, cnt;
}info;

pair<int ,int> move(int dir, int x, int y, int ox, int oy) {
	while(true) {
		int nx = px[dir] + x;
		int ny = py[dir] + y;

		if(nx < 0 || ny < 0 || nx>=N || ny >=M ) break;
		if(arr[nx][ny] == 'O') return {-1, -1};
		if(arr[nx][ny] == '#') break;
		if(nx == ox && ny == oy) break;

		x = nx;
		y = ny;
	}
	return {x, y};
}

// true -> red
// false
bool whoFirst(int dir, int rx, int ry, int bx, int by) {
	if(dir == 0) {
		return rx < bx;
	}
	else if(dir == 1) {
		return ry < by;
	}
	else if(dir == 2) {
		return rx > bx;
	}
	else {
		return ry > by;
	}
}

void bfs() {
	queue<info> q;
	q.push({red.first, red.second, blue.first, blue.second, 0});
	vst[red.first][red.second][blue.first][blue.second] = true;

	while(!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if(cnt == 10) continue;
		for(int i=0;i<4;i++) {
			pair<int, int> nr;
			pair<int, int> nb;
			if(whoFirst(i, rx, ry ,bx, by)) {
				nr = move(i, rx, ry, -1, -1);
				nb = move(i, bx, by, nr.first, nr.second);
			}
			else {
				nb = move(i, bx, by, -1, -1);
				nr = move(i, rx, ry, nb.first, nb.second);
			}

			// cout << "red:" << nr.first << ", " << nr.second << endl;
			// cout << "blue:" << nb.first << ", " << nb.second << endl << endl;

			if(nb.first == -1 && nb.second == -1) continue;
			if(nr.first == -1 && nr.second == -1) {
				cout << cnt + 1;
				return;
			}

			if(vst[nr.first][nr.second][nb.first][nb.second]) continue;

			vst[nr.first][nr.second][nb.first][nb.second] = true;
			q.push({nr.first, nr.second, nb.first, nb.second, cnt+1});
		}
	}
	cout << -1;
}

int main() {
	cin >> N >> M;
	for(int i=0;i<N;i++) {
		string str;
		cin >> str;
		arr.push_back(str);

		for(int j=0;j<str.length();j++) {
			if(str[j] == 'R') red = make_pair(i, j);
			if(str[j] == 'B') blue = make_pair(i, j);
		}
	}

	bfs();

}