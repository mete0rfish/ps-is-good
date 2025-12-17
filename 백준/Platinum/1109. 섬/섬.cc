#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int N, M;
vector<string> maps;
int areas[55][55];
int total_area_cnt;
bool vst[55][55];
vector<pair<int,int>> area_starts;
set<int> adj[3000];
int dists[3000];
bool is_island[3000];
int res[3000];

int px[8] = {-1,0,1,0, -1,-1,1,1};
int py[8] = {0,-1,0,1, -1,1,-1,1};


void bfs_island(int a, int b, int area) {
    queue<pair<int, int>> q;
    q.push({a, b});
    vst[a][b] = true;
    areas[a][b] = area;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0;i<8;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (vst[nx][ny]) continue;
            if (maps[nx][ny] != 'x') continue;

            vst[nx][ny] = true;
            areas[nx][ny] = area;
            q.push({nx, ny});
        }
    }
}

void bfs_occean(int a, int b, int area) {
    queue<pair<int, int>> q;
    q.push({a, b});
    vst[a][b] = true;
    areas[a][b] = area;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (vst[nx][ny]) continue;
            if (maps[nx][ny] != '.') continue;

            vst[nx][ny] = true;
            areas[nx][ny] = area;
            q.push({nx, ny});
        }
    }
}

void check_area() {
    total_area_cnt = 0;


    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (vst[i][j]) continue;

            total_area_cnt++;

            if (maps[i][j] == 'x') {
                is_island[total_area_cnt] = true;
                bfs_island(i, j, total_area_cnt);
            } else {
                is_island[total_area_cnt] = false;
                bfs_occean(i, j, total_area_cnt);
            }
        }
    }
}

void check_adj() {
    for (int x=0;x<N;x++) {
        for (int y=0;y<M;y++) {
            int cur_area = areas[x][y];

            for (int i=0;i<4;i++) {
                int nx = x + px[i];
                int ny = y + py[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                int next_area = areas[nx][ny];

                if (cur_area != next_area) {
                    adj[cur_area].insert(next_area);
                    adj[next_area].insert(cur_area);
                }
            }
        }
    }
}

void check_height() {
    memset(dists, -1, sizeof(dists));
    
    int root_id = areas[0][0];
    queue<int> q;
    q.push(root_id);
    dists[root_id] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (dists[next] == -1) {
                dists[next] = dists[cur]+1;
                q.push(next);
            }
        }
    }

    // 높이 계산

    vector<int> h_vec(total_area_cnt+1, 0);
    vector<pair<int, int>> nodes; // dist, id

    for (int i=1;i<=total_area_cnt;i++) {
        if (dists[i] != -1) {
            nodes.push_back({dists[i], i});

            if (is_island[i]) h_vec[i] = 1;
        }
    }

    sort(nodes.rbegin(), nodes.rend());

    for (auto n : nodes) {
        int cur = n.second;
        int cur_dist = n.first;

        for (int p : adj[cur]) {
            if (dists[p] < cur_dist) { // 만약 부모이면
                if (is_island[cur]) {
                    h_vec[p] = max(h_vec[p], h_vec[cur]);
                } else {
                    h_vec[p] = max(h_vec[p], h_vec[cur]+1);
                }
            }
        }
    }

    int mx_h = 0;
    bool flag = false;

    for (int i=1;i<=total_area_cnt;i++) {
        if (!is_island[i]) continue;
        if (dists[i] == -1) continue;

        flag = true;
        res[h_vec[i]]++;
        mx_h = max(mx_h, h_vec[i]);
    }

    if(!flag) {
        cout << "-1";
        return;
    }

    for (int i=1;i<=mx_h;i++) {
        cout << res[i] << " ";
    }
}

int main() {
    cin >> N >> M;
    string border(M+2, '.');
    maps.push_back(border);

    for(int i=0;i<N;i++) {
        string str;
        cin >> str;
        maps.push_back("."+str+".");
    }
    maps.push_back(border);
    N+=2;
    M+=2;

    check_area();
    check_adj();
    check_height();

    return 0;
}
