#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> X;

    int res = 0;
    for(int i=0;i<7;i++) {
        if(X & (1 << i)) res++;
    }

    cout << res;
    
    return 0;
}