#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, C;
int res = 0;
int arr[200001];
vector<int> v;

// 1, 2, 4, 8, 9
// 0~4 : (0 + 4) / 2 => 2
// 0~1 : (0 + 1) / 2 => 0
// 3~4 : (3 + 4) / 2 => 3

bool func(int dist) {
    int cnt = 1;

    int prev = arr[0];
    for (int i=1;i<N;i++) {
        int cur = arr[i];

        if (cur - prev >= dist) {
            cnt++;
            prev = cur;
        }
    }

    return cnt >= C;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> C;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int s = 1;
    int e = arr[N-1] - arr[0];

    while (s <= e) {
        int m = s + (e-s)/2;

        if (func(m)) {
            res = max(res, m);
            s = m+1;
        } else { 
            e = m-1;
        }
    }

    cout << res << endl;
    return 0;
}
