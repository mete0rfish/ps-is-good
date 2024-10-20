#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

ll t, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll gap = b-a;
        ll remain = gap;
        ll res = 0;
        bool flag = false;
        for(int i=1;i<gap;i++) {
            flag =false;
            for(int j=1;j<=2;j++) {

                if(remain - i >= 0) {
                    //cout << "remain: "<<remain << ", i: " << i << endl;
                    remain -= i;
                    res++;
                }
                else {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(remain > 0) {
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}
