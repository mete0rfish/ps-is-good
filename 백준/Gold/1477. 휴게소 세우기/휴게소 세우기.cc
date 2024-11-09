#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 9999999


int n, m, l;
int res;
vector<int> v;

int check(int mid) {
	int cnt = 0;
	for (int i = 1; i < v.size(); i++) {
		int dis = v[i] - v[i - 1];
		cnt += (dis / mid);
		if (dis % mid == 0) {
			cnt--;
		}
	}
	return cnt;
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	cin >> n >> m >> l;
	v.push_back(0);
	v.push_back(l);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int left = 1;
	int right = l;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = check(mid);

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			res = mid;
			right = mid - 1;
		}
	}
	cout << res;
}

