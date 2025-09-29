#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];
int ldp[1001][1001];
int rdp[1001][1001];

int main() {
	cin >> N >> M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	for(int j=2;j<=M;j++) {
		dp[1][j] = dp[1][j-1] + arr[1][j];
	}

	for(int i=2;i<=N;i++) {
		// ->
		ldp[i][1] = dp[i-1][1] + arr[i][1];
		for(int j=2;j<=M;j++) {
			ldp[i][j] = max(ldp[i][j-1], dp[i-1][j]) + arr[i][j];
		}
		// <-
		rdp[i][M] = dp[i-1][M] + arr[i][M]; 
		for(int j=M-1;j>=0;j--) {
			rdp[i][j] = max(rdp[i][j+1], dp[i-1][j]) + arr[i][j];
		}

		for(int j=1;j<=M;j++) {
			dp[i][j] = max(ldp[i][j], rdp[i][j]);
		}
	}
	
	cout << dp[N][M];
}