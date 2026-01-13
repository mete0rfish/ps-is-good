#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int kbs1_idx, kbs2_idx;
string res = "";
vector<string> v;

int main() 
{
    cin >> N;
    for (int i=0;i<N;i++) {
        string tmp; cin >> tmp;
        v.push_back(tmp);

        if (tmp == "KBS1") kbs1_idx = i;
    }

    for (int i=0;i<kbs1_idx;i++) {
        res += "1";
    }
    for (int i=kbs1_idx;i>0;i--) {
        swap(v[i], v[i-1]);
        res += "4";
    }

    for (int i=0;i<N;i++) {
        if (v[i] == "KBS2") kbs2_idx = i;
    }

    for (int i=0;i<kbs2_idx;i++) {
        res += "1";
    }
    for (int i=kbs2_idx;i>1;i--) {
        swap(v[i], v[i-1]);
        res += "4";
    }

    cout << res << endl;
    return 0;
}
