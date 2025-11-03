#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

string str;

bool isValid(int l, int r) {
	while(l <= r) {
		if(str[l] != str[r]) return false;

		l++;
		r--;
	}
	return true;
}

int main() {
	cin >> str;
	for (int i=0;i<str.length();i++) {
		if (isValid(i, str.length()-1)) {
			cout << str.length() + i;
			return 0;
		}
	}
}
