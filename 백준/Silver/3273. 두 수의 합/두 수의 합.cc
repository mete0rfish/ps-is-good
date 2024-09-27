#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define ll long long
#define MAX 2000000001

int n, x;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    cin >> x;

    sort(v.begin(), v.end());

    int st = 0, ed = n-1;
    int cnt = 0;
    while(1) {
        if(st >= ed) {
            break;
        }

        int sum = v[st] + v[ed];
        if(sum == x) {
            cnt++;
            st++;
            ed--;
        }
        else if(sum < x) {
            st++;
        }
        else {
            ed--;
        }
    }

    cout << cnt;

    return 0;
}
