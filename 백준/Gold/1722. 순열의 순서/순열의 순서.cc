#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
long long K;
int selected[21];
long long fact[21];
bool used[21];

void calc_fact() {
    fact[0] = 1;
    for(int i=1;i<=20;i++) {
        fact[i] = fact[i-1] * i;
    }
}

void func1() {
    cin >> K;
    for(int i=0;i<N;i++) {
        for(int j=1;j<=N;j++) {
            if(used[j]) continue;
            
            if(K > fact[N-i-1]){
                K -= fact[N-i-1];
            }
            else {
                selected[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    for(int i=0;i<N;i++) {
        cout << selected[i] << ' ';
    }
    cout << endl;
}

void func2() {
    for(int i=0;i<N;i++) {
        cin >> selected[i];
    }
    
    K = 1;

    for(int i=0;i<N;i++) {
        for(int j=1;j<selected[i];j++) {
            if(used[j]) continue;
            K += fact[N-i-1];
        }
        used[selected[i]] = true;
    }

    cout << K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    calc_fact();
    cin >> N;
    cin >> M;
    if(M == 1) {
        func1();
    }
    else {
        func2();
    }
    
    return 0;
}