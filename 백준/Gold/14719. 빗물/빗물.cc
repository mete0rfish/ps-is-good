#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

int H, W;
int arr[501];
int left_max[501];
int right_max[501];

int main() {
	cin >> H >> W;
	
	for(int i=0;i<W;i++) cin >> arr[i];

	// -> : i 포함 최대 높이

	left_max[0] = arr[0];
	for(int i=1;i<W;i++) {
		left_max[i] = max(left_max[i-1], arr[i]);
	}
	right_max[W-1] = arr[W-1];
	for(int i=W-2;i>=0;i--) {
		right_max[i] = max(right_max[i+1], arr[i]);
	}

	int res = 0;
	for(int i=1;i<W-1;i++) {
		int t = min(left_max[i], right_max[i]);
		res += (t - arr[i]);
	}

	cout << res;
}
