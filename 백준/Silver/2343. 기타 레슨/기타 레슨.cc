#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int res=1e9, mid;
int arr[100001];

int check(int target) {
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<N;i++) {
        if(sum + arr[i] > target) {
            cnt++;
            sum = 0;
        }
        sum += arr[i];
    }

    if(sum != 0)cnt++;

    return cnt;
}

void func(int l, int r) {
    if(l > r) return;

    mid = (l+r)/2;
    
    int cnt = check(mid);
    if(cnt > M) {
        func(mid+1, r);
    }
    else {
        res=min(res,mid);
        func(l, mid-1);
    }
}

int main() {
    cin >> N >> M;
    int sum = 0;
    int max_ele=0;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        sum += arr[i];
        max_ele = max(max_ele, arr[i]);
    }

    int l= max_ele,r = sum;

    func(l, r);

    cout << res;
    return 0;
}