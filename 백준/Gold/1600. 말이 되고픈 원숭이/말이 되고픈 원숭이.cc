#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int arr[201][201];
int dist[31][201][201];

int K, N, M;

int px[12] = {-1,0,1,0, -1,-2,-2,-1, 1,2,2,1};
int py[12] = {0,-1,0,1, -2,-1,1,2, -2,-1,1,2};

typedef struct {
    int cnt, x, y;
}node;

int main() {
    cin >> K >> M >> N;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    queue<node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    memset(dist, 0, sizeof(dist));

    while (!q.empty()) {
        int cnt = q.front().cnt;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();


        if (x == N-1 && y == M-1) {
            cout << dist[cnt][x][y];
            return 0;
        }

        for (int i=0;i<4;i++) {
            int nx = px[i] + x;
            int ny = py[i] + y;

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[cnt][nx][ny] != 0) continue;
            if (arr[nx][ny] == 1) continue;

            dist[cnt][nx][ny] = dist[cnt][x][y] + 1;
            q.push({cnt, nx, ny});
        }

        if (cnt < K) {
            for (int i=4;i<12;i++) {
                int nx = px[i] + x;
                int ny = py[i] + y;

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (dist[cnt+1][nx][ny] != 0) continue;
                if (arr[nx][ny] == 1) continue;

                dist[cnt+1][nx][ny] = dist[cnt][x][y] + 1;
                q.push({cnt+1, nx, ny});
            }
        }
    }
    cout << -1;
    return 0;
}
