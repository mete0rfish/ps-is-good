#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;



int main() 
{
    int T;
    cin >> T;

    while (T--) {
        string str;
        int k;
        cin >> str;
        cin >> k;
        
        vector<int> pos[26];
        for (int i=0;i<str.length();i++) {
            int idx = str[i] - 'a';
            pos[idx].push_back(i);
        }

        int a_len=1e9, b_len =0;
        for (int i=0;i<26;i++) {
            for (int j=0; j+k-1<pos[i].size(); j++) {
                int len = pos[i][j+k-1] - pos[i][j] + 1;

                a_len = min(a_len, len);
                b_len = max(b_len, len);
            }
        }

        if (a_len == 1e9 || b_len == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << a_len << " " << b_len << "\n";
        }
    }

    return 0;
}

