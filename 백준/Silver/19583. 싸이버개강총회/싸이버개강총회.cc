#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int res;
string S, E, Q;
map<string, bool> m;

pair<int, int> stringToInt(string target) {
    string t_h = target.substr(0, 2);
    string t_m = target.substr(3, 2);
    return make_pair(stoi(t_h), stoi(t_m));
}

bool isTargetEarlierAndEqual(string target, string crit) {
    pair<int, int> t_t = stringToInt(target); 
    pair<int, int> c_t = stringToInt(crit); 

    if(t_t.first== c_t.first) {
        return t_t.second <= c_t.second;
    }
    return t_t.first < c_t.first;
}

bool isTargetLaterAndEqual(string target, string crit) {
    pair<int, int> t_t = stringToInt(target); 
    pair<int, int> c_t = stringToInt(crit); 

    if(t_t.first== c_t.first) {
        return t_t.second >= c_t.second;
    }
    return t_t.first > c_t.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string logTime, name;
    cin >> S >> E >> Q;
    while(1) {
        cin >> logTime >> name;
        if(cin.eof())   break;

        if(isTargetEarlierAndEqual(logTime, S)) {
            m[name] = true;
        }
        if(isTargetLaterAndEqual(logTime, E) && isTargetEarlierAndEqual(logTime, Q)) {
            if(m[name] == true) {
                m[name] = false;
                res++;
            }
        }
    }

    cout << res;

    return 0;
}
