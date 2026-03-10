#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> v;

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string str; cin >> str;
        v.push_back(str);
    }

    int tmp = min(N, M);
    for (int i=tmp;i>1;i--) {
        for (int j=0;j<=N-i;j++) {
            for (int k=0;k<=M-i;k++) {
                char a = v[j][k];
                char b = v[j][k+i-1];
                char c = v[j+i-1][k];
                char d = v[j+i-1][k+i-1];
                if (a == b && b == c && c == d) {
                    cout << i*i;
                    return 0;
                }
            }
        }
    }
    cout << 1;
    return 0;
}