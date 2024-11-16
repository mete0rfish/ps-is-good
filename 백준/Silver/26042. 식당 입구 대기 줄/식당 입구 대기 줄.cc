#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int res_len, res_idx=1e9;

int main() {
    int type, idx;
    int cur = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> type;
        if(type == 1) {
            cin >> idx;
            cur++;
            
            if(cur > res_len) {
                res_len = cur;
                res_idx = idx;
            }
            else if(cur == res_len && res_idx > idx) {
                res_idx = idx;
            }
        }
        else {
            cur--;
        }
    }

    cout << res_len << " " << res_idx;
}