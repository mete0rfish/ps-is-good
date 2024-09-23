#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

#define ll long long

int n, res;
vector<string> v;
bool chk[51];

int cmp(string a, string b) {
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    res = n;
    for(int i=0;i<n;i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(),cmp);

    for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++) {

            string tmp = v[j].substr(0, v[i].size());
            if(tmp == v[i]) {
                res--;
                break;
            }
        }
    }

    cout << res;

    return 0;
}
