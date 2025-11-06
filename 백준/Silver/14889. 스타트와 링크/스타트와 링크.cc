#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>

using namespace std;

int N;
int arr[21][21];
bool vst[21];
int res = 1e9;

void dfs(int cnt, int idx) {
	if(N == cnt*2) {
		int a=0; int b=0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(vst[i] && vst[j]) {
					a+=arr[i][j];
				}
				else if(!vst[i] && !vst[j]) {
					b+=arr[i][j];
				}
			}
		}

		res = min(res, abs(a-b));
		return;
	}
	
	for(int i=idx;i<N;i++) {
		vst[i] = true;
		dfs(cnt+1, i+1);
		vst[i] = false;
	}
}

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << res;
}
