#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
pair<int, int> r_start_pos;
pair<int, int> b_start_pos;
pair<int, int> r_end_pos;
pair<int, int> b_end_pos;
bool rvst[5][5];
bool bvst[5][5];
int mn_cnt = 1e9;

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x<N && y<M;
}

void dfs(vector<vector<int>>& maze, int rx, int ry, int bx, int by, int cnt, bool rarrived, bool barrived) {
    if (make_pair(rx, ry) == r_end_pos) rarrived = true;
    if (make_pair(bx, by) == b_end_pos) barrived = true;
    
    if (rarrived && barrived) {
        mn_cnt = min(mn_cnt, cnt);
        return;
    }
    
    if (cnt >= mn_cnt) return;
    
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            int nrx = rx + (rarrived ? 0 : px[i]); 
            int nry = ry + (rarrived ? 0 : py[i]);
            int nbx = bx + (barrived ? 0 : px[j]); 
            int nby = by + (barrived ? 0 : py[j]);
            
            if (!rarrived && (!isValid(nrx, nry) || maze[nrx][nry] == 5)) continue;
            if (!barrived && (!isValid(nbx, nby) || maze[nbx][nby] == 5)) continue;
            
            if (!rarrived && rvst[nrx][nry]) continue;
            if (!barrived && bvst[nbx][nby]) continue;
            
            // 충돌 검사
            // 1. 같은 곳으로 이동 불가
            if (nrx == nbx && nry == nby) continue;
            
            // 2. 서로 자리 변경 불가
            if (nrx == bx && nry == by && nbx == rx && nby == ry) continue;
            
            if (!rarrived) rvst[nrx][nry] = true;
            if (!barrived) bvst[nbx][nby] = true;
            dfs(maze, nrx, nry, nbx, nby, cnt + 1, rarrived, barrived);
            if (!rarrived) rvst[nrx][nry] = false;
            if (!barrived) bvst[nbx][nby] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    N = maze.size();
    M = maze[0].size();
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (maze[i][j] == 1)  r_start_pos = make_pair(i, j);
            else if (maze[i][j] == 2)  b_start_pos = make_pair(i, j);
            else if (maze[i][j] == 3)  r_end_pos = make_pair(i, j);
            else if (maze[i][j] == 4)  b_end_pos = make_pair(i, j);
        }
    }
    
    int answer = 0;
    
    rvst[r_start_pos.first][r_start_pos.second] = true;
    bvst[b_start_pos.first][b_start_pos.second] = true;
    
    dfs(maze, r_start_pos.first, r_start_pos.second, b_start_pos.first, b_start_pos.second, 0, false ,false);
   
    mn_cnt = (mn_cnt == 1e9) ? 0 : mn_cnt;
    return mn_cnt;
}