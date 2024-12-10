#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define MAX 4

int N,M,K;
char maps[11][11];
map<string, int> res;
int px[8] = {-1,0,1,0, -1,1, -1,1}; //{-1,-1,-1,0,0,1,1,1};
int py[8] = {0,-1,0,1, 1,-1, -1,1}; //{-1,0,1,-1,1,-1,0,1};

void dfs(int x, int y, int cnt, string str) {
    if(cnt == 5)  return;

    res[str]++;
    for(int i=0;i<8;i++) {
        int nx = px[i] + x;
        int ny = py[i] + y;

        if(nx < 0)  nx = N-1;
        if(ny < 0)  ny = M-1;
        if(nx >= N)  nx = 0;
        if(ny >= M)  ny = 0;

        dfs(nx, ny ,cnt+1, str+maps[nx][ny]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        string tmp; cin >> tmp;
        for(int j=0;j<M;j++) {
            maps[i][j] = tmp[j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            string tmp = "";
            dfs(i,j,0,tmp+maps[i][j]);
        }
    }

    string que;
    while(K--) {
        cin >> que;
        cout << res[que] << "\n";
    }

    return 0;
}
