#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, K;
vector<int> output;
int cnt;

void func(int sum) {

    if(sum > N) return;
    if(sum == N) {
        cnt++;
        if(cnt == K) {
            for(int i=0;i<output.size();i++) {
                cout << output[i];
                if(i != output.size()-1)
                    cout <<  '+';
            }
            cout << "\n";
        }
        return;
    }
    for(int i=1;i<=3;i++) {
        output.push_back(i);
        func(sum + i);
        output.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    func(0);
    if(cnt < K) {
        cout << -1;
    }
}
