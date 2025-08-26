#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
char arr[1001][1001];
int f_dis[1001][1001];
int j_dis[1001][1001];
queue<pair<int, int>> fq;
queue<pair<int, int>> jq;

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(&f_dis[0][0], &f_dis[1000][1000], -1);
    fill(&j_dis[0][0], &j_dis[1000][1000], -1);

    cin >> R >> C;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'F') {
                fq.push({i, j});
                f_dis[i][j] = 0;
            }
            else if(arr[i][j] == 'J') {
                jq.push({i, j});
                j_dis[i][j] = 0;
            }
        }
    }

    while(!fq.empty()) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();
            
        for(int i=0;i<4;i++) {
            int nx = px[i] + x;
            int ny = py[i] + y;

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(f_dis[nx][ny] != -1) continue;
            if(arr[nx][ny] == '#') continue;

            f_dis[nx][ny] = f_dis[x][y] + 1;
            fq.push({nx, ny});
        }        
    }

    while(!jq.empty()) {
        int x = jq.front().first;
        int y = jq.front().second;
        jq.pop();

        if(x == 0 || y == 0 || x == R-1 || y == C-1) {
            cout << j_dis[x][y] + 1;
            return 0;
        }

        for(int i=0;i<4;i++) {
            int nx = px[i] + x;
            int ny = py[i] + y;

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(j_dis[nx][ny] != -1) continue;
            if(arr[nx][ny] == '#') continue;
            if(f_dis[nx][ny] != -1 && j_dis[x][y] + 1 >= f_dis[nx][ny]) continue;

            j_dis[nx][ny] = j_dis[x][y] + 1;
            jq.push({nx, ny});
        }        
    }

    cout << "IMPOSSIBLE";
    
    return 0;
}