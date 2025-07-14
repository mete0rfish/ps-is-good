#include <iostream>

using namespace std;

int N, M;

int main() {
    cin >> N;
    N = (~N+1) ^ N;
    int cnt = 0;
    for(int i=0;i<32;i++) {
        if((N >> i) & 1) cnt++;
    }
    cout << cnt;
    
    return 0;
}