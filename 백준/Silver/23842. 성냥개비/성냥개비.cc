#include <iostream>
#include <cstring>

using namespace std;

int n;
int num[10] ={6,2,5,5,4,5,6,3,7,6};

void print_zero(int target) {
    if(target/10==0) {
        cout<< "0";
    }
}

void print(int a, int b, int c) {
    print_zero(a);cout << a << "+";
    print_zero(b);cout << b << "=";
    print_zero(c);cout << c ;
}

int main() {
    cin >> n;
    for(int i=0;i<=99;i++) {
        int a = num[i/10] + num[i%10];
        for(int j=0;j<=99;j++) {
            int b = num[j/10] + num[j%10];
            for(int k=0;k<=99;k++) {
                int c = num[k/10] + num[k%10];
                if(a+b+c == n-4 && i+j ==k) {
                    
                    print(i,j,k);
                    return 0;
                }
            }
        }
    }
    cout << "impossible";
    return 0;
}