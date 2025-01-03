#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

string key, code;
vector<pair<char, int>> v;
int iter[11];
char maps[101][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> key;
    int len = key.length();
    for(int i=0;i<len;i++) {
        v.push_back(make_pair(key[i], i));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) {
        iter[v[i].second] = i;
    }

    cin >> code;
    int len2 = code.length()/len;

    for(int j=0;j<len;j++) {
        for(int i=0;i<len2;i++) {
            maps[i][j] = code[j*len2 + i];
        }
    }

    for(int i=0;i<len2;i++) {
        for(int j=0;j<len;j++) {
            cout << maps[i][iter[j]];
        }
    }

    return 0;
}