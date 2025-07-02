#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
string a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> a;
    int res = 0;
    for(int i=0;i<a.length();i++) {
        if(a[i] == '1')res++;
    }
   
    cout << res;
    return 0;
}