#include <iostream>
#include <map>

using namespace std;

map<string, int> m;
int times[4] = {4,6,4,10};

int main() {
    int N;
    cin >> N;
    
    for (int i=0;i<N*4;i++) {
        for (int j=0;j<7;j++) {
            string name;
            cin >> name;
            if (name == "-") continue;
            m[name] += times[i%4];
        }
    }

    int mx = 0;
    int mn = 1e9;
    for (auto& [name, count] : m) {
        mx = max(mx, count);
        mn = min(mn, count);
    }

    cout << (mx-mn <=12 ? "Yes" : "No");
    return 0;
}