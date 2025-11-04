#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>

using namespace std;

/*
 A B C D E
 B E D A C
*/
int N;
string str;
queue<string> q;
map<string, bool> m;

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> str;
		q.push(str);
		m[str] = false;
	}

	int res = 0;
	for(int i=0;i<N;i++) {
		cin >> str;
		while(!q.empty() && m[q.front()]) q.pop();
		
		if(!q.empty()) {
			if (q.front() != str) {
				m[str] = true;
				res++;
			} else {
				q.pop();
			}
		}
	}
	cout << res;
}
