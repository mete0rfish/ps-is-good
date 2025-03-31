#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, R, C;
int cnt;

void func(int x, int y, int n) {

    if(x==C && y==R) {
        cout << cnt;
        return;
    }

    if(C >= x && C < x + n && R >= y && R < y+n) {
        func(x, y, n/2);
        func(x, y+n/2, n/2);
        func(x+n/2, y, n/2);
        func(x+n/2, y+n/2, n/2);
    }
    else {
        cnt += (n*n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> C >> R;

    func(0, 0, pow(2,N));
}
