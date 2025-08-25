#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int cnt, x, y, dir;
}info;

int N;
char arr[51][51];
bool vst[5][51][51];
vector<pair<int, int>> doors;
int px[4] = {-1,0,1,0}; // 위, 오른쪽, 아래, 왼쪽
int py[4] = {0,1,0,-1};

struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.cnt > b.cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == '#') {
                doors.push_back({i, j});
            }
        }
    }

    priority_queue<info, vector<info>, cmp> pq;
    int x = doors[0].first;
    int y = doors[0].second;
    for(int i=0;i<4;i++) {
        pq.push({0, x, y, i});
        // vst[i][x][y] = true; // TODO
    }
    
    while(!pq.empty()) {
        info cur = pq.top();
        pq.pop();

        if(cur.x == doors[1].first && cur.y == doors[1].second) {
            cout << cur.cnt;
            return 0;
        }

        if(vst[cur.dir][cur.x][cur.y]) continue;
        vst[cur.dir][cur.x][cur.y] = true;

        for(int i=0;i<N;i++) {
            int nx = cur.x + px[cur.dir] * i;
            int ny = cur.y + py[cur.dir] * i;

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[nx][ny] == '*') break;
            

            if (arr[nx][ny] == '!') {
                // 위, 아래일 경우, 왼쪽 또는 오른쪽
                if(cur.dir==0 || cur.dir==2) {
                    if (!vst[cur.dir][nx][ny]) {
                        pq.push({cur.cnt+1, nx, ny, 1});
                        pq.push({cur.cnt+1, nx, ny, 3});
                    }
                }
                // 왼쪽, 오른쪽일 경우, 아래 또는 위
                else {
                    if (!vst[cur.dir][nx][ny]) {
                        pq.push({cur.cnt+1, nx, ny, 0});
                        pq.push({cur.cnt+1, nx, ny, 2});
                    }
                }
            }
            if (arr[nx][ny] == '#') pq.push({cur.cnt, nx, ny, -1});
        }
    }
    
    return 0;
}