#include <iostream>
#include <cstring>

using namespace std;

int T;
long long ax, ay, ar, bx, by ,br;
long long d, add, sub;

int main() {
    cin >> T;
    while (T--) {
        cin >> ax >> ay >> ar >> bx >> by >> br;

        d = (ax-bx) * (ax-bx) + (ay-by) * (ay-by);
        add = (ar+br) * (ar+br);
        sub = (ar-br) * (ar-br);
        
        if (d == 0 && ar == br) cout << -1 << "\n";
        else if (d == add || d == sub) cout << 1 << "\n";
        else if (sub < d && d < add) cout << 2 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}