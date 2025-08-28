#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int cnt, x, y;
}info;

int N, M;
int arr[1001][1001];
int dis[2][1001][1001];
queue<info> q;

int px[4] = {0,-1,0,1};
int py[4] = {-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string str;
        cin >> str;
        for(int j=0;j<M;j++) {
            arr[i][j] = (int)(str[j] - '0');
        }
    }

    fill(&dis[0][0][0], &dis[1][1000][1000], -1);
    q.push({0, 0, 0});
    dis[0][0][0] = 0;

    while(!q.empty()) {
        int cnt = q.front().cnt;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        
        if(x == N-1 && y == M-1) {
            cout << dis[cnt][x][y] + 1;
            return 0;
        }

        for(int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(cnt == 0) {
                if(arr[nx][ny] == 1) {
                    if(dis[cnt][nx][ny]==-1) {
                        dis[1][nx][ny] = dis[cnt][x][y] + 1;
                        q.push({1, nx, ny});
                    }
                }
                else {
                    if(dis[cnt][nx][ny]==-1) {
                        dis[cnt][nx][ny] = dis[cnt][x][y] + 1;
                        q.push({cnt, nx, ny});
                    }
                }
            }
            else {
                if(arr[nx][ny] == 0) {
                    if(dis[cnt][nx][ny] == -1) {
                        dis[cnt][nx][ny] = dis[cnt][x][y] + 1;
                        q.push({cnt, nx, ny});
                    }
                }
            }
        }
    }
    cout << -1;
    
    return 0;
}