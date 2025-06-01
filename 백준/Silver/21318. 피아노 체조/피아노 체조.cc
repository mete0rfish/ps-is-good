#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    
    dp[1] = 0;
    
    for(int i=2;i<=N;i++) {
        dp[i] = dp[i-1];
        if(arr[i] < arr[i-1]) {
            dp[i]++;
        }
    }
    
    int a, b;
    cin >> M;
    while(M--) {
        cin >> a >> b;
        cout << dp[b] - dp[a] << "\n";
    }
    
    return 0;
}

// -10 -9 2 4 4

