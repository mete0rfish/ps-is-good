#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, CNT;
int sx, sy;
int arr[1001][1001];
int dis[1001][1001];
bool visited[1001][1001];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void bfs() {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = cur.first + px[i];
            int ny = cur.second + py[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;
            if(visited[nx][ny]) continue;

            dis[nx][ny] = dis[cur.first][cur.second] + 1;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                visited[i][j] = true;
            }
            else if(arr[i][j] == 2){
                sx = i;
                sy = j;
            }  
        }
    }

    bfs();


    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] == 1 && dis[i][j] == 0)cout << -1 << " ";
            else cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
}