#include <iostream>

using namespace std;

int main() 
{
    int X, Y;
    cin >> X >> Y;
    
    int sum = 0;
    for (int i=1; i<X; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) sum += 30;
        else if (i== 2) sum += 28;
        else sum += 31;
    }
    sum += Y;
    
    if (sum%7 == 0) cout << "SUN";
    else if (sum%7 == 1) cout << "MON";
    else if (sum%7 == 2) cout << "TUE";
    else if (sum%7 == 3) cout << "WED";
    else if (sum%7 == 4) cout << "THU";
    else if (sum%7 == 5) cout << "FRI";
    else if (sum%7 == 6) cout << "SAT";

    return 0;
}
