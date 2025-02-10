#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

string str;
char arr[3][3];

bool win_x() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 'X' && (arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
            return true;
    }
    
    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == 'X' && (arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
            return true;
    }

    if (arr[0][0] == 'X' && (arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
        return true;

    if (arr[0][2] == 'X' && (arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
        return true;

    return false;
}

bool win_o() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 'O' && (arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
            return true;
    }

    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == 'O' && (arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
            return true;
    }

    if (arr[0][0] == 'O' && (arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
        return true;

    if (arr[0][2] == 'O' && (arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> str;
        if (str == "end")   break;

        int x_cnt = 0, o_cnt = 0, dot_cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            arr[i / 3][i % 3] = str[i];

            if (str[i] == 'X') x_cnt++;
            else if (str[i] == 'O') o_cnt++;
            else dot_cnt++;
        }

        bool isWinX = win_x();
        bool isWinO = win_o();

        if (isWinX && !isWinO && x_cnt == o_cnt + 1)
            cout << "valid\n";
        else if (!isWinX && isWinO && x_cnt == o_cnt)
            cout << "valid\n";
        else if (!isWinX && !isWinO && x_cnt == 5 && o_cnt == 4)
            cout << "valid\n";
        else
            cout << "invalid\n";
    }
}