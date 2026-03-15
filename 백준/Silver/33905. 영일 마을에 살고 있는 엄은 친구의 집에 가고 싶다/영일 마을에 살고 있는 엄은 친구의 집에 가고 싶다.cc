#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
vector<int> edges[10001];
bool vst[10001];

int main() 
{
    cin >> N >> M >> K;
    for (int i=0;i<M;i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i=0;i<K;i++) {
        int k;
        cin >> k;
        vst[k] = true;
    }

    int cnt = 0;


    queue<int> q;
    q.push(1);
    vst[1] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        cnt++;

        for (int next : edges[curr]) {
            if (vst[next]) continue;

            vst[next]=true;
            q.push(next);
        }
    }

    cout << cnt-1;
    return 0;
}