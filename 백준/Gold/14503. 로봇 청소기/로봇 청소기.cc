#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int px[4] = {-1,0,1,0};
int py[4] = {0,1,0,-1};
int arr[51][51];
int vst[51][51];
int pos, sx,sy;
int res;

bool check_around(int x, int y) {
    bool hasDirty = false;
    for(int i=0;i<4;i++) {
        int nx = px[i] + x;
        int ny = py[i] + y;

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(arr[nx][ny] == 1) continue;

        if(arr[nx][ny] == 0 && !vst[nx][ny]) hasDirty = true;
    }

    return hasDirty;
}

void move(int x, int y, int dir) {
    
    if(arr[x][y] == 0 && !vst[x][y]) {
        res++;
    }

    vst[x][y] = true;

    // 2. 청소되지 않은 빈칸이 없는 경우
    if(!check_around(x, y)) {
        x -= px[dir];
        y -= py[dir];

        if(x < 0 || y < 0 || x >= N || y >= M) return;
        if(arr[x][y] == 1) return;

    }
    // 3. 청소되지 않은 빈칸이 있는 경우
    else {
        dir--;
        if(dir == -1)dir = 3;
        
        int nx = px[dir] + x;
        int ny = py[dir] + y;

        if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if(arr[nx][ny] == 0 && !vst[nx][ny]) {
                x = nx;
                y = ny;
            }
        }
    }

    move(x, y, dir);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;

    cin >> sx >> sy >> pos;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    move(sx, sy, pos);

    cout << res;
    
    return 0;
}