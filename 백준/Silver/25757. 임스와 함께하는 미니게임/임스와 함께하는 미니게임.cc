#include <iostream>
#include <map>

using namespace std;

map<string, bool> m;

int main() {
    int N;
    char C;
    cin >> N >> C;

    int cnt = 0;
    int res = 0;
    while(N--) {
        string str;
        cin >> str;
        
        if(m[str])  continue;
        
        m[str] = true;
        cnt++;

        if(C == 'Y') {
            res++;
            cnt=0;
        }
        else if(C=='F' && cnt == 2) {
            res++;
            cnt=0;
        }
        else if(C=='O' && cnt == 3) {
            res++;
            cnt=0;
        }
    }

    cout << res;
    return 0;
}