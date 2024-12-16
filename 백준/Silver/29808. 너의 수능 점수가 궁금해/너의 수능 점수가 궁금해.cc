#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int id;
int pa[4] = {508, 508, 108, 108};
int pb[4] = {212, 305, 212, 305};
vector<pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> id;
    if(id%4763 != 0) {
        cout << 0;
        return 0;
    }
    id /= 4763;

    for(int a=0;a<=200;a++) {
        for(int b=0;b<=200;b++) {
            for(int i=0;i<4;i++) {
                int tmp = a * pa[i] + b* pb[i];
                if(tmp == id)   v.push_back(make_pair(a, b));
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size() <<"\n";
    for(int i=0;i<v.size();i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
