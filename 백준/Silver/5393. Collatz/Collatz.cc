#include <iostream>

using namespace std;

long long T, N;

long long count_odd(long long x) {
    if (x <= 0) return 0;
    return (x + 1) / 2;
}

long long count_even(long long x) {
    if (x <= 0) return 0;
    return x / 2;
}

void solve() {
    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    long long even_cut = count_even(2 * N) - count_even(N);
    long long tmp = (N - 1) / 3;
    long long odd_cut = count_odd(N) - count_odd(tmp);

    cout << even_cut + odd_cut << "\n";
}
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
       
        solve();
    }
    return 0;
}