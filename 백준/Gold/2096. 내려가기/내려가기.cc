#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a, b, c;
int tmp[4];
int maxDp[4], minDp[4];

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> a >> b >> c;
        if(i == 0) {
            maxDp[0] = a;
            maxDp[1] = b;
            maxDp[2] = c;
            minDp[0] = a;
            minDp[1] = b;
            minDp[2] = c;
        }
        else {
            tmp[0] = max(maxDp[0], maxDp[1]) + a;
            tmp[1] = max(maxDp[0], max(maxDp[1], maxDp[2])) + b;
            tmp[2] = max(maxDp[1], maxDp[2]) + c;
            for(int i=0;i<3;i++) maxDp[i] = tmp[i];

            tmp[0] = min(minDp[0], minDp[1]) + a;
            tmp[1] = min(minDp[0], min(minDp[1], minDp[2])) + b;
            tmp[2] = min(minDp[1], minDp[2]) + c;
            for(int i=0;i<3;i++) minDp[i] = tmp[i];
        }
    }

    cout << *max_element(maxDp, maxDp+3) << ' ' << *min_element(minDp, minDp+3);
    
    return 0;
}