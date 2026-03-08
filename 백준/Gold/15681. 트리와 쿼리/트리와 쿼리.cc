#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, R, Q;
int U, V;

vector<int> edges[100001];
bool vst[100001];
int subtreeCnt[100001];

void dfs(int cur) {
    vst[cur] = true;
    subtreeCnt[cur] = 1;

    for (int next : edges[cur]) {
        if (vst[next]) continue;

        dfs(next);

        subtreeCnt[cur] += subtreeCnt[next];
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;
    for (int i=0;i<N-1;i++) {
        cin >> U >> V;
        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    dfs(R);

    for (int i=0;i<Q;i++) {
        int tmp;
        cin >> tmp;
        cout << subtreeCnt[tmp]<< "\n";
    }
    return 0;
}