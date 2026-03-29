#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{
    long long a, b;
    cin >> a >> b;

    long long res = log10(a) * b;
    cout << res + 1;

    return 0;
}