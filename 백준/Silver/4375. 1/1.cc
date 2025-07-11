#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    
    while(scanf("%d", &N) != EOF) {
        int num = 1;
        int len = 1;
        while(true) {
            if(num%N == 0) break;
            num = num * 10 + 1;
            num %= N;
            len++;
        }
        cout << len << "\n";
    }
    return 0;
}