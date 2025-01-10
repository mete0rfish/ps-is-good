#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, M;
int tmp;
int p[202];

int find(int x) {
    if (p[x] == x)   return x;
    return p[x] = find(p[x]);
}

void union_nodes(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y) p[y] = x;
    else p[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            if (tmp == 1) {
                union_nodes(i, j);
            }
        }
    }

    int top;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            top = find(x);
        }
        else {
            if (find(top) != find(x)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}