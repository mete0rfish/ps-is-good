#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;

string str;

int main() {
	int idx = 1;
	while(1) {
		cin >> str;
		if (str.find("-") != string::npos) break;

		stack<char> s;
		for (int i=0;i<str.length();i++) {
			if (!s.empty()) {
				if (s.top() == '{' && str[i] == '}') {
					s.pop();
				} else {
					s.push(str[i]);
				}
			} else {
				s.push(str[i]);
			}
		}

		int res = 0;

		while(!s.empty()) {
			char a = s.top(); s.pop();
			if (!s.empty()) {
				char b = s.top(); s.pop();

				// b=={ 바꾸기
				if(a == b) {
					res++;
				} else {
					res+=2;
				}
			} else {
				res++;
			}
		}
		cout << idx << ". " << res << "\n";
		idx++;
	}
}
