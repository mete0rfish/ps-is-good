#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, H, tmp;

int main() {
    cin >> N >> H;
    vector<int> bottom(H+1, 0);
    vector<int> top(H+1, 0);
    for(int i=1;i<=N;i++) {
        cin >> tmp;
        if(i%2 == 0) bottom[tmp]++;
        else top[tmp]++;
    }

    for(int i=H-1;i>=1;i--) {
        bottom[i] += bottom[i+1];
    }

    // for(int i=1;i<=H;i++) {
    //     cout << bottom[i] << ' ';
    // }
    // cout << endl;

    int cnt = 1;
    int mini = 99999999;
    for(int i= H-1;i>=1;i--) {
        top[i] += top[i+1];
    }

    for(int i=1;i<=H;i++) {
        tmp = top[H-i+1] + bottom[i];
        if(tmp < mini) {
            mini = tmp;
            cnt = 1;
        }
        else if(tmp == mini) cnt++;
    }

    cout << mini << ' ' << cnt;

    // cout << mini << ' ' << cnt;

    return 0;
}