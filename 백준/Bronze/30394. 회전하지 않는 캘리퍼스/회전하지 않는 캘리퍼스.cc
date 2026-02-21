#include <iostream>
#include <algorithm>

using namespace std;

int N, x, y;

int main() 
{
    cin >> N;
    int mx = -1e9, mn = 1e9;

    for (int i=0;i<N;i++) {
        cin >> x >> y;
        mx = max(mx, y);
        mn = min(mn, y);
    }

    cout << mx - mn;

    return 0;
}