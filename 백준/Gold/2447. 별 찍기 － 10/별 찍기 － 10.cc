#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

char v[2188][2188] = {' '};

void draw(int n, int x, int y) {
    if (n == 1) {
        v[x][y] = '*';
        return;
    }

    int size = n/3;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (i == 1 && j == 1) continue;

            draw(size, x + (i*size), y + (j*size));
        }
    }
}

int main() 
{
    int n;
    cin >> n;

    memset(v, ' ', sizeof(v));

    draw(n, 0, 0);
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}

