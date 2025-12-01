#include <iostream>

using namespace std;

unsigned int N;

int main() 
{
    cin >> N;
    bool isPowerTwo = (N & (N-1)) == 0;
    cout << isPowerTwo ? 1 : 0;
    return 0;
}
