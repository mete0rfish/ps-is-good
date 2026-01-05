#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool vst[1000][1000];
int px[4] = {1, 0, -1, 0};
int py[4] = {0, 1, 0, -1};

void solution(int N, int M) {
    vector<vector<int>> v(N, vector<int>(N, 0));
    memset(vst, false, sizeof(vst));
    int rx=0, ry=0;

    int idx = N*N;
    int x = 0, y = 0;
    int dir = 0;

    for (int i=0;i<N*N;i++) {
        v[x][y] = idx;
        vst[x][y] = true;

        if (idx == M) {
            rx = x + 1;
            ry = y + 1;
        }
        if (idx == 0) break; 

        int nx = x + px[dir];
        int ny = y + py[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || vst[nx][ny]) {
            dir = (dir + 1) %4;
            nx = x + px[dir];
            ny = y + py[dir];
        }

        x = nx;
        y = ny;
        idx--;
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    cout << rx << " " << ry;
}

int main() {
    int N, M;
    cin >> N >> M;
    solution(N, M);

    return 0;
}
