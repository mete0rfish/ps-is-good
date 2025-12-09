#include <algorithm>
#include <ios>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int arr[11][11];
bool vst[11];
int mn_time = 1e9;

void dfs(int idx, int cur_time, int vst_cnt) {
    if (vst_cnt == N) {
        mn_time = min(mn_time, cur_time);
        return;
    }

    if(cur_time >= mn_time) return;

    for (int i=1;i<=N;i++) {
        if (vst[i]) continue;

        vst[i] = true;
        dfs(i, cur_time + arr[idx][i], vst_cnt + 1);
        vst[i] = false;
    }
}

int main() {
    cin >> N >> K;

    for (int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if (i == j) continue;
            arr[i][j] = 1e9;
        }
    }

    for (int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }

    for (int k = 1;k<=N; k++) {
        for(int i = 1; i<=N;i++) {
            for (int j=1;j<=N;j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    K++;
    vst[K] = true;
    dfs(K, 0, 1);
    
    cout << mn_time;

    return 0;
}
