#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

pair<int, int> s_pos, h_pos;
vector<pair<int, int>> f_pos;
int dist_start[1001][1001];
int dist_home[1001][1001];

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void bfs_start(int n, int m, vector<string> vec) {
    memset(dist_start, -1, sizeof(dist_start));
    queue<pair<int ,int>> q;
    q.push(s_pos);
    dist_start[s_pos.first][s_pos.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vec[nx][ny] == 'D') continue;
            if (dist_start[nx][ny] != -1) continue;

            dist_start[nx][ny] = dist_start[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void bfs_home(int n, int m, vector<string> vec) {
    memset(dist_home, -1, sizeof(dist_home));
    queue<pair<int ,int>> q;
    q.push(h_pos);
    dist_home[h_pos.first][h_pos.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vec[nx][ny] == 'D') continue;
            if (dist_home[nx][ny] != -1) continue;

            dist_home[nx][ny] = dist_home[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int calc() {
    int res = 1e9;
    bool flag = false;
    for (auto f : f_pos) {
        if (dist_start[f.first][f.second] != -1 && dist_home[f.first][f.second] != -1) {
            res = min(res, dist_start[f.first][f.second] + dist_home[f.first][f.second]);
            flag = true;
        }       
    }
        
    return flag ? res : -1;
}

int solution(int n, int m, vector<string> vec) {
    int answer = 0;

    // 현재 -> 가장 가까운 물고기 이동, dist와 pair
    bfs_start(n, m, vec);
    bfs_home(n, m, vec);

    answer = calc();
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> vec;

    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        vec.push_back(str);

        for (int j=0; j<str.length();j++) {
            if (str[j] == 'S') s_pos = {i, j};
            else if (str[j] == 'H') h_pos = {i, j};
            else if (str[j] == 'F') f_pos.push_back({i, j});
        }
    }

    cout << solution(n, m, vec);

    return 0;
}
