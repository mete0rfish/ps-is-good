#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int n, cnt;
int a, b, c, d;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++) {
       cin >> a >> b >> c >> d;
        v.push_back(make_pair(a*100 + b, c*100 + d));
    }

    sort(v.begin(), v.end());

    int i = 0, end = 301;
    while(end < 1131) {
        int maxi = 0;
        bool flag = false;
        for(;i<n;i++) {
            if(v[i].first <= end) {

                maxi = max(maxi, v[i].second);
                flag = true;
            }
            else {
                break;
            }
        }

        if(!flag) {
            cout << 0;
            return 0;
        }

        end = maxi;
        cnt++;
    }

    cout << cnt;
}
