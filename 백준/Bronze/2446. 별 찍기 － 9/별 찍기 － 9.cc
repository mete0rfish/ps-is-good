#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void draw1(int n, int depth) {
    int mx_cnt = 2*n - 1;
    int empty_cnt = depth;
    int star_cnt = mx_cnt - empty_cnt*2;


    for(int i=0;i<empty_cnt;i++) {
        cout << " ";
    }
    for(int i=0;i<star_cnt;i++) {
        cout << "*";
    }

    cout << "\n";
}

int main() 
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        draw1(n, i);
    for(int i=n-2;i>=0;i--)
        draw1(n, i);

    return 0;
}

