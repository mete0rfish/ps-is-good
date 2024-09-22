#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define ll long long

ll n;
ll sum;
vector<pair<ll, ll> > X;
vector<pair<ll, ll> > Y;
vector<pair<ll, ll> > Z;
vector<pair<ll,pair<ll,ll>>> edge;
ll parent[100001];

ll find_parent(ll target) {
    if (parent[target] == target) {
        return target;
    }
    return find_parent(parent[target]);
}

void union_parent(ll a, ll b) {
    int pa = find_parent(a);
    int pb = find_parent(b);

    if (pa < pb) {
        parent[pb] = pa;
    } else {
        parent[pa] = pb;
    }
}

void kruskal() {
    for (int i = 0; i < edge.size(); i++) {
        ll a = edge[i].second.first;
        ll b = edge[i].second.second;
        if (find_parent(a) != find_parent(b)) {
            sum += edge[i].first;
            union_parent(a, b);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
        Z.push_back(make_pair(z, i));
        parent[i] = i;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < n - 1; i++) {
        edge.push_back(make_pair(X[i+1].first - X[i].first, make_pair(X[i].second, X[i+1].second)));
        edge.push_back(make_pair(Y[i+1].first - Y[i].first, make_pair(Y[i].second, Y[i+1].second)));
        edge.push_back(make_pair(Z[i+1].first - Z[i].first, make_pair(Z[i].second, Z[i+1].second)));
    }

    sort(edge.begin(), edge.end());

    kruskal();
    cout << sum;
    return 0;
}
