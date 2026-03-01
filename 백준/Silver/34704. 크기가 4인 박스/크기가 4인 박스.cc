#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int tmp, res;
int cnt[5];
vector<int> v;

int main() 
{
    cin >> N;

    for (int i=0; i<N;i++) {
        cin >> tmp;
        cnt[tmp]++;
    }

    res += cnt[4];

    res += cnt[3];
    if (cnt[1] >= cnt[3]) {
        cnt[1] -= cnt[3];
    } else {
        cnt[1] = 0;
    }

    res += cnt[2]/2;
    cnt[2] %= 2;
    if(cnt[2] == 1) {
        res++;
        if(cnt[1] >= 2) {
            cnt[1] -= 2;
        } else {
            cnt[1] = 0;
        }
    }

    if (cnt[1] > 0) {
        // 남은 1 처리 - 4개씩 묶기
        res += (cnt[1] + 3) / 4;
    }

    cout << res;
    return 0;
}