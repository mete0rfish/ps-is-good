#include <iostream>
#include <algorithm>

using namespace std;

int T, t;

int main() 
{
    cin >> T;

    while (T--) {
        cin >> t;
        int target = t*60+30;
        if (target%(25*60) <=17*60) cout << "ONLINE\n";
        else cout << "OFFLINE\n"; 
    }

    return 0;
}