#include <iostream>
#include <map>

using namespace std;

int N, a, b;
map<int, int> xx;
map<int, int> yy;

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> a >> b;
		xx[a]++;
		yy[b]++;
	}

	int res = 0;
	for(auto x : xx) {
		if(x.second >= 2) res++;
	}

	for(auto y : yy) {
		if(y.second >= 2) res++;
	}

	cout << res;
}