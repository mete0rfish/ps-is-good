#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, res;
vector<string> arr;
bool vst[21][21];
bool used[27];

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

void dfs(int x, int y, int depth) {
    res = max(depth, res);

    for (int i=0;i<4;i++) {
        int nx = x + px[i];
        int ny = y + py[i];

        if (nx < 0 || ny <0|| nx>=N || ny>=M) continue;
        if (vst[nx][ny]) continue;
        if (used[arr[nx][ny] - 'A']) continue;

        used[arr[nx][ny] - 'A'] = true;
        vst[nx][ny] = true;
        dfs(nx, ny,depth+1);
        vst[nx][ny] = false;
        used[arr[nx][ny] - 'A'] = false;
    }
}

int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        string str;
        cin >> str;
        arr.push_back(str);
    }

    vst[0][0] = true;
    used[arr[0][0] - 'A'] = true;
    dfs(0,0, 1);

    cout<< res;
}
