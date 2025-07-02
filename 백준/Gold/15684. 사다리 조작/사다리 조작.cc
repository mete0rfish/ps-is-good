#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, H;
bool arr[31][11];
int res = 99999999;

bool isCorrect() {
    for(int i=1;i<=N;i++) {
        int y = i;
        for(int x=1;x<=H;x++) {
            if(arr[x][y]) y++;
            else if(arr[x][y-1]) y--;
        }
        if(i != y) {
            return false;
        }
    }   
    return true;
}

void solve(int maxCnt, int cnt, int idx) {
    if(cnt == maxCnt) {
        if(isCorrect()) {
            res = min(res, cnt);
        }
        return;
    }
    
    for(int y=idx;y<=N;y++) {
        for(int x=1;x<=H;x++) {
            if(arr[x][y-1] || arr[x][y] || arr[x][y+1]) continue;
            arr[x][y] = true;
            solve(maxCnt, cnt + 1, y);
            arr[x][y] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> H;

    int a, b;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        arr[a][b] = true;
    }

    for(int i =0; i<4;i++) {
        solve(i, 0, 1);
    }

    if(res == 99999999) cout << -1;
    else cout << res;
    
    return 0;
}