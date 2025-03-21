#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

#define GARO 0
#define SERO 1
#define DAEGAK 2

using namespace std;

int N, cnt;

int maps[17][17];
bool vst[17][17];

// 가로, 세로, 대각
int px[3] = {0, 1, 1};
int py[3] = {1, 0, 1};

bool isInvalidateGaro(int x, int y) {
    if(y + 1 >=N || maps[x][y+1] == 1)  return true;
    return false;
}

bool isInvalidateSero(int x, int y) {
    if(x + 1 >=N || maps[x+1][y] == 1)  return true;
    return false;
}

bool isInvalidateDaegak(int x, int y) {
    if(maps[x+1][y+1] == 1)     return true;
    if(isInvalidateGaro(x, y) || isInvalidateSero(x, y))  return true;
    return false;
}

void dfs(int x, int y, int pos) {
    // cout << "{ " << x << ", " << y << "} : " << pos << "\n";
    if(x == N-1 && y == N-1) {
        cnt++;
        return;
    }

    if(pos == GARO) {


        for(int i=0;i<3;i++) {
            if(i == SERO)continue;
            if(i == GARO) {
                if(isInvalidateGaro(x, y)) continue;
            }
            else if(i == DAEGAK) {
                if(isInvalidateDaegak(x, y)) continue;
            }

            int nx = px[i] + x;
            int ny = py[i] + y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N)  continue;

            dfs(nx, ny, i);
        }
    }
    if(pos == SERO) {

        for(int i=0;i<3;i++) {
            if(i == GARO)continue;
            if(i == SERO) {
                if(isInvalidateSero(x, y)) continue;
            }
            else if(i == DAEGAK) {
                if(isInvalidateDaegak(x, y)) continue;
            }

            int nx = px[i] + x;
            int ny = py[i] + y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N)  continue;

            dfs(nx, ny, i);
        }
    }
    if(pos == DAEGAK) {

        for(int i=0;i<3;i++) {
            if(i == GARO) {
                if(isInvalidateGaro(x, y)) continue;
            }
            if(i == SERO) {
                if(isInvalidateSero(x, y)) continue;
            }
            else if(i == DAEGAK) {
                if(isInvalidateDaegak(x, y)) continue;
            }

            int nx = px[i] + x;
            int ny = py[i] + y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N)  continue;

            dfs(nx, ny, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
        }
    }

    dfs(0, 1, GARO);
    cout << cnt;
}
