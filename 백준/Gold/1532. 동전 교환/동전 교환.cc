#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

// 금화 부족: 은화 -> 금화, 은화 부족: 동화 -> 은화
// 은화 부족: 동화 -> 은화
// 동화 부족: 은화 -> 동화


long long solution(vector<long long>& provided, vector<long long>& required) {
    long long cnt = 0;

    while(provided[0] < required[0]) {
        if (provided[1] >= 11) {
            provided[0] ++;
            provided[1] -= 11;
            cnt++;
        } else if (provided[2] >= 11) {
            provided[1] ++;
            provided[2] -= 11;
            cnt++;
        } else {
            break;
        }
    }

    while (provided[1] < required[1]) {
        if (provided[0] > required[0]) {
            provided[0] --;
            provided[1] += 9;
            cnt++;
        } else if (provided[2] >= 11) {
            provided[1] ++;
            provided[2] -= 11;
            cnt++;
        } else {
            break;
        }
    }

    while (provided[2] < required[2]) {
        if (provided[1] > required[1]) {
            provided[1] --;
            provided[2] += 9;
            cnt++;
        } else if (provided[0] > required[0]) {
            provided[0] --;
            provided[1] += 9;
            cnt++;
        } else {
            break;
        }
    }

    for (int i=0;i<3;i++) {
        if (provided[i] < required[i]) return -1;
    }
    return cnt;
}

int main() {
    vector<long long> provided, required;
    long long G1, S1, B1, G2, S2, B2;
    cin >> G1 >> S1 >> B1 >> G2 >> S2 >> B2;
    provided.push_back(G1);
    provided.push_back(S1);
    provided.push_back(B1);
    required.push_back(G2);
    required.push_back(S2);
    required.push_back(B2);

    cout << solution(provided, required);

    return 0;
}
