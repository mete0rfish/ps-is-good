#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
int arr[1000003];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++) {
        if(arr[i] != 0) continue;

        for(int idx=1;idx<=3;idx++) {
            if(arr[i-1] != idx && arr[i+1] != idx) {
                arr[i] = idx;
            }
        }
    }

    for(int i=1;i<=n-1;i++) {
        if(arr[i] == arr[i+1]) {
            cout << -1;
            return 0;
        }
    }

    for(int i=1;i<=n;i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
