#include <climits>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int cnt, x, y;
}node;

int K, N, M;
int arr[1001][1001];
int dist[11][1001][1001];

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

int main() {
    cin >> N >> M >> K;

    for (int i=0;i<N;i++) {
        string str; cin >> str;
        for (int j=0;j<str.length();j++) {
            arr[i][j] = (int)(str[j] - '0');
        }
    }


    memset(dist, 0, sizeof(dist));

    queue<node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

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
            int nx = x + px[i];
            int ny = y + py[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (arr[nx][ny] == 1) {
                if (cnt >= K) continue;
                if (dist[cnt+1][nx][ny] != 0) continue;

                dist[cnt+1][nx][ny] = dist[cnt][x][y] + 1;
                q.push({cnt+1, nx, ny});
            }
            else {
                if (dist[cnt][nx][ny] != 0) continue;

                dist[cnt][nx][ny] = dist[cnt][x][y] + 1;
                q.push({cnt, nx, ny});
            }
        }
    }

    cout << -1;
    return 0;
}
