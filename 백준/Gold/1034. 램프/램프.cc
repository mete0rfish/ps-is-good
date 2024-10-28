#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n,m,k;
string arr[51];
priority_queue<pair<int,int>> pq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cin >> k;

    int res = 0;
    for(int i=0;i<n;i++) {
        int tmp=0;
        for(int j=0;j<m;j++) {
            if(arr[i][j] == '0')    tmp++;
        }

        if(tmp%2 == k%2 && k >= tmp) {
            int ttmp=0;
            for(int k=0;k<n;k++) {
                if(arr[i]==arr[k])  ttmp++;
            }
            res = max(res, ttmp);
        }
    }

    cout << res;

    return 0;
}
