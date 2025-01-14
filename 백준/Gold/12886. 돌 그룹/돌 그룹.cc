#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

bool flag;
int A, B, C;
bool visited[1501][1501];

void dfs(int a, int b, int c) {
    if (a == b && b == c) {
        flag = true;
        return;
    }

    if (a > b) {
        int na = a - b;
        int nb = b + b;
        if (na <= 1000 && nb <= 1000 && na >= 0 && nb >= 0) {
            if (!visited[na][nb] && !visited[nb][na]) {
                visited[na][nb] = true;
                dfs(na, nb, c);
            }
        }
    } else {
        int na = a + a;
        int nb = b - a;
        if (na <= 1000 && nb <= 1000 && na >= 0 && nb >= 0) {
            if (!visited[na][nb] && !visited[nb][na]) {
                visited[na][nb] = true;
                dfs(na, nb, c);
            }
        }
    }
    if (a > c) {
        int na = a - c;
        int nc = c + c;
        if (na <= 1000 && nc <= 1000 && na >= 0 && nc >= 0) {
            if (!visited[na][nc] && !visited[nc][na]) {
                visited[na][nc] = true;
                dfs(na, b, nc);
            }
        }
    } else {
        int na = a + a;
        int nc = c - a;
        if (na <= 1000 && nc <= 1000 && na >= 0 && nc >= 0) {
            if (!visited[na][nc] && !visited[nc][na]) {
                visited[na][nc] = true;
                dfs(na, b, nc);
            }
        }
    }
    if (b > c) {
        int nb = b - c;
        int nc = c + c;
        if (nb <= 1000 && nc <= 1000 && nb >= 0 && nc >= 0) {
            if (!visited[nb][nc] && !visited[nc][nb]) {
                visited[nb][nc] = true;
                dfs(a, nb, nc);
            }
        }
    } else {
        int nb = b + b;
        int nc = c - b;
        if (nb <= 1000 && nc <= 1000 && nb >= 0 && nc >= 0) {
            if (!visited[nb][nc] && !visited[nc][nb]) {
                visited[nb][nc] = true;
                dfs(a, nb, nc);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >> C;
    if ((A + B + C) % 3 != 0) {
        cout << 0;
        return 0;
    }
    dfs(A, B, C);
    if (flag) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
