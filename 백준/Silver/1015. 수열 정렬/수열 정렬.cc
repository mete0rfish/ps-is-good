#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
vector<pair<int, int>> v;

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin >> N;
    
    for (int i=0;i<N;i++) {
        int a;
        cin >> a;
        v.push_back({a, i});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (v[j].second == i) {
                cout << j << " ";
            }
        }
    }
    
    return 0;
}