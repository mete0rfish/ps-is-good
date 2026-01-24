#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 1. 빈칸의 구역 할당
 2. 모양의 크기 계산 -> 각 돌렸을 때 모두 저장
 3. 
*/
int N, M;
vector<vector<pair<int, int>>> puzzles;
vector<vector<pair<int ,int>>> emptys;

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

vector<pair<int, int>> normalize(vector<pair<int, int>> piece) {
    int min_x = 100, min_y = 100;
    for (auto& p : piece) {
        min_x = min(min_x, p.first);
        min_y = min(min_y, p.second);
    }
    
    for (auto& p : piece) {
        p.first -= min_x;
        p.second -= min_y;
    }
    
    sort(piece.begin(), piece.end());
    return piece;
}

vector<pair<int, int>> extract(int r, int c, int target, vector<vector<int>> table, bool vst[51][51]) {
    vector<pair<int ,int>> v;
    queue<pair<int, int>> q;
    
    q.push({r, c});
    vst[r][c] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        v.push_back({x, y});
        
        for (int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (vst[nx][ny]) continue;
            if (table[nx][ny] != target) continue;
            
            vst[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return normalize(v);
}

vector<pair<int, int>> rotate(vector<pair<int, int>> piece) {
    for (auto& p : piece) {
        int x = p.first;
        int y = p.second;
        p.first = y;
        p.second = -x;
    }
    return normalize(piece);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = game_board.size();
    M = game_board[0].size();
    
    bool vst1[51][51] = {false,};
    bool vst2[51][51] = {false, };
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (game_board[i][j] == 0 && !vst1[i][j]) {
                emptys.push_back(extract(i, j, 0, game_board, vst1));
            }
            if (table[i][j] == 1 && !vst2[i][j]) {
                puzzles.push_back(extract(i, j, 1, table, vst2));
            }
        }
    }
    
    vector<bool> used(puzzles.size(), false);
    
    for (auto b : emptys) {
        bool matched = false;
        for (int i=0;i<puzzles.size();i++) {
            if (used[i]) continue;
            if (puzzles[i].size() != b.size()) continue;
            
            vector<pair<int, int>> curr_puzzle = puzzles[i];
            for (int dir = 0; dir <4; dir++) {
                if (b == curr_puzzle) {
                    answer += b.size();
                    used[i] = true;
                    matched = true;
                    break;
                }
                curr_puzzle = rotate(curr_puzzle);
            }
            if (matched) break;
        }
    }
    
    return answer;
}