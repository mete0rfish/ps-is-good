#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n;
deque<int> dq;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    int tmp = 1;
    for(int i=n-1;i>=0;i--) {
        if(v[i] == 1) {
            dq.push_back(tmp);
        }
        else if(v[i] == 2) {
            int a = dq.back();  dq.pop_back();
            dq.push_back(tmp);
            dq.push_back(a);
        }
        else {
            dq.push_front(tmp);
        }
        tmp++;
    }

    while(!dq.empty()) {
        cout << dq.back() << ' ';
        dq.pop_back();
    }

    return 0;
}
