#include <ios>
#include <iostream>
#include <queue>

using namespace std;

int N, M, p, q, res;
char ch;
vector<int> enemies[1001];
vector<int> friends[1001];
int vst[1001];
// 1:  
// 2:
// 3: 5
// 4: 6
// 5: 3
// 6: 4

void dfs(int a) {
    vst[a] = true;

    // 친구 DFS
    for (auto b : friends[a]) {
        if (vst[b]) continue;

        dfs(b);
    }

    // 적의 적
    for (auto b : enemies[a]) {
        for (auto c : enemies[b]) {
            if (vst[c]) continue;

            dfs(c);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i=0; i<M;i++) {
        cin >> ch >> p >> q;
        if (ch == 'F') {
            friends[p].push_back(q);
            friends[q].push_back(p);
        }
        else {
            enemies[p].push_back(q);
            enemies[q].push_back(p);
        }
    }

    for (int i=1;i<=N;i++) {
        if (vst[i]) continue;

        dfs(i);
        res++;
    }
    
    cout << res;
    return 0;
}
