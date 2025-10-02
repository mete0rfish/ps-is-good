#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int res;
int arr[500][500];
int px[4] = {0,1,0,-1};
int py[4] = {-1,0,1,0};
int sand_px[] = {-1, +1, -1, +1, 0, -2, +2, -1, +1};
int sand_py[] = {-1, -1, 0, 0, -2, 0, 0, +1, +1};
int percent[] = {10, 10, 7, 7, 5, 2, 2, 1, 1};

bool valid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

pair<int, int> rotate90(int x, int y) {
	return {-y, x};
}

pair<int, int> rotate180(int x, int y) {
	pair<int, int> temp = rotate90(x, y);
	return rotate90(temp.first, temp.second);
}

pair<int, int> rotate270(int x, int y) {
	pair<int, int> temp = rotate180(x, y);
	return rotate90(temp.first, temp.second);
}


void calc(int x, int y, int dir) {
	int value = arr[x][y];
	if(value == 0) return;

	arr[x][y] = 0;
	int sum = 0;

	// 나머지
	for(int i=0;i<9;i++) {
		int cur_x = sand_px[i];
		int cur_y = sand_py[i];

		if(dir == 1) {
			pair<int, int> rotated = rotate90(cur_x, cur_y);
			cur_x = rotated.first;
			cur_y = rotated.second;
		}
		else if(dir == 2) {
			pair<int, int> rotated = rotate180(cur_x, cur_y);
			cur_x = rotated.first;
			cur_y = rotated.second;
		}
		else if(dir == 3) {
			pair<int, int> rotated = rotate270(cur_x, cur_y);
			cur_x = rotated.first;
			cur_y = rotated.second;
		}

		int nx = cur_x + x;
		int ny = cur_y + y;

		int amount = (value * percent[i])/ 100;
		sum += amount;

		if(valid(nx, ny)) {
			arr[nx][ny] += amount;
		} else {
			res+= amount;
		}
	}
	
	// 알파
	int nx = px[dir] + x;
	int ny = py[dir] + y;
	int alpha = value - sum;

	if(valid(nx, ny)) {
		arr[nx][ny] += alpha;
	}
	else {
		res += alpha;
	}
}

int main() {
	int total = 0;
	cin >> N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin >> arr[i][j];
		}
	}
	
	int x = N/2;
	int y = N/2;
	int dir = 0;
	int move_cnt = 1; // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
				 // 1, 1, 2, 2, 3, 3, 4, 4, 5, 5,  6,  6,  6,
	while(true) {
		for(int i=0;i<2;i++) {
			for(int j=0;j<move_cnt;j++) {
				x += px[dir];
				y += py[dir];

				if(!valid(x, y)) {
					goto end_loop;
				}

				if(arr[x][y] > 0) {
					calc(x, y, dir);
				}
			}
			dir = (dir+1)%4;
		}
		move_cnt++;
	}

	end_loop:;

	cout << res;
}
