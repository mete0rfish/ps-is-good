#include <algorithm>
#include <ios>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int idx = 1;
int arr[51][51];
int vst[51][51];
vector<int> v;

int px[4] = {0,-1,0,1};
int py[4] = {-1,0,1,0};

// 1, 2, 4, 8, 

void bfs(int x, int y) {
    queue<pair<int ,int>> q;
    q.push({x, y});
    vst[x][y] = idx;
    int cnt = 1;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            // cout << xx << ", " << yy << ": " << pow(2,i) << "->" << ((arr[xx][yy] >> i) & 1)  << endl;
            if (((arr[xx][yy] >> i) & 1) == 1) continue;

            int nx = xx + px[i];
            int ny = yy + py[i];

            if (nx <0 || ny <0 || nx>=N || ny>=M) continue;
            if (vst[nx][ny] != 0) continue;
            
            q.push({nx, ny});
            vst[nx][ny] = idx;
            cnt++;
        }
    }

    v.push_back(cnt);
}

int main() {
    cin >> M >> N;

    
    for (int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if (vst[i][j]) continue;

            bfs(i, j);
            idx++;
        }
    }

    cout << v.size() << "\n";
    cout << *max_element(v.begin(), v.end())<< "\n";

    int mx = 0;
    for (int x=0;x<N;x++) {
        for (int y=0;y<M;y++) {
            int cur_idx = vst[x][y];

            for (int i=0;i<4;i++) {
                int nx = x + px[i];
                int ny = y + py[i];

                if (nx <0 || ny <0 || nx>=N || ny>=M) continue;

                int next_idx = vst[nx][ny];
                if (cur_idx != next_idx) {
                    mx = max(v[cur_idx-1] + v[next_idx-1], mx);
                }
            }
        }
    }

    cout << mx;
    return 0;
}
