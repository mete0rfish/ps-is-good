#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[201];
int N;
int arr[201];

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> arr[i];
	}

	int max_len = 1;
	fill(&dp[0], &dp[201], 1);
	for(int i=1;i<N;i++) {
		for(int j=0;j<i;j++) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		max_len = max(max_len, dp[i]);
	}

	cout << N - max_len;
}