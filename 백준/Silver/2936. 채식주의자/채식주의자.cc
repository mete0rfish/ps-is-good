#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int a, b;

int main() 
{
    cin >> a >> b;
    if (a+b == 0) {
        cout << "125.00 125.00";
        return 0;
    }

    double base = 250.0*250.0/2;

    if (a > 0 && b > 0) {
        if (a > b) printf("0.00 %.2f", 250.0 - base / a);
        else printf("%.2f 0.00", 250.0 - base / b);
    }
    else if ( a < 125 && b == 0) {
        double tmp = 250.0 - base / (250 - a);
        printf("%.2f %.2f", tmp, 250.0 - tmp);
    }
    else if (a == 0 && b < 125) {
        double tmp = 250.0 - base / (250 - b);
        printf("%.2f %.2f", 250.0 - tmp, tmp);
    }
    else if (b == 0) {
        printf("0.00 %.2f", base / a);
    }
    else {
        printf("%.2f 0.00", base / b);
    }

    return 0;
}