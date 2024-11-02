#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n, m;
int arr[301][301];
int t_arr[301][301];
bool visited[301][301];

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void identify_area(int x, int y, int area_num) {
    queue<pair<int, int >> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int nx = cur.first + px[i];
            int ny = cur.second + py[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)  continue;
            if(visited[nx][ny] || arr[nx][ny] <= 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int melt(int x, int y) {
    int cnt = 0;
    for(int i=0;i<4;i++) {
        int nx = x + px[i];
        int ny = y + py[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m)  continue;
        if(arr[nx][ny ] == 0)   cnt++;
    }
    return cnt;
}

void print_area() {
    cout << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }

    int day = 0;
    while(1) {
        /*
         * 덩어리 계싼
         */
        fill(&visited[0][0], &visited[300][301], false);
        fill(&t_arr[0][0], &t_arr[300][301], 0);

        int area_num = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] > 0 && !visited[i][j]) {
                    area_num++;
                    identify_area(i,j,area_num);
                }
            }
        }
        // print_area();
        // cout << area_num << endl;
        if(area_num >= 2) {
            cout << day << endl;
            break;
        }
        if(area_num == 0) {
            cout << 0 << endl;
            break;
        }

        /*
         * 빙하 녹이기
         */
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] > 0) {
                    t_arr[i][j] = arr[i][j] - melt(i,j);
                    if(t_arr[i][j] < 0) t_arr[i][j] = 0;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                arr[i][j] = t_arr[i][j];
            }
        }
        day++;
    }
    return 0;
}
