#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int r, c;
int res;
bool flag;
char maps[1501][1501];
bool visited[1501][1501];
queue<pair<int,int>> swans, doneSwans;
queue<pair<int,int>> water, doneWater;
pair<int,int> starts;

int xPos[4] = {1, 0, -1, 0};
int yPos[4] = {0, 1, 0, -1};

void waterDFS() {
    while(!water.empty()) {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        for(int i=0;i<4;i++) {
            int nx = xPos[i] + x;
            int ny = yPos[i] + y;

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (maps[nx][ny]!='X')  continue;

            maps[nx][ny] = '.';
            doneWater.push({nx,ny});
        }
    }
}

void swanDFS() {
    while(!swans.empty()) {
        int x = swans.front().first;
        int y = swans.front().second;
        swans.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xPos[i] + x;
            int ny = yPos[i] + y;

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if(maps[nx][ny] == 'X') {
                doneSwans.push({nx,ny});
            }
            else if(maps[nx][ny] == '.') {
                swans.push({nx,ny});
            }
            else if (maps[nx][ny] == 'L') {
                flag = true;
                break;
            }
        }
    }
}

void doActions() {
    int dday = 0;

    while(!flag) {
        swanDFS();
        if(!flag) {
            waterDFS();
            water = doneWater;
            swans = doneSwans;

            while(!doneSwans.empty()) doneSwans.pop();
            while(!doneWater.empty()) doneWater.pop();
            dday++;
        }
    }

    cout << dday;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 'L') {
                starts.first = i;
                starts.second = j;
            }
            if(maps[i][j] != 'X') {
                water.push({i,j});
            }
        }
    }

    swans.push({starts.first, starts.second});
    visited[starts.first][starts.second] = true;

    doActions();

    return 0;
}
