#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, K;

vector<int> word_masks;
bool vst[26];
int res = 0;

void solution(int idx, int cnt, int mask) {
    if (cnt == K) {
        int cnt = 0;
        for (auto word : word_masks) {
            if ((word & mask) == word) {
                cnt++;
            }
        }
        res = max(res, cnt);
        return;
    }

    for (int i=idx; i<26; i++) {
        if ((mask & (1 << i)) != 0) continue;

        solution(i+1, cnt+1, mask | (1 << i));
    }
}

int main() {
    
    cin >>N>>K;

    if (K < 5) {
        cout << 0;
        return 0;
    }

    if (K == 26) {
        cout << N;
        return 0;
    }

    string str;
    for(int i=0;i<N;i++) {
        cin >> str;

        int mask = 0;
        for (char c: str) {
            mask = mask | (1<< (c-'a'));
        }
        word_masks.push_back(mask);
    }

    int default_mask = 0;

    default_mask |= (1 << ('a' - 'a'));
    default_mask |= (1 << ('n' - 'a'));
    default_mask |= (1 << ('t' - 'a'));
    default_mask |= (1 << ('i' - 'a'));
    default_mask |= (1 << ('c' - 'a'));

    solution(0, 5, default_mask);

    cout << res;

    return 0;
}
