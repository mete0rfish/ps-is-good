#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, M;

/*
 N=4, M=3
 답: 4
 (4-3)*3 + 1
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N >> M;
        cout << (N-M)*M+1 << endl;
    }
    
    return 0;
}