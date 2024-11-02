#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n, k, cnt_res, min_res;
bool visited[100001];
bool isFirst = true;

void bfs(int s) {
    queue<pair<int, int>> q;
    q.push({s, 0});


    while(!q.empty()) {
        int cur_pos = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();
        visited[cur_pos] = true;

        if(cur_pos == k) {
            if(isFirst) {
                isFirst = false;
                min_res = cur_cnt;
                cnt_res++;
            }
            else if(!isFirst && min_res == cur_cnt) {
                cnt_res++;
            }
        }

        if((cur_pos-1 >= 0 && cur_pos-1 <= 100000) && !visited[cur_pos-1]) {
            //visited[cur_pos-1] = true;
            q.push({cur_pos-1 , cur_cnt + 1});
        }
        if((cur_pos+1 >= 0 && cur_pos+1 <= 100000) && !visited[cur_pos+1]) {
            //visited[cur_pos+1] = true;
            q.push({cur_pos+1 , cur_cnt + 1});
        }
        if((cur_pos*2 >= 0 && cur_pos*2 <= 100000) && !visited[cur_pos*2]) {
            //visited[cur_pos*2] = true;
            q.push({cur_pos*2 , cur_cnt + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    bfs(n);

    cout << min_res << endl << cnt_res;

    return 0;
}
