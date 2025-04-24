#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int res[10];
bool visited[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (prev != arr[i]) {
			if (k == 0 || res[k - 1] <= arr[i]) {
				res[k] = arr[i];
				prev = arr[i];
				func(k + 1);
			}
			
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	func(0);
}