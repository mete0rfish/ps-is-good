#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n;
int arr[1001];
bool visited[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int res = 1;
    for(int i=0;i<n-1;i++) {
        int cnt = upper_bound(arr, arr+n, arr[i]) - lower_bound(arr, arr+n, arr[i]);
        res = max(res, cnt);
    }

    cout << res;

    return 0;
}
