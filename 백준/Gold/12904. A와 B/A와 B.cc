#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    while(1) {
        if(b[b.length()-1] == 'A') {
            b.pop_back();
        }
        else {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
        if(a.length() == b.length()) {
            break;
        }
    }

    if(a.compare(b) == 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}