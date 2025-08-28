#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int cnt, x, y, dir;
}info;

struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.cnt > b.cnt;
    } 
};

int N;
char arr[51][51];
bool vst[5][51][51];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};
priority_queue<info, vector<info>, cmp> q;
vector<pair<int, int>> doors;

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

    int dx = doors[0].first;
    int dy = doors[0].second;
    for(int i=0;i<4;i++) {
        q.push({0,dx,dy,i});
    }


    while(!q.empty()) {
        int cnt = q.top().cnt;
        int x = q.top().x;
        int y = q.top().y;
        int dir = q.top().dir;
        q.pop();

        if(x == doors[1].first && y == doors[1].second) {
            cout << cnt;
            return 0;
        }

        if(vst[dir][x][y]) continue;
        vst[dir][x][y] = true;

        for(int i=0;i<N;i++){
            int nx = x + px[dir]*i;
            int ny = y + py[dir]*i;

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
            if(arr[nx][ny] == '*') break;

            if(arr[nx][ny] == '!') {
                if(dir == 0 || dir == 2) {
                    if(!vst[dir][nx][ny]) {
                        q.push({cnt+1, nx, ny, 1});
                        q.push({cnt+1, nx, ny, 3});
                    }
                }
                else {
                    if(!vst[dir][nx][ny]) {
                        q.push({cnt+1, nx, ny, 0});
                        q.push({cnt+1, nx, ny, 2});
                    }
                }
            }
            if(arr[nx][ny] == '#') {
                q.push({cnt, nx, ny, 0});
            }
        }
        
    }
    return 0;
}