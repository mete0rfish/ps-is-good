#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

#define ll long long
using namespace std;

char tmp[10][10];
int arr[10][10];
vector<pair<int, int> > blank;

bool vertical_check(int y, int value) {
    for (int i = 0; i < 9; i++) {
        if (arr[i][y] == value) {
            return false;
        }
    }
    return true;
}

bool horizonal_check(int x, int value) {
    for (int i = 0; i < 9; i++) {
        if (arr[x][i] == value) {
            return false;
        }
    }
    return true;
}

bool cube_check(int x, int y, int value) {
    int sx = x / 3 * 3;
    int sy = y / 3 * 3;

    for (int i = sx; i < sx + 3; i++) {
        for (int j = sy; j < sy + 3; j++) {
            if (arr[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

void func(int blank_idx) {
    if (blank_idx == blank.size()) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }
        exit(0);
    }

    for (int i = 1; i < 10; i++) {
        int x = blank[blank_idx].first;
        int y = blank[blank_idx].second;
        // cout << "idx: " << blank_idx<< endl;
        // cout << "x, y: " << x << ", " << y << endl << endl;

        if (
            vertical_check(y, i) &&
            horizonal_check(x, i) &&
            cube_check(x,y,i)
        ) {

            arr[x][y] = i;
            func(blank_idx + 1);
            arr[x][y] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> tmp[i][j];
            arr[i][j] = (int)(tmp[i][j] - '0');
            if (arr[i][j] == 0) {
                blank.push_back({i, j});
            }
        }
    }

    func(0);

    return 0;
}
