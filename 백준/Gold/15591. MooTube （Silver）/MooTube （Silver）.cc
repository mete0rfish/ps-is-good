#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

vector<pair<long, long>> edge[5001];
bool vst[5001];
int res;
int K, V;
int N, Q;

void dfs(int x) {

    for(int i=0;i<edge[x].size();i++) {
        int node = edge[x][i].first;
        if(vst[node])  continue;
        if(edge[x][i].second < K) continue;

        vst[node] = true;
        dfs(node);
        res++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p, q, r;
    cin >> N >> Q;
    for(int i=0;i<N-1;i++) {
        cin >> p >> q >> r;
        edge[p].push_back(make_pair(q, r));
        edge[q].push_back(make_pair(p, r));
    }

    for(int i=0;i<Q;i++) {
        cin >> K >> V;

        memset(vst, false, sizeof(vst));
        res = 0;
        vst[V] = true;

        dfs(V);
        cout << res << endl;
    }
}
