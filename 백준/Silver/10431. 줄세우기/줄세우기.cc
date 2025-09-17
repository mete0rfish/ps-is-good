#include <iostream>

using namespace std;

int P;
int arr[21];

int main() {
    cin >> P;

    for(int idx=0;idx<P;idx++) {
        int num;
        cin >> num;
        for(int i=0;i<20;i++) cin >> arr[i];
        
        int result = 0;
        for(int i=0;i<20;i++) {
            for(int j=i;j<20;j++) {
                if(arr[i] > arr[j]) {
                    result++;
                }
            }
        }
    
        cout << num <<" "<<result <<"\n";
    }

    
    return 0;
}