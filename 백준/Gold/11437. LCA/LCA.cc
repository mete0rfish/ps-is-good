#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int N, M;
int dept[50001];
int parent[50001];
vector<int> edge[50001];
bool vst[50001];

void dfs(int x, int depth) {
    dept[x] = depth;
    vst[x] = true;
    for(int y : edge[x]) {
        if(!vst[y]) {
            parent[y] = x;
            dfs(y, depth+1);
        }
    }
}

void func(int a, int b) {
    while(dept[a] != dept[b]) {
        if(dept[a] > dept[b]) {
            a = parent[a];
        }
        else {
            b = parent[b];
        }
    }

    while(a != b) {
        a = parent[a];
        b = parent[b];
    }

    cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0;i<N-1;i++) {
        int a, b;
        cin >> a>> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);

    cin >> M;
    for(int i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        func(a, b);
    }


    return 0;
}
