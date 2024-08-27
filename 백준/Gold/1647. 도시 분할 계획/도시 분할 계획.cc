#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

#define ll long long
using namespace std;

int n, m;
vector<pair<int, pair<int, int> > > v;
int parent[100001];

int find_parent(int target) {
    if (parent[target] == target) {
        return target;
    }
    return find_parent(parent[target]);
}

void union_parent(int a, int b) {
    int ap = find_parent(a);
    int bp = find_parent(b);

    if (ap < bp) {
        parent[bp] = ap;
    } else {
        parent[ap] = bp;
    }
}

void cruskal() {
    int res = 0;
    int max_cost = 0;

    for (int i = 0; i < v.size(); i++) {
        pair<int, pair<int, int> > cur = v[i];

        if (find_parent(cur.second.first) != find_parent(cur.second.second)) {
            max_cost = max(max_cost, cur.first);
            res += cur.first;
            union_parent(cur.second.first, cur.second.second);
        }
    }

    cout << res - max_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    int total = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a, b)));
        total += a;
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    sort(v.begin(), v.end());

    cruskal();

    return 0;
}
