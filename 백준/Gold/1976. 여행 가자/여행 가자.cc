#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, M;
int tmp;
vector<int> target;
vector<int> edge[201];
bool visited[201];

void dfs(int t) {
    visited[t] = true;
    for (int e : edge[t]) {
        if (!visited[e]) {
            dfs(e);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            if (tmp == 1) {
                edge[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        target.push_back(tmp);
    }

    dfs(target[0]);

    for (int i = 0; i < M; i++) {
        if (!visited[target[i]]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}