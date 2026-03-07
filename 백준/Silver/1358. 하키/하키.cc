#include <iostream>

using namespace std;

int W, H, X, Y, P;
int cnt = 0;

int main() {
    cin >> W >> H >> X >> Y >> P;

    while (P--) {
        int x, y;
        cin >> x >> y;
        // 정사각형
        if (X <= x && x <= X+W && Y <= y && y <= Y+H) {
            cnt++;
            continue;
        }
        
        //반원
        // 왼쪽
        int lx = X;
        int ly = Y+(H/2);
        int r = (H/2);
        if ((x - lx)*(x - lx) + (y - ly)*(y - ly) <= r*r) {
            cnt++;
            continue;
        }

        // 오른쪽
        int rx = X+W;
        int ry = Y+(H/2);
        if ((x - rx)*(x - rx) + (y - ry)*(y - ry) <= r*r) {
            cnt++;
            continue;
        }
    }
    cout << cnt;
    
    return 0;
}