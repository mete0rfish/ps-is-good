#include <iostream>
#include <vector>

using namespace std;

string arr[65];
int N;

void func(int size, int x, int y) {
    char cur = arr[x][y];
    
    for(int i=x;i<x+size;i++) {
        for(int j=y;j<y+size;j++) {
            if(arr[i][j] != cur) {
                cout << "(";
                func(size/2, x, y);
                func(size/2, x, y+size/2);
                func(size/2, x+size/2, y);
                func(size/2, x+size/2, y+size/2);
                cout << ")";
                return;
            }
        }
    }
    
    cout << cur;
}

int main() {
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    func(N, 0 ,0);
    return 0;
}
