#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
1. 방향 선택
2. 블럭을 해당 방향 이동
    - 이동 순서
        - 0위: x,y = 1,1 ~ 1,N -> 2,1 ~ 2,N
        - 1아래: x,y = N-1,0 ~ N-1,N -> N-2,0 ~ N-2,N
        - 2왼쪽: x,y = 1,1 ~ N,1 ->1,2 ~ N,2
        - 3오른쪽: x,y = 1,N-1 ~ N,N-1, 1,N-2 ~ N,N-2 
    1. 벽이나 블록이면 멈춤
    2. 만약 블록이고, 자신의 숫자와 같으면 자신 블록 삭제
*/

int px[4] = {-1, 1, 0, 0};
int py[4] = {0, 0, -1, 1};

int N;
int arr[21][21];
int res;

bool isBlock(int x, int y) {
    return arr[x][y] != 0;
}

void move(int x, int y, int dir, bool merged[][21]) {
    if(arr[x][y] == 0) return;
    
    int tmp = arr[x][y];
    arr[x][y] = 0;
    
    while(true) {
        int nx = x + px[dir];
        int ny = y + py[dir];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) {
            arr[x][y] = tmp;
            return;
        } 
        if(arr[nx][ny] != 0) {
            if(arr[nx][ny] == tmp && !merged[nx][ny]) {
                arr[nx][ny] *= 2;
                merged[nx][ny] = true;
            }
            else {
                arr[x][y] = tmp;
            }
            return;
        }

        x = nx;
        y = ny;
    }

    //cout << x << ", " << y << endl;
    
}

void totalMove(int dir, bool merged[][21]) {
    if(dir == 0) {
        for(int x=0;x<N;x++) {
            for(int y=0;y<N;y++) {
                if(isBlock(x, y)) move(x, y, dir, merged);
            }
        }
    }
    else if(dir == 1) {
        for(int x=N-1;x>=0;x--) {
            for(int y=0;y<N;y++) {
                if(isBlock(x, y)) move(x,y,dir, merged);
            }
        }
    }
    else if(dir == 2) {
        for(int y=0;y<N;y++) {
            for(int x=0;x<N;x++) {
                if(isBlock(x, y)) {
                    //cout <<endl<< x << ", " << y << endl;
                    move(x,y,dir, merged);
                } 
            }
        }
    }
    else if(dir == 3) {
        for(int y=N-1;y>=0;y--) {
            for(int x=0;x<N;x++) {
                if(isBlock(x, y)) move(x,y,dir, merged);
            }
        }
    }
}

void solve(int idx) {
    if(idx == 5) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                // cout << arr[i][j] << ' ';
                res = max(res, arr[i][j]);
            }
            // cout << endl;
        }
        // cout << endl;
        return;
    }

    
    for(int dir=0;dir<4;dir++) {
        int tmp[21][21];
        bool merged[21][21] = {false,};
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                tmp[i][j] = arr[i][j];
            }
        }

        totalMove(dir, merged);
        solve(idx+1);

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    solve(0);
    cout << res;
    
    return 0;
}