#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n;
int arr[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=0;i<50;i++) {
        for(int j=0;j<50;j++) {
            arr[i][j] = 1e9;
        }
    }

    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++) {
            if(i == j) {
                arr[i][j] = 0;
            }
            else if(str[j]=='Y') {
                arr[i][j] = 1;
            }
        }
    }

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int res =0;
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            if(i!=j && arr[i][j] <= 2) {
                cnt++;
            }
        }
        res = max(res, cnt);
    }

    cout << res;
    return 0;
}
