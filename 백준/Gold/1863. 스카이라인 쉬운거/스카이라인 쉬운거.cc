#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int a, b;
bool isUsed[500001];
int res;
stack<int> s;

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> a >> b;

		while(!s.empty() && s.top() > b) {
			res++;
			s.pop();
		}

		if(s.empty()) {
			s.push(b);
		}
		else if(!s.empty() && s.top() != b) {
			s.push(b);
		}
	}

	while(!s.empty()) {
		if(s.top() != 0) {
			res++;
		}
		
		s.pop();
	}
	cout << res;
}
