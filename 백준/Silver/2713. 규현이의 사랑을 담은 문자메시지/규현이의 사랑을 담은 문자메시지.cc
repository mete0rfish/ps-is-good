#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool vst[22][22];
int px[4] = {0, 1, 0, -1};
int py[4] = {1, 0, -1, 0};

string to_binary(char ch) {
    string binary = "";
    if (ch != ' ') {
        int ten = (int)(ch - 'A' + 1);

        while (ten > 0) {
            ten % 2 == 0 ? binary += "0" : binary += "1";
            ten /= 2;
        }
    }

    for(int i=binary.length();i<5;i++) {
        binary += "0";
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

void solution(int R, int C, string str) {
    vector<vector<int>> v(R, vector<int>(C, 0));
    memset(vst, false, sizeof(vst));

    string all_binary = "";
    for (char ch : str) {
        string binary = to_binary(ch);
        all_binary += binary;
    }

    int idx = 0, dir = 0;
    int all_binary_len = all_binary.length();
    int x = 0, y= 0;

    for (int i=0;i<R*C;i++) {
        if (idx < all_binary_len) {
            v[x][y] = all_binary[idx] - '0';
            idx++;
        }
        vst[x][y] = true;

        if (i == R*C-1) break;

        int nx = x + px[dir];
        int ny = y + py[dir];

        if (nx < 0 || ny < 0 || nx >= R || ny >= C || vst[nx][ny]) {
            dir = (dir + 1) % 4;
            nx = x + px[dir];
            ny = y + py[dir];
        } 
        x = nx;
        y = ny;
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cout << v[i][j];
        }
    }
    cout << "\n";
}

int main() {
    int T, R, C;
    
    cin >> T;
    while(T--) {
        cin >> R >> C;
        cin.ignore();

        string str;
        getline(cin, str);
        solution(R, C, str);
    }

    return 0;
}
