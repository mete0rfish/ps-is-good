#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int T, N;
int tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while(T--) {
        vector<int> v;
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> tmp;
            v.push_back(tmp);
        }

        int large = -1;
        long sum = 0;
        for(int i=N-1;i>=0;i--) {
            if(large < v[i]) {
                large = v[i];
            }
            else {
                sum += (large - v[i]);
            }
        }
        cout << sum << "\n";
    }

}
