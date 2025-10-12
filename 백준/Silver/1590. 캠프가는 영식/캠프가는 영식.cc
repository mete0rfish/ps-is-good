#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, T, S, I, C;
int res=1e9;

int main() {
	cin >> N >> T;
	while(N--) {
		cin >> S >> I >> C;
		for(int i=0;i<C;i++){
			int t = S + I*i;
			if(t-T == 0) res = 0;
			else if(t-T > 0 && res > t-T) {
				res = t-T;
			}
		}
	}

	if(res == 1e9) cout << -1;
	else cout << res;
}
