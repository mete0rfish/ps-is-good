#include <iostream>
#include <cmath>

using namespace std;

int N, M;
long Ps[2000001][2];
long Qs[2000001][2];

int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) cin >> Ps[i][0] >> Ps[i][1];
    for (int i=0;i<M;i++) cin >> Qs[i][0] >> Qs[i][1];

    long res = 0;
    for (int i=0;i<M;i++) {
        long Qx = Qs[i][0];
        long Qy = Qs[i][1];

        for (int i=0;i<N;i++) {
            long Px = Ps[i][0];
            long Py = Ps[i][1];

            long dist = (Qx-Px)*(Qx-Px) + (Qy-Py)*(Qy-Py);
            res = max(res, dist);
        }
    }

    cout << res;
    
    return 0;
}