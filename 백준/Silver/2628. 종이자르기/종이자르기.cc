#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int T, a ,b;
vector<int> garo;
vector<int> sero;

int main() {
    cin >> M >> N >> T;
    garo.push_back(0);
    garo.push_back(N);
    sero.push_back(0);
    sero.push_back(M);

    while (T--) {
        cin >> a >> b;
        if (a == 0) {
            garo.push_back(b);
        }
        else {
            sero.push_back(b);
        }
    }    

    sort(garo.begin(), garo.end());
    sort(sero.begin(), sero.end());

    int A = 0, B=0;
    for (int i=1;i<garo.size();i++) {
        A = max(A, garo[i] - garo[i-1]);
    }
    for (int i=1;i<sero.size();i++) {
        B = max(B, sero[i] - sero[i-1]);
    }

    cout << A * B;
}
