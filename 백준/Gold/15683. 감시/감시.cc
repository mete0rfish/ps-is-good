#include <iostream>
#include <vector>

using namespace std;

/*
1번: 4
2번: 2
3번: 4
4번: 4
5번: 1
*/
int N, M;
int res = 99999;
int wall_cnt;
int arr[9][9];
vector<pair<int, int>> cctvs;
int px[4] = {0, 1, 0, -1};
int py[4] = {1, 0, -1, 0};

void fills(int x ,int y, int mode) {
    while(true) {
        int nx = px[mode] + x;
        int ny = py[mode] + y;
        x = nx;
        y = ny;
        if(nx < 0 || ny < 0 || nx >= N || ny >= M)return;
        if(arr[nx][ny] == 6)return;

        if(arr[nx][ny] == 0) {
            arr[nx][ny] = -1;
        }
    }
}

void check() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] == 0)cnt++;
        }
    }

    res = min(res, cnt);
}

// 모든 CCTV
void dfs(int idx) {
    if(idx == cctvs.size()) {
        check();
        return;
    }

    int x = cctvs[idx].first;
    int y = cctvs[idx].second;
    int tmp[9][9];

    for(int mode=0; mode<4; mode++) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                tmp[i][j] = arr[i][j];
            }
        }
                
        if(arr[x][y] == 1) {
            fills(x, y, mode % 4);
        }
        else if(arr[x][y] == 2) {
            fills(x, y, mode % 4);
            fills(x, y, (mode + 2) % 4);
        }
        else if(arr[x][y] == 3) {
            fills(x, y, mode % 4);
            fills(x, y, (mode + 1) % 4);
        }
        else if(arr[x][y] == 4) {
            fills(x, y, mode % 4);
            fills(x, y, (mode+1) % 4);
            fills(x, y, (mode+2) % 4);
        }
        else if(arr[x][y] == 5) {
            fills(x, y, mode % 4);
            fills(x, y, (mode+1) % 4);
            fills(x, y, (mode+2) % 4);
            fills(x, y, (mode+3) % 4);
        }

        dfs(idx+1);
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] >= 1  && arr[i][j] <= 5)cctvs.push_back(make_pair(i, j));
            if(arr[i][j] == 6) wall_cnt++;
        }
    }

    dfs(0);
    cout << res << endl;
    
    return 0;
}