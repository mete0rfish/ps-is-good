#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, tmp;
    cin >> N;
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int tmp; cin >> tmp;
            
            pq.push(tmp);
            if (pq.size() > N) {
                pq.pop();
            }
        }
    }

    // for (int i=0;i<N-1;i++) pq.pop();

    cout << pq.top();
    return 0;
}
