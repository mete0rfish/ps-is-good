#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int res = 1e9;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int l = 1, r = v[M-1];
    while(l <= r) {
        int m = (l + r) / 2;
        int cnt = 0;
        for(int i=0;i<M;i++) {
            cnt += (v[i] / m);
            if(v[i] % m != 0) cnt++;
        }
        if(cnt <= N) {
            r = m -1;
            res = min(res, m);
        }
        else {
            l = m+1;
        }
    }

    cout << res;
    
    return 0;
}