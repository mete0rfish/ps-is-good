#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[1001];
vector<int> two;
int res;

int N, tmp;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    for(int i=0;i<N-1;i++) {
        for(int j=i;j<N;j++) {
            two.push_back(arr[i] + arr[j]);
        }
    }
    
    sort(arr, arr+N);
    sort(two.begin(), two.end());
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int sum = arr[i];
            int c = arr[j];
            
            int l = 0;
            int r = two.size();
            while(l < r) {
                int m = (l + r) / 2;
                int aAndB = two[m];
                
                if(aAndB + c == sum) {
                    res = max(res, sum);
                    break;
                }
                else if(aAndB + c < sum) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
    }
    
    cout << res;
    return 0;
}

// -10 -9 2 4 4

