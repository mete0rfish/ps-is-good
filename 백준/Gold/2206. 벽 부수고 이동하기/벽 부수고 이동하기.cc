#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int cnt, x, y;
}info;

int N, M;
int arr[1002][1002];
int dis[2][1002][1002];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++) {
            arr[i][j] = (int)(str[j]-'0');
        }
    }

    fill(&dis[0][0][0], &dis[1][1000][1000], -1);
    
    queue<info> q;
    q.push({0, 0, 0});
    dis[0][0][0] = 1;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if(x == N-1 && y == M-1) {
            cout << dis[cnt][x][y];
            return 0;
        }

        for(int i=0;i<4;i++) {
            int nx = px[i] + x;
            int ny = py[i] + y;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 한 번 부신 상태에선 이동 밖에 못함
            if(cnt == 1) {
                if(dis[cnt][nx][ny] == -1) {
                    if(arr[nx][ny] == 0) {
                        q.push({cnt, nx, ny});
                        dis[cnt][nx][ny] = dis[cnt][x][y] + 1;
                    }
                }
            }
            // 부시지 않은 상태에서 벽인 경우 부수고, 아닌 경우 이동
            else {
                if(dis[cnt][nx][ny] == -1) {
                    if(arr[nx][ny] == 1) {
                        q.push({1, nx, ny});
                        dis[1][nx][ny] = dis[0][x][y] + 1;
                    }
                    else {
                        q.push({0, nx, ny});
                        dis[0][nx][ny] = dis[0][x][y] + 1;
                    }
                }
            }
            
        }
    }

    cout << -1;
    
    return 0;
}