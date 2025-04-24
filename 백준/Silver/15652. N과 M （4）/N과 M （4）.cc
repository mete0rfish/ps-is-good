#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, M;
int output[9];
bool vst[9];

void func(int len, int idx) {
    if(len == M) {
        for(int i=0;i<M;i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=idx;i<=N;i++) {

        vst[i] = true;
        output[len] = i;
        func(len + 1, i);
        vst[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    func(0, 1);
}
