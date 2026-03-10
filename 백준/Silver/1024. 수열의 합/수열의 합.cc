#include <iostream>

using namespace std;

long long N, L;

long long func(long long n) {
    return n*(n+1)/2;
}

int main() {
    cin >> N >> L;

    for (int i=L;i<=100;i++) {
        if ((N-func(L-1))/L >= 0 && (N-func(L-1))%L == 0) {

            long long x = (N-func(L-1))/L;
            for (long long j=x;j<(x+L);j++) {
                cout << j << " ";
            }
            return 0;
        }
        L++;
    }

    cout << -1;
    return 0;
}