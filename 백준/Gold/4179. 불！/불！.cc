#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int res = 1e9;
char arr[1001][1001];
bool f_vst[1001][1001];
bool j_vst[1001][1001];
int f_dis[1001][1001];
int j_dis[1001][1001];
queue<pair<int, int>> fq;
queue<pair<int ,int>> jq;

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void f_bfs() {
    while(!fq.empty()) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();
        
        for(int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(f_vst[nx][ny]) continue;

            f_vst[nx][ny] = true;
            f_dis[nx][ny] = f_dis[x][y] + 1;
            fq.push({nx, ny});
        }
    }
}

void j_bfs() {
    while(!jq.empty()) {
        int x = jq.front().first;
        int y = jq.front().second;
        jq.pop();

        if(x == 0 || y == 0 || x == R-1 || y == C-1) {
            cout << j_dis[x][y] + 1;
            exit(0);
        }
        
        for(int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(j_vst[nx][ny]) continue;
            if (f_dis[nx][ny] != -1 && j_dis[x][y] + 1 >= f_dis[nx][ny]) continue;

            j_vst[nx][ny] = true;
            j_dis[nx][ny] = j_dis[x][y] + 1;
            jq.push({nx, ny});
        }
    }
}

int main() {
    cin >> R >> C;
    fill(&f_dis[0][0], &f_dis[1000][1000], -1);
    fill(&j_dis[0][0], &j_dis[1000][1000], -1);
    
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'F')  {
                f_vst[i][j] = true;
                f_dis[i][j] = 0;
                fq.push({i, j});
            }
            else if(arr[i][j] == 'J') {
                j_vst[i][j] = true;
                j_dis[i][j] = 0;
                jq.push({i, j});
            }
            else if(arr[i][j] == '#') {
                j_vst[i][j] = true;
                f_vst[i][j] = true;
            }
        }
    }

    f_bfs();
    j_bfs();
    
    cout << "IMPOSSIBLE";
    return 0;
}