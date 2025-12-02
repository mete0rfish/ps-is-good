#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int N;
char arr[7][7];
vector<pair<int, int>> wallable;
bool wallable_vst[37];
vector<pair<int ,int>> walls;
vector<pair<int, int>> teachers;

bool vst[7][7];
int catched_cnt;
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};
string res = "NO";

void dfs(int x, int y, int dir, map<pair<int,int>, bool>& m) {
    if(arr[x][y] == 'S' && !m[{x, y}]) {
        catched_cnt++;
    }
    
    int nx = x + px[dir];
    int ny = y + py[dir];
    
    if (nx < 0 || ny < 0 || nx>=N || ny>=N) return;
    if(vst[x][y]) return;
    
    dfs(nx, ny, dir,m);
}

void choose(int idx, int cnt) {
    if (cnt == 3) {
        memset(vst, false, sizeof(vst));
        catched_cnt = 0;
        map<pair<int, int>, bool> m;

        for(auto w : walls) {
            vst[w.first][w.second] = true;
        }
        
        for(auto t : teachers) {
            for(int dir=0;dir<4;dir++) {
                dfs(t.first, t.second, dir, m);
            }
        }
        
        if (catched_cnt == 0) {
            cout << "YES";
            exit(0);
        }
        return;
    }
    
    for (int i=idx; i<wallable.size();i++) {
        if (wallable_vst[i]) continue;
        
        wallable_vst[i] = true;
        walls.push_back({wallable[i].first, wallable[i].second});
        choose(i+1, cnt+1);
        walls.pop_back();
        wallable_vst[i] = false;
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'X') wallable.push_back({i, j});
            else if (arr[i][j] == 'T') teachers.push_back({i,j});
        }
    }
    
    choose(0, 0);
    
    cout << res;
    return 0;
}
