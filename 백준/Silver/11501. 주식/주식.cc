#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}


		int large = -1;
		long long sum = 0;
		for (int cur = n; cur >= 1; cur--) {
			if (large < arr[cur]) {
				//cout << "changed: " << large << endl;
				large = max(large, arr[cur]);
			}
				
			else if (large >= arr[cur]) {
				int tmp = large - arr[cur];
				sum += tmp;
			}
		}

		cout << sum << "\n";
	}


}