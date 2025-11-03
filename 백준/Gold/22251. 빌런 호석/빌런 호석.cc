#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

int N, K, P, X;
int res;
int cnts[11][8] = {
	{1,1,1,0,1,1,1}, {0,0,1,0,0,1,0}, {1,0,1,1,1,0,1}, {1,0,1,1,0,1,1}, {0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1}, {1,1,0,1,1,1,1}, {1,0,1,0,0,1,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}
};
int arr[10][10]; // 반전 개수

void init() {
	for(int i=0;i<9;i++) {
		for(int j=i+1;j<10;j++) {
			int cnt = 0;
			for(int idx = 0;idx<7;idx++) {
				if(cnts[i][idx] != cnts[j][idx]) cnt++;
			}
			arr[i][j] = cnt;
			arr[j][i] = cnt;
		}
	}
}

int main() {
	cin >> N >> K >> P >> X;
	init();
	
	// 0 패딩
	string str = to_string(X);
	while(K > str.length()) {
		str = "0" + str;
	} 
	
	// 계산
	for(int t=1;t<=N;t++) {
		if(X == t) continue;

		string t_str = to_string(t);
		while(K>t_str.length()) {
			t_str = "0" + t_str;
		} 

		int total_cnt = 0;
		for (int j=0;j<K;j++) {
			int a = str[j] - '0';
			int b = t_str[j] - '0';

			total_cnt += arr[a][b];
		}

		if(1 <= total_cnt && total_cnt <= P) {
			res++;
		}
	}
	cout << res;
}