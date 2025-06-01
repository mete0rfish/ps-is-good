#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int N;
string str;
map<string, int> m;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> str;
        str.erase(0, str.find('.') + 1);
        m[str]++;
        v.push_back(str);
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for(int i=0;i< v.size();i++) {
        cout << v[i] << ' ' << m[v[i]] << "\n";
    }
    
    return 0;
}

// -10 -9 2 4 4

