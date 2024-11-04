#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n, k, min_res;
int visited[100001];
int prevs[100001];
vector<int> path;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 0;

    while (!q.empty()) {
        int cur_pos = q.front();
        q.pop();
       
        if (cur_pos == k) {
            min_res = visited[cur_pos];
            int iter = cur_pos;
            while (iter != s) {
                path.push_back(iter);
                iter = prevs[iter];
            }
            path.push_back(s);
            return;
        }

        if ((cur_pos - 1 >= 0 && cur_pos - 1 <= 100000) && !visited[cur_pos - 1]) {
            q.push(cur_pos - 1);
            visited[cur_pos-1] = visited[cur_pos]+1;
            prevs[cur_pos - 1] = cur_pos;
        }
        if ((cur_pos + 1 >= 0 && cur_pos + 1 <= 100000) && !visited[cur_pos + 1]) {
            q.push(cur_pos + 1);
            visited[cur_pos + 1] = visited[cur_pos] + 1;
            prevs[cur_pos + 1] = cur_pos;
        }
        if ((cur_pos * 2 >= 0 && cur_pos * 2 <= 100000) && !visited[cur_pos * 2]) {
            q.push(cur_pos * 2);
            visited[cur_pos * 2] = visited[cur_pos] + 1;
            prevs[cur_pos * 2] = cur_pos;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    bfs(n);

    cout << min_res << endl;

    for (int i = path.size()-1; i >= 0; i--) {
        cout << path[i] << ' ';
    }

    return 0;
}
