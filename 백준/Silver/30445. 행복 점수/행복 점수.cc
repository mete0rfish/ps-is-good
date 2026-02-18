#include <iostream>
#include <map>

using namespace std;

map<char, int> m;
string str;

int main() {
    getline(cin, str);

    for (int i=0;i<str.length();i++) {
        m[str[i]]++;
    }

    double ph = m['H'] + m['A'] + m['P'] + m['Y'];
    double pg = m['S'] + m['A'] + m['D'];

    if (ph == 0 && pg == 0) {
        cout << "50.00";
    } else {
        double h = (ph / (ph + pg)) * 100;
        h += 1e-9;
        printf("%.2f", h);
    }
    
    return 0;
}