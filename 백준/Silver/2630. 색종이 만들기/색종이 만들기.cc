#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N;
int arr[129][129];
int wCnt, bCnt;

void func(int x, int y, int n) {
    int tmpCnt = 0;
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            if(arr[i][j]) tmpCnt++;
        }
    }

    if(tmpCnt == n*n) bCnt++;
    else if(tmpCnt == 0) wCnt++;
    else {
        func(x, y, n/2);
        func(x, y+n/2, n/2);
        func(x+n/2, y, n/2);
        func(x+n/2, y+n/2, n/2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    func(0,0,N);
    cout << wCnt << "\n" << bCnt;
}
