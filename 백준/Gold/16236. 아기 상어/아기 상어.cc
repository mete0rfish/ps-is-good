#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
int space[21][21];
int shark_x, shark_y, shark_size = 2;
int eat_count = 0;
int total_time = 0;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool find_and_eat_fish() {
    int dist[21][21];
    fill(&dist[0][0], &dist[20][20], -1);
    queue<pair<int, int>> q;

    q.push({shark_x, shark_y});
    dist[shark_x][shark_y] = 0;

    vector<tuple<int, int, int>> edible_fishes;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(dist[nx][ny] != -1 || space[nx][ny] > shark_size) continue;
    
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
    
            if (space[nx][ny] > 0 && space[nx][ny] < shark_size) {
                edible_fishes.emplace_back(dist[nx][ny], nx, ny);
            }
        }
    }

    if (edible_fishes.empty()) {
        return false;
    }

    sort(edible_fishes.begin(), edible_fishes.end());

    auto [fish_dist, fish_x, fish_y] = edible_fishes[0];

    total_time += fish_dist;
    space[shark_x][shark_y] = 0;
    shark_x = fish_x; shark_y = fish_y;
    space[shark_x][shark_y] = 0;
    eat_count++;

    if (eat_count == shark_size) {
        shark_size++;
        eat_count = 0;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> space[i][j];
            if (space[i][j] == 9) {
                shark_x = i;
                shark_y = j;
            }
        }
    }
    
    while (find_and_eat_fish());

    cout << total_time << endl;

    return 0;
}