#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int N;
int floyd[53][53];
int res;
map<char, set<char>> mp;

bool isSmall(char ch) {
    return ch >= 'a' && ch <= 'z';
}

char toChar(int idx) {
    if (idx < 26) {
        return 'A' + idx;
    } else {
        return 'a' + (idx-26);
    }
}

int main() 
{
    cin >> N;
    cin.ignore();
    
    for (int i=0;i<53;i++) {
        for (int j=0; j<53; j++) {
            floyd[i][j] = 0;
        }
    }
    
    for (int i=0;i<N;i++) {
        string str;
        getline(cin, str);

        int ch1 = isSmall(str[0]) ? str[0] - 'a' + 26 : str[0] - 'A';
        int ch2 = isSmall(str[5]) ? str[5] - 'a' + 26 : str[5] - 'A';
        
        if (ch1 == ch2) continue;

        floyd[ch1][ch2] = 1;
    }
    
    for (int k=0; k<53; k++) {
        for (int i=0;i<53;i++) {
            for (int j=0; j<53; j++) {
                if (i == j) continue;

                if (floyd[i][k] && floyd[k][j]) {
                    floyd[i][j] = 1;
                }
            }
        }
    }
    
    
    for (int i=0;i<53;i++) {
        for (int j=0; j<53;j++) {
            if (floyd[i][j]) {
                res++;
            }
        }
    }
    cout << res << "\n";
    for (int i=0;i<53;i++) {
        for (int j=0; j<53;j++) {
            if (floyd[i][j]) {
                cout << toChar(i) << " => " << toChar(j) << "\n";
            }
        }
    }
    return 0;
}
