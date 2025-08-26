#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define MAX 1001

using namespace std;

int n, m;
int map[MAX][MAX];
int res[2][MAX][MAX];
bool chk[2][MAX][MAX];
queue<tuple<int, int, int>> q;
int xPos[4] = { -1,1,0,0 };
int yPos[4] = { 0,0,-1, 1 };

/*
부순 벽의 수
최종 길이
*/

void bfs(int x, int y) {
	q.push(make_tuple(0, x, y));
	chk[0][x][y] = true;
	res[0][x][y] = 1;

	while (!q.empty()) {
		tuple<int, int,int> curr = q.front();
		q.pop();
		
		int currX = get<1>(curr);
		int currY = get<2>(curr);

		for (int i = 0; i < 4; i++) {
			int broken = get<0>(curr);
			int movedX = currX + xPos[i];
			int movedY = currY + yPos[i];

			if (movedX < 1 || movedY < 1 || movedX > n || movedY > m) continue;

			// 벽을 이미 부쉈으면 안부수고 패스
			if (broken && !chk[broken][movedX][movedY]) {
				// 벽이 아니면 그대로 이동
				if (map[movedX][movedY] != 1) {
					chk[broken][movedX][movedY] = true;
					res[broken][movedX][movedY] = res[broken][currX][currY] + 1;
					q.push(make_tuple(broken, movedX, movedY));
				}
			}
			// 벽을 안부쉈으면 그대로 패스
			else if (!broken && !chk[broken][movedX][movedY]) {
				// 1이면 부수고 이동
				if (map[movedX][movedY] == 1) {
					chk[1][movedX][movedY] = true;
					res[1][movedX][movedY] = res[0][currX][currY] + 1;
					q.push(make_tuple(1, movedX, movedY));
				}
				// 0이면 그냥 이동
				else {
					chk[0][movedX][movedY] = true;
					res[0][movedX][movedY] = res[0][currX][currY] + 1;
					q.push(make_tuple(0, movedX, movedY));
				}
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			map[i][j] = (int)(str[j-1]-'0');
		}
	}
	
	bfs(1, 1);
	
	/*cout << "==== res ====" << endl;
	cout << " 00000 " << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[0][i][j] << ' ';
		}
		cout << endl;
	}
	cout <<endl<< " 11111 " << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[1][i][j] << ' ';
		}
		cout << endl;
	}
	*/

	/*
	cout << "==== broken ====" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << broken[i][j] << ' ';
		}
		cout << endl;
	}*/
	if (res[1][n][m] == 0 && res[0][n][m] == 0)
		cout << -1;
	else {
		if (res[0][n][m] == 0)	cout << res[1][n][m];
		else if (res[1][n][m] == 0) cout << res[0][n][m];
		else cout << min(res[0][n][m], res[1][n][m]);
	}
		
}

