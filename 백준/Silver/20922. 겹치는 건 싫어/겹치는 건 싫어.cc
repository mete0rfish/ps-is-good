#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[200001];
int cnt[100001];

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int res = 0;
    cnt[arr[0]]++;
    int l = 0, r = 1;
    while(l < N && r < N) {
        if(cnt[arr[r]] >= K) {
            cnt[arr[l]]--;
            l++;
        }
        else {

            cnt[arr[r]]++;
            r++;
        }
        res = max(res, r - l);
    }

    cout << res;
    
    return 0;
}