#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int r,c,m,d,s;

typedef struct {
    int r,c,m, d, s;
} fireball;

vector<fireball> board[51][51];

int px[8] = {-1,-1,0,1,1, 1, 0,-1};
int py[8] = { 0, 1,1,1,0,-1,-1,-1};

int main() 
{
    cin >> N >> M >> K;

    for (int i=0;i<M;i++) {
        cin >> r >> c >> m >> s >> d;
        board[r-1][c-1].push_back({r-1,c-1,m,d,s});
    }

    for (int t=1;t<=K;t++) {
        queue<fireball> tmp;
        // 1. 살아있는 파이어볼 백업

        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (board[i][j].size() < 1) continue;

                for (auto& fb : board[i][j]) {
                    tmp.push(fb);
                }

                board[i][j].clear();
            }
        }


        // 2. 파이어볼 이동
        while (!tmp.empty()) {
            auto fb = tmp.front();
            tmp.pop();

            int nx = (fb.r + px[fb.d] * (fb.s % N) + N) % N;
            int ny = (fb.c + py[fb.d] * (fb.s % N) + N) % N;

            board[nx][ny].push_back({nx, ny, fb.m, fb.d, fb.s});
        }

        // 3. 중복 파이어볼 분열
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (board[i][j].size() < 2) continue;

                // 3-1. 질량, 속력
                int cnt = board[i][j].size();
                int new_m=0, new_s=0, new_d;
                bool odd = true, even = true;

                for (auto& fb : board[i][j]) {
                    new_m += fb.m;
                    new_s += fb.s;

                    if (fb.d % 2 == 0) odd = false;
                    else even = false;
                }

                new_m /= 5;
                new_s /= cnt;

                board[i][j].clear();


                // 3-2. 질량이 0이면 패스
                if (new_m == 0) continue;


                // 3-3. 방향대로 board에 매핑
                int start_d = (even || odd) ? 0 : 1;

                for (int dir=0;dir<4;dir++) {
                    int nd = start_d + (dir*2);
                    board[i][j].push_back({i, j, new_m, nd, new_s});
                }
            }
        }
    }

    int answer = 0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (board[i][j].size() < 1) continue;

            for (auto& fb : board[i][j]) {
                answer += fb.m;
            }
        }
    }

    cout << answer;

    return 0;
}

