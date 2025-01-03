#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int N;
    string code, voca;
    vector<string> vocas;

    cin >> code;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> voca;
        vocas.push_back(voca);
    }

    for(int i=0;i<27;i++) {
        string tmp = code;
        for(int j=0;j<tmp.length();j++) {
            tmp[j] = 'a' + (tmp[j] - 'a' + i) % 26;
        }

        for(int j=0;j<N;j++) {
            if(tmp.find(vocas[j]) != string::npos) {
                cout << tmp;
                return 0;
            }
        }

    }

    return 0;
}