#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void func(int idx,int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (!used[i]) {

				arr[k] = i;
				used[i] = true;
				func(i+1,k + 1);
				used[i] = false;
			
			
		}

	}


}

int main() {

	cin >> n >> m;
	func(1,0);
	return 0;
}