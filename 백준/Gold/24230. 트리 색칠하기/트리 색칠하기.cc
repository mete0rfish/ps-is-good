#include <iostream>
#include <vector>

using namespace std;

int N;
int tmp, a, b, res;
int color[200001];
vector<int> edge[200001];
bool vst[200001];

void dfs(int x) {
    for(int i=0;i<edge[x].size();i++) {
        int y = edge[x][i];

        if(vst[y]) continue;

        if(color[x] != color[y]) {
            // cout << x << " vs. " << y << endl;
            // cout << color[x] << ", " << color[y] << endl << endl;
            res++;
        }
        
        vst[y] = true;
        dfs(y);
    }
}

int main() {
    cin >> N;

    for(int i=1;i<=N;i++) {
        cin >> color[i];
    }
    for(int i=0;i<N-1;i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vst[1] = true;
    if(color[1] != 0) res = 1;
    dfs(1);

    cout << res;
    return 0;
}