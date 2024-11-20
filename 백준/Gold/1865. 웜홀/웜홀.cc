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

int tc, n, m, w;
int s, e, t;

bool bellman_ford(vector<pair<pair<int,int>,int>> edge) {
    vector<ll> dist(n+1, INF);

    for(int i=0;i<n;i++) {
        for(int j=0;j<edge.size();j++) {
            ll a = edge[j].first.first;
            ll b = edge[j].first.second;
            ll cost = edge[j].second;

            if(dist[b] > dist[a] + cost) {
                dist[b] = dist[a] + cost;
                if(i == n-1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;
    while(tc--) {
        vector<pair<pair<int,int>,int>> edge;

        cin >> n >> m >> w;
        for(int i=0;i<m;i++) {
            cin >> s >> e >> t;
            edge.push_back({make_pair(s,e), t});
            edge.push_back({make_pair(e,s), t});
        }
        for(int i=0;i<w;i++) {
            cin >> s >> e >> t;
            edge.push_back({make_pair(s,e), -t});
        }

        if(bellman_ford(edge)) {
            cout << "YES\n";
        }
        else {
            cout <<"NO\n";
        }
    }

    return 0;
}
