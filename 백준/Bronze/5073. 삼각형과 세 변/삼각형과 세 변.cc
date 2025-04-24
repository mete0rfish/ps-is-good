#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int a, b, c;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    while(1) {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)  break;

        if(a > b && a > c) {
            if(a >= b+c) {
                cout << "Invalid" << "\n";
                continue;
            }
        }
        else if(b > a && b > c) {
            if(b >= a+c) {
                cout << "Invalid" << "\n";
                continue;
            }
        }
        else {
            if(c >= a+b) {
                cout << "Invalid" << "\n";
                continue;
            }
        }

        if(a == b) {
            if(b == c) {
                cout << "Equilateral\n";
            }
            else {
                cout << "Isosceles\n";
            }
        }
        else if(a == c) {
            if(c == b) {
                cout << "Equilateral\n";
            }
            else {
                cout << "Isosceles\n";
            }
        }
        else if(b == c) {
            if(c == a) {
                cout << "Equilateral\n";
            }
            else {
                cout << "Isosceles\n";
            }
        }
        else {
            if(b == c) {
                cout << "Isosceles\n";
            }
            else {
                cout << "Scalene\n";
            }
        }
    }
}
