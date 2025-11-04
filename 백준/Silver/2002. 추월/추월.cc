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
int res;
vector<int> v;
map<string, int> m;

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> str;
		m[str] = i;
	}

	int res = 0;
	for(int i=0;i<N;i++) {
		cin >> str;
		v.push_back(m[str]);
	}

	for(int i=0;i<N-1;i++) {
		for(int j=i+1;j<N;j++) {
			if(v[i] > v[j]) {
                res++;
                break;
            }
		}
	}
	
	cout << res;
}
