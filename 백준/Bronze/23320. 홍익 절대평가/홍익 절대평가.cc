#include <iostream>
#include <algorithm>

using namespace std;

int N, Y, X;
int arr[101];

int main() 
{
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    cin >> X >> Y;

    sort(arr, arr + N, greater<>());

    int res1 = (N * X) / 100;
    int res2 = 0;
    for (int i=0;i<N && arr[i] >= Y;i++) {
        res2++;
    }

    cout << res1 << " " << res2;

    return 0;
}
