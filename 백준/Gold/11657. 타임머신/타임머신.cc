#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long
#define INF 9999999999

using namespace std;

int n,m;
ll dist[502];
bool isCycle;
vector<pair<int,int>> edge[6002];

void bellman_ford() {
    dist[1] = 0;
    for(int cnt=0;cnt<n;cnt++) {
        for(int i=1;i<=n;i++) {
            for(int j=0;j<edge[i].size();j++) {
                int next_idx = edge[i][j].first;
                int cost = edge[i][j].second;

                if(dist[i] == INF)  continue;
                if(dist[i] + cost < dist[next_idx]) {
                    dist[next_idx] = dist[i] + cost;
                    if(cnt == n-1)
                        isCycle = true;
                }
            }
        }
    }

    if(isCycle) {
        cout << -1;
    }
    else {
        for(int i=2;i<=n;i++) {
            cout << (dist[i]==INF ? -1 : dist[i])  << "\n";
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a ,b,c;
    cin >> n >> m;
    fill(dist, dist+501, INF);

    for(int i=0;i<m;i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
    }

    bellman_ford();
    return 0;
}
