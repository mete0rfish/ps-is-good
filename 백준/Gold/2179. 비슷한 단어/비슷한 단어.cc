#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> strs;
vector<string> res;
map<string, int> m; 
map<string, int> m_idx;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second >= 2 && b.second < 2) return true;
    if (a.second < 2 && b.second >= 2) return false;

    if (a.second >= 2 && b.second >= 2) {
        if (a.first.length() != b.first.length()) 
            return a.first.length() > b.first.length();
        return m_idx[a.first] < m_idx[b.first];
    }

    return a.first.length() > b.first.length();
} 

int main() 
{
    cin >> N;
    for (int i=0;i<N;i++) {
        string str;
        cin >> str;
        strs.push_back(str);

        for(int j=0;j<str.length();j++) {
            string sub_str = str.substr(0, j+1);
            m[sub_str]++;

            if (m_idx.find(sub_str) == m_idx.end()) {
                m_idx[sub_str] = i;
            }
        }
    }

    vector<pair<string, int>> vec(m.begin(), m.end());
    
    sort(vec.begin(), vec.end(),cmp);

    if (vec[0].second == 1) {
        cout << strs[0] << "\n" << strs[1] << endl;
        return 0;
    }

    string target = vec[0].first;

    // for (auto v : vec) {
    //     cout << v.first << " : " << v.second << endl;
    // }


    for(auto str : strs) {
        if (res.size() == 2) break;

        string sub_str = str.substr(0,target.length());
        if (sub_str == target) {
            res.push_back(str);
        }
    }

    for(auto r : res) {
        cout << r << "\n";
    }
}
