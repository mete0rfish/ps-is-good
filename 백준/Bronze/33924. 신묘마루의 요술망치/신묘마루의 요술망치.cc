#include <functional>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M,K;
string str;
int arr[8];

/*
0 1
2 3
4 5
6 7

*/
int main() 
{
    cin >> N >> M;
    cin >> K;
    cin >> str;

    int idx = (N-1)*2 + (M-1);
    arr[idx] = 1;

    for (char ch : str) {
        if (ch == 'A') {
            for (int i=0;i<4;i++) {
                swap(arr[i], arr[i+4]);
            }
        }
        else if (ch == 'B') {
            swap(arr[0],arr[3]); swap(arr[1], arr[2]);
            swap(arr[4],arr[7]); swap(arr[5], arr[6]);
        }
        else if (ch == 'C') {
            swap(arr[0],arr[7]); swap(arr[1], arr[6]);
            swap(arr[2],arr[5]); swap(arr[3], arr[4]);
        } else {
            int tmp = arr[0];
            arr[0] = arr[2];
            arr[2] = arr[4];
            arr[4] = arr[6];
            arr[6] = arr[7];
            arr[7] = arr[5];
            arr[5] = arr[3];
            arr[3] = arr[1];
            arr[1] = tmp;
        }
    }

    for (int i=0;i<8;i++) {
        if (arr[i] == 1) {
            cout << (i/2) + 1 << " " << (i%2) + 1; 
            break;
        }
    }


    return 0;
}
