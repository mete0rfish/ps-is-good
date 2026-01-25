#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

// 빈도
// 빈도가 같으면 
int N,M;
vector<pair<int, string>> v;
map<string, int> m;

bool cmp(pair<int, string>& a, pair<int, string>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }

    if (a.second.length() != b.second.length()) {
        return a.second.length() > b.second.length();
    }

    return a.second < b.second;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i=0;i<N;i++) {
        string str;
        cin >> str;
        if (str.length() < M) continue;

        m[str]++;
    }

    for (auto& iter : m) {
        v.push_back({iter.second, iter.first});
    }

    sort(v.begin(), v.end(), cmp);
    
    for (int i=0;i<v.size();i++) {
        cout << v[i].second << "\n";
    }
    
    return 0;
}
