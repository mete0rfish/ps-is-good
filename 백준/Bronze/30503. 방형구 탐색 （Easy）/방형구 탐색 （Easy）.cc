#include <iostream>

using namespace std;

int N, Q;
long long arr[1001];

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];

    cin >> Q;
    while (Q--) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            int cnt = 0;
            for (int i=l-1;i<r;i++) {
                if (arr[i] == k) cnt++;
            }
            cout << cnt << "\n";
        }
        else {
            int l, r;
            cin >> l >> r;
            for (int i=l-1;i<r;i++) {
                arr[i] = 0;
            }
        }
    }
    
    return 0;
}