#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void func(int num) {
    string str = "";
    while (num != 0) {
        if (num % -2 == 0) {
            str += "0";
            num /= -2;
        } else {
            str += "1";
            num = (num-1) / -2;
        }
    }

    reverse(str.begin(), str.end());

    cout << str << endl;
}

int main() 
{
    int num;
    cin >> num;

    if (num == 0) {
        cout << 0;
    } else {
        func(num);
    }

    return 0;
}
