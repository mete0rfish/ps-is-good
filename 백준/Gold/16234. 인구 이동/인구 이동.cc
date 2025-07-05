#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;
int arr[51][51];
bool vst[51][51];
vector<pair<int,int>> v;
int sum;
int px[4] = {1,0,-1,0};
int py[4] = {0,1,0,-1};

void dfs(int x, int y) {
    for(int i=0;i<4;i++) {
        int nx = px[i] + x;
        int ny = py[i] + y;

        if(nx < 0 || ny <0 || nx >=N || ny >=N) continue;
        if(vst[nx][ny]) continue;
        int gap = abs(arr[x][y] - arr[nx][ny]);
        if(gap < L || gap > R) continue;

        vst[nx][ny] = true;
        sum += arr[nx][ny];
        v.push_back(make_pair(nx, ny));
        dfs(nx, ny);
    }
}

void solve() {
    int day = 0;
    while(true) {
        bool flag = false;
        fill(&vst[0][0], &vst[0][0] + 51 * 51, false);
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(!vst[i][j]) {
                    v.clear();
                    sum = arr[i][j];
                    vst[i][j] = true;
                    v.push_back(make_pair(i, j));
                    dfs(i, j);
                    if(v.size() == 1) continue;
    
                    int avg = sum / v.size();
                    for(int i=0;i<v.size();i++) {
                        arr[v[i].first][v[i].second] = avg;
                        flag = true;
                    }
                }
            }
        }

        if(!flag) break;
        day++;
    }
    cout << day;
}

int main() {

    cin >> N >> L >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    solve();
    
    return 0;
}