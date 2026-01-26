#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

vector<long long> v;
stack<long long> stk;

// 꼴찌와 같을 경우
// 꼴지와 다를 경우

int main() 
{
    long long N, newScore, P;
    cin >> N >> newScore >> P;
    
    
    for (int i=0;i<N;i++) {
        long long score;
        cin >> score;
        v.push_back(score);
    }

    sort(v.begin(), v.end());

    for (int i=0;i<v.size(); i++) {
        if (newScore <= v[i])
        stk.push(v[i]);
    }

    int biggerThan = 0, biggerOrEqual = 0;

    for (int i=0;i<v.size();i++) {
        if (v[i] > newScore) {
            biggerThan++;
            biggerOrEqual++;
        }
        if (v[i] == newScore) {
            biggerOrEqual++;
        }
    }

    if (biggerOrEqual >= P) cout << -1;
    else cout << biggerThan+1;

    return 0;
}
