#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, A, B;
int cnt = 0;
int res;
int sons[101];
vector<int> v;

bool isOdd(int x) {
    return x%2==1;
}

bool isValidRange(int x) {
    return A <= x && x <= B;
}

int main() {
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> sons[i];
    }

    cin >> A >> B;

    sort(sons, sons + N);

    isOdd(A) ? v.push_back(A) : v.push_back(A+1);
    isOdd(B) ? v.push_back(B) : v.push_back(B-1);

    for(int i=1;i<N;i++) {
        int mid = (sons[i] + sons[i-1]) / 2;

        if(isOdd(mid) && isValidRange(mid)) {
            v.push_back(mid);
        }
        else if(!isOdd(mid)) {
            if(isValidRange(mid - 1)) {
                v.push_back(mid-1);
            }
            if(isValidRange(mid + 1)) {
                v.push_back(mid+1);
            }
        }
    }

    for(int i=0;i<v.size();i++) {
        int mini = 1e9;
        int cur = v[i];
        for(int j=0;j<N;j++) {
            mini = min(mini, abs(cur - sons[j]));
        }

        if(cnt < mini) {
                cnt = mini;
                res = v[i];
        }
    }

    cout << res;
    return 0;
}