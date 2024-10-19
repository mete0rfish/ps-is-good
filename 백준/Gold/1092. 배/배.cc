#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
int res;
vector<int> crain;
vector<int> container;

void func() {
    if (crain[0] < container[0]) {
        cout << -1;
        return;
    }

    int days = 0;

    while(!container.empty()) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<container.size();j++) {
                if(crain[i] >= container[j]) {
                    container.erase(container.begin() + j);
                    break;
                }
            }
        }
        days++;
    }

    cout << days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        crain.push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        container.push_back(tmp);
    }

    sort(crain.begin(), crain.end(), greater<int>());
    sort(container.begin(), container.end(), greater<int>());

    func();

    return 0;
}

/*
    괜히 어렵게 생각함
    어차피 전체가 100 * 10000 밖에 되지 않기 때문에, 2초 충분히 가능하므로
    visited 체크만 해주면 충분히 시간내에 가능
*/