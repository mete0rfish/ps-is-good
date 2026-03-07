#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    
    vector<pair<int, int>> v(N);
    
    for (int i=0;i<N;i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector<int> P(N);
    for (int i=0;i<N;i++) {
        P[v[i].second] = i;
    }

    for (int i=0;i<N;i++) {
        cout << P[i] << " ";
    }
    
    return 0;
}