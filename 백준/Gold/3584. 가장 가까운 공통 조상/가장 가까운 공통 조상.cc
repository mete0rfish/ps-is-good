#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int T, N;
vector<int> e[10001];
bool vst[10001];
int d[10001];
int p[10001];

void init() {
    for(int i=1;i<=N;i++) {
        p[i] = i;
        vst[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while(T--) {
        int a, b;
        cin >> N;
        init();

        for(int i=0;i<N-1;i++) {
            cin >> a >> b;
            p[b] = a;
        }
        cin >> a >> b;
        vst[a] = true;
        while(a != p[a]) {
            
            a = p[a];
            vst[a] = true;
        }
        while(!vst[b]) {
            b = p[b];
        }
        cout << b << "\n";
    }
}
