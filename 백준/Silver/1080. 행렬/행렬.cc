#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n, m;
int maps[51][51];
int total[51][51];

void print() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maps[i][j] << ' ';
        }
        cout << endl;
    }
}


void flip(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            maps[i][j] = (maps[i][j] == 0 ? 1 : 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < str.length(); j++) {
            maps[i][j] = (int)(str[j] - '0');
        }
    }
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < str.length(); j++) {
            total[i][j] = (int)(str[j] - '0');
        }
    }

    int res = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (maps[i][j] != total[i][j]) {
                flip(i, j);
                res++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] != total[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << res;

    return 0;
}
