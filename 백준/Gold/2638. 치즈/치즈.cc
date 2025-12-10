#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[101][101];
bool outer[101][101];
int chk[101][101];
bool vst[101][101];

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void prints() {
    cout << endl;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cout << chk[i][j] << " ";
        }
        cout << endl;
    }
}

void check_outer(int x, int y) {
    queue<pair<int ,int>> q;
    q.push({x, y});
    outer[x][y] = true;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nx = xx + px[i];
            int ny = yy + py[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (outer[nx][ny]) continue;
            if (arr[nx][ny] == 1) {
                chk[nx][ny]++;
                continue;
            }

            outer[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void melt(bool& flag) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if (chk[i][j]>=2) {
                flag = true;
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    while(true) {
        bool flag = false;
        memset(vst, false, sizeof(vst));
        memset(chk, false, sizeof(chk));
        memset(outer, false, sizeof(outer));

        outer[0][0] = true;
        check_outer(0, 0);

        // prints();
        melt(flag);

        if (!flag) break;
        res++;
    }
    cout << res;
}
