#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> va;
vector<int> vb;
int n, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> a >> b;
    int mh = max(a, b);
    
    for(int i=1;i<=a;i++) {
        if(i == a) {
            va.push_back(mh);
        }
        else {
            va.push_back(i);
        }
    }
    for(int i=b-1;i>=1;i--) {
        vb.push_back(i);
    }

    int tmp = n - (va.size() + vb.size());
    if(tmp < 0) {
        cout << -1;
    }
    else if(tmp == 0) {
        for(auto t : va) cout << t <<' ';
        for(auto t : vb) cout << t <<' ';
    }
    else {
        if(a <= 1) {
            for(auto t : va) cout << t <<' ';
            for(int i=0;i<tmp;i++) cout << "1 ";
            for(auto t : vb) cout << t <<' ';
        }
        else {
            for(int i=0;i<tmp;i++) cout << "1 ";
            for(auto t : va) cout << t <<' ';
            for(auto t : vb) cout << t <<' ';
        }
    }
    
    
    return 0;
}