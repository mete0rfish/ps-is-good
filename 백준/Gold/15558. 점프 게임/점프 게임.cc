#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int l, i, t;
}info;

int N, k;
vector<string> line(2);
bool vst[2][100001];

int main() 
{
    cin >> N >> k;
    cin >> line[0] >> line[1];

    queue<info> q;
    q.push({0, 0, 0});
    vst[0][0] = true;

    int pl[3] = {0,0,1};
    int pi[3] = {1,-1,k};

    while (!q.empty()) {
        int cur_line = q.front().l;
        int cur_idx = q.front().i;
        int cur_time = q.front().t;
        q.pop();

        for (int i=0;i<3;i++) {
            int next_line = (i==2) ? 1-cur_line : cur_line;
            int next_idx = cur_idx + pi[i];
            int next_time = cur_time + 1;

            if (next_idx >= N) {
                cout << 1;
                return 0;
            }
            // next_idx가 0이면 패스
            // next_idx <= next_time 패스

            if (next_idx < next_time) continue;
            if (line[next_line][next_idx] == '0') continue;
            if (vst[next_line][next_idx]) continue;

            q.push({next_line, next_idx, next_time});
            vst[next_line][next_idx] = true;
        }
    }

    cout << 0;

    return 0;
}

