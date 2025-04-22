#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, K, A, B, C;
int arr[13][13];
pair<int, int> pos[11];
int dir[11];
deque<int> dq[13][13];
bool flag;

int px[4] = {0, 0, -1, 1};
int py[4] = {1, -1, 0, 0};

bool isBottom(int idx, int x, int y) {
    return dq[x][y].front() == idx;
}

bool isExternal(int nx, int ny) {
    if(nx < 0 || ny < 0 || nx >= N || ny >= N) {
        return true;
    }
    return false;
}

void gotoFrontToBack(int x, int y, int nx, int ny) {
    while(!dq[x][y].empty()) {
        int front = dq[x][y].front();
        dq[nx][ny].push_back(front);
        dq[x][y].pop_front();
        pos[front].first = nx;
        pos[front].second = ny;
    }
}
void gotoBackToFront(int x, int y, int nx, int ny) {
    while(!dq[x][y].empty()) {
        int back = dq[x][y].back();
        dq[nx][ny].push_back(back);
        dq[x][y].pop_back();
        pos[back].first = nx;
        pos[back].second = ny;
    }
}

void changeDir(int idx) {
    if(dir[idx] == 0) dir[idx] = 1;
    else if(dir[idx] == 1) dir[idx] = 0;
    else if(dir[idx] == 2) dir[idx] = 3;
    else if(dir[idx] == 3) dir[idx] = 2;
}

void move(int idx) {
    int x = pos[idx].first;
    int y = pos[idx].second;
    int nx = px[dir[idx]] + x;
    int ny = py[dir[idx]] + y;
    // cout << "x: " << x << ", y:" << y << endl;
    // 밑에 말인지 확인
    if(!isBottom(idx, x, y)) return;


    // 파란색인 경우 || 벽인 경우
    if(isExternal(nx, ny) || arr[nx][ny] == 2) {
        // 1. 방향 바꾸기
        changeDir(idx);

        // 2. 힌 킨 이동
        nx = px[dir[idx]] + x;
        ny = py[dir[idx]] + y;

        // 이동하려는 칸이 파란색이거나 벽이면 멈추기
        if(isExternal(nx, ny) || arr[nx][ny] == 2) {
           return;
        }
    }

    // 빨간색인 경우
    if(arr[nx][ny] == 1) {
        // 역순으로 옮기기
        gotoBackToFront(x, y, nx, ny);
    }

    // 흰색인 경우
    else {
        gotoFrontToBack(x, y, nx, ny);
    }

    if(dq[nx][ny].size() >= 4) {
        flag = true;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<K;i++) {
        cin >> A >> B >> C;
        pos[i] = make_pair(A-1, B-1);
        dir[i] = C-1;
        dq[A-1][B-1].push_back(i);
    }

    int cnt;
    for(cnt=1;cnt<=1000;cnt++) {
        for(int i =0;i<K;i++) {
            move(i);
        }
        if(flag) {
            break;
        }
    }

    if(cnt == 1001) cout << -1;
    else cout << cnt;
}
