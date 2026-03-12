#include <iostream>

using namespace std;

int T, N;
int over[5002];
int is_beauty[5002];

int func2(int num) {
    if (num <= 1) return 0;

    int sum = 1;
    for (int i=2;i*i<=num;i++) {
        if (num % i ==0) {
            sum += i;
            if (i * i != num) {
                sum += num /i;
            }
        }
    }
    return sum;
}

void func(int n) {
    if (func2(n) <= n) {
        cout << "BOJ 2022\n";
        return ;
    } 

    bool isBeautiful = true;
    for (int i=1;i<=n/2;i++) {
        if (n%i==0) {
            if (func2(i) > i) {
                isBeautiful = false;
                break;
            }
        }
    }

    if (isBeautiful) cout << "Good Bye\n";
    else cout << "BOJ 2022\n";
}

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        func(N);
    }
    return 0;
}