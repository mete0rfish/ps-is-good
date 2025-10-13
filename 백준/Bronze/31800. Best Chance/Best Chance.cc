#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int tmp;

vector<int> v1;
vector<int> v11;
vector<int> v2;

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> tmp;
		v1.push_back(tmp);
		v11.push_back(tmp);
	}

	for(int i=0;i<N;i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}

	sort(v11.begin(), v11.end());

	for(int i=0;i<N;i++) {
		int max_value = (v11[N-1] == v1[i] ? v11[N-2] : v11[N-1]);
		int gh = max_value - v2[i];
		int s = v1[i] - gh - v2[i];
		cout << s << " ";
	}
}
