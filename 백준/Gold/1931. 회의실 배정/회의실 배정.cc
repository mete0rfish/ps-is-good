#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int n;
vector<pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }

    sort(v.begin(), v.end());

    int last = v[0].first;
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if(v[i].second >= last) {
            last = v[i].first;
            cnt++;
        }
    }

    cout << cnt;
}
