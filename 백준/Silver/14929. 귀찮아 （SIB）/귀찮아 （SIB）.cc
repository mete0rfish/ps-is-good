#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long arr[100001];
long long dp[100001];

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        if(i == 0) dp[i] = arr[i];
        else dp[i] = dp[i-1] + arr[i];
    }
    long long sum = 0;
    for(int i=0;i<N;i++) {
        sum += arr[i] * (dp[N-1] - dp[i]);
    }

    cout << sum;
    
    return 0;
}