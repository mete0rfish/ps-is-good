#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, K;

vector<string> words;
bool vst[26];
int res = 0;

void isBigger(int A) {
    res = (A > res ? A : res);
}

int read() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        bool isRead = true;
        string word = words[i];

        for (int j=0;j<word.length();j++) {
            if (!vst[word[j] - 'a']) {
                isRead = false;
                break;
            }
        }

        if (isRead) {
            cnt++;
        }
    }

    return cnt;
}

void choose(int idx, int cnt) {
    if (cnt == K) {
        int readable = read();
        isBigger(readable);
        return;
    }

    for (int i=idx;i<26;i++) {
        if (vst[i]) continue;

        vst[i] = true;
        choose(i+1, cnt+1);
        vst[i] = false;
    }
}

int main() {
    
    cin >>N>>K;

    if (K < 5) {
        cout << 0;
        return 0;
    }

    string str;
    for(int i=0;i<N;i++) {
        cin >> str;
        words.push_back(str);
    }

    vst['a' - 'a'] = true;
    vst['n' - 'a'] = true;
    vst['t' - 'a'] = true;
    vst['i' - 'a'] = true;
    vst['c' - 'a'] = true;

    choose(0, 5);

    cout << res;

    return 0;
}
