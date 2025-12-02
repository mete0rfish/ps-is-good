#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int H, W;
int res;
// -> : 3 3 3 3 4 2 2 2 
// <- : 3 3 3 3 4 4 4 4
//    : 0 2 1 1 0 1 1 0

int main() {
    
    cin >> H >> W;

    vector<int> arr(W);
    for(int i=0;i<W;i++) {
        cin >> arr[i];
    }

    
    vector<int> left_max(W);
    vector<int> right_max(W);

    left_max[0] = arr[0];
    for(int i=1;i<W;i++) {
        left_max[i] = max(left_max[i-1], arr[i]);
    }

    right_max[W-1] = arr[W-1];
    for(int i=W-2;i>=0;i--) {
        right_max[i] = max(right_max[i+1], arr[i]);
    }

    for(int i=0;i<W;i++) {
        res += min(left_max[i], right_max[i]) - arr[i];
    }

    cout << res;

    return 0;
}
