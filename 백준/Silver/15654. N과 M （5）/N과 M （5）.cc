#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, M;
int input[9];
int output[9];
bool vst[9];

void func(int len) {
    if(len == M) {
        for(int i=0;i<M;i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<N;i++) {
        if(vst[i])  continue;

        vst[i] = true;
        output[len] = input[i];
        func(len + 1);
        vst[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> input[i];
    }

    sort(input, input+N);
    func(0);
}
