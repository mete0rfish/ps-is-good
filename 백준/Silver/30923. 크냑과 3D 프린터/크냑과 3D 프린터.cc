#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
long sum;
long arr[32769];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        sum += arr[i]*2;
    }
    sum += n*2;
    sum += arr[0] + arr[n-1];

    for(int i=0;i<n-1;i++) {
        sum += abs(arr[i]- arr[i+1]);
    }

    cout << sum;

    return 0;
}
