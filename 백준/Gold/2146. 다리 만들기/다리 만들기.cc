#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int N, area_num= 2;
int res = 99999;
int arr[101][101];
bool visited[101][101];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void identify_area(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        arr[cur.first][cur.second] = area_num;

        for(int i=0;i<4;i++) {
            int nx = cur.first + px[i];
            int ny = cur.second + py[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N)  continue;
            if(visited[nx][ny] || arr[nx][ny] == 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void bfs(int num) {
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j] == num) {
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int n = q.front().second;
        q.pop();


        for(int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N)   continue;
            //cout << "{" << nx << ", " << ny << "} : " << arr[nx][ny] << endl;
            if(visited[nx][ny])   continue;

            if(arr[nx][ny] != num && arr[nx][ny] != 0) {
                res = min(res, n);
                return;
            }

            q.push({{nx, ny}, n+1});
            visited[nx][ny] = true;
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

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j] == 1) {
                identify_area(i,j);
                area_num++;
            }
        }
    }


    for(int i=2;i<area_num;i++) {
        bfs(i);
        fill(visited[0], visited[100], false);
    }

    cout << res;

    return 0;
}
