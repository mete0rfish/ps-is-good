#include <iostream>
#include <queue>
#include <vector>
#include <cstring> 

using namespace std;

int R, C, N;
vector<string> maps;
bool vst[101][101];
bool c_vst[101][101];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void throws (int seq, int r) {
    r = R-r;
    if (seq % 2 == 0) { // 짝수면 왼쪽
        for (int c=0;c<C;c++) {
            if (maps[r][c] == 'x') {
                maps[r][c] = '.';
                return;
            }
        }
    }
    else {
        for (int c=C-1;c>=0;c--) {
            if (maps[r][c] == 'x') {
                maps[r][c] = '.';
                return;
            }
        }
    }
}

void check_cluster() {
    queue<pair<int ,int>> q;

    int r = R-1;
    for(int c=0;c<C;c++) {
        if (maps[r][c] == 'x') {
            q.push({r, c});
            vst[r][c] = true;
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];
            
            if (nx < 0 || ny<0 || nx>=R || ny>=C ) continue;
            if (vst[nx][ny]) continue;
            if (maps[nx][ny] == '.') continue;
            
            vst[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void find_non_cluster(vector<pair<int, int>>& cluster_points) {
    for(int r=0;r<R;r++) {
        for (int c=0;c<C;c++) {
            if (maps[r][c] == '.' || c_vst[r][c] || vst[r][c]) continue;

            queue<pair<int, int>> q;
            q.push({r, c});
            c_vst[r][c] = true;
            cluster_points.push_back({r, c});

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i=0;i<4;i++) {
                    int nx = x + px[i];
                    int ny = y + py[i];

                    if (nx<0 || ny<0 || nx>=R || ny>=C) continue;
                    if (c_vst[nx][ny]) continue;
                    if (maps[nx][ny] == '.') continue;

                    c_vst[nx][ny] = true;
                    q.push({nx, ny});
                    cluster_points.push_back({nx, ny});
                }
            }
        }
    }
}

void drop_non_cluster(vector<pair<int, int>>& cluster_points) {
    if (cluster_points.empty()) return;

    // 기존 위치 지우기
    for (auto cp : cluster_points) {
        maps[cp.first][cp.second] = '.';
    }

    // 최소 x 거리 구하기
    int mn_dist = R;
    for (auto cp : cluster_points) {
        int x = cp.first;
        int y = cp.second;

        int dist = 0;
        while (x+1 < R && maps[x+1][y] == '.') {
            x++;
            dist++;
        }

        mn_dist = min(mn_dist, dist);
    }

    // 최소 x 거리 + x에 위치 잡기
    for (auto cp : cluster_points) {
        maps[cp.first + mn_dist][cp.second] = 'x';
    }
}

int main() 
{
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string str;
        cin >> str;
        maps.push_back(str);
    }
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int tmp; cin >> tmp;
        vector<pair<int, int>> cluster_points;
        memset(vst, false, sizeof(vst));
        memset(c_vst, false, sizeof(c_vst));
        
        throws(i, tmp);
        check_cluster();
        find_non_cluster(cluster_points);
        drop_non_cluster(cluster_points);
        
        // cout << endl;
        // for(int i=0;i<R;i++) {
        //     for(int j=0;j<C;j++) {
        //         cout << c_vst[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout << maps[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
