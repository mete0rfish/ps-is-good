#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

map<string, double> m;
vector<string> v;

int main() {
	string str;
	double total = 0;
	while(getline(cin, str)) {
		total++;
		m[str]++;
	}	
    cout << fixed;
	cout.precision(4);
	for(auto iter = m.begin() ; iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second/total*100 << "\n";
	}
}
