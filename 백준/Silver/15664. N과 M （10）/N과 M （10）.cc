#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int arr[10];
int res[10];
bool visited[10];
bool chked[10];

void func(int k, int idx) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i]<<' ';
		}
		cout << '\n';
		return;
	}

	int prev = 0;
	for (int i = idx; i < n; i++) {
		if (!visited[i] && prev != arr[i]) {
			if (k == 0 || res[k - 1] <= arr[i]) {
				res[k] = arr[i];
				visited[i] = true;
				prev = arr[i];
				func(k + 1, idx + 1);
				visited[i] = false;
			}
			
		}
	}
}

int main() {
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0, 0);
}