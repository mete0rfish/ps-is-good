#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long N, M;
long long B;
map<string, long long> m;  

int main() 
{
    cin >> B >> N >> M;
    for (int i=0;i<N;i++) {
        string str;
        long long price;
        cin >> str >> price;

        m[str] = price;
    }

    long long sum = 0;
    for (int i=0;i<M;i++) {
        string str;
        cin >> str;

        sum += m[str];
        if (sum > B) {

            cout << "unacceptable";
            return 0;
        }

    }
    
    cout << "acceptable";
    return 0;
}