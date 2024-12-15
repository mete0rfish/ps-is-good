#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

ll N, B;
vector<pair<ll, ll> > v;

bool cmp(pair<ll,ll> a, pair<ll, ll> b) {
    return a.first + a.second < b.first + b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    int res = 0;
    for(int i=0;i<N;i++) {
        vector<pair<ll,ll>> tmp = v;
        tmp[i].first /= 2;

        sort(tmp.begin(), tmp.end(), cmp);
        int cnt = 0;
        ll sum = 0;
        for(int j=0;j<N;j++) {
            sum +=  tmp[j].first + tmp[j].second;

            if(sum > B) {
                break;
            }
            else {
                cnt++;
            }
        }
        res = max(res, cnt);
    }

    cout << res;

    return 0;
}
