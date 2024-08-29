#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

#define MAX 1000001
#define ll long long
using namespace std;

int n;
vector<int> player;
int score[MAX];
bool chk[MAX];

/*
 * 소수이면 패스
 * 소수가 아니면 다른 수들로 나누어본다.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        player.push_back(tmp);
        chk[tmp] = true;
    }

    for(int i=0;i<player.size();i++) {
        for(int j = player[i]*2; j<MAX;j+=player[i]) {
            if(chk[j]) {
                score[player[i]]++;
                score[j]--;
            }
        }
    }

    for(int i=0;i<n;i++) {
        cout << score[player[i]] << ' ';
    }

    return 0;
}
