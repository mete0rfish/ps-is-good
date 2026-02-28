#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[16][16];
int res;

bool isValid(int r1, int c1, int r2, int c2) {
    int area = (r2-r1+1)*(c2-c1+1);

    vector<bool> chk(area+1, false);

    for (int i=r1;i<=r2;i++) {
        for (int j=c1;j<=c2;j++) {
            if (arr[i][j] > area) return false;
            if (chk[arr[i][j]]) return false;

            chk[arr[i][j]] = true;
        }
    }

    return true;
}

int main() 
{
    int N;
    cin >> N;

    for (int i=0; i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    for (int r1=0;r1<N;r1++) {
        for (int c1=0;c1<N;c1++) {
            for (int r2=r1;r2<N;r2++) {
                for (int c2=c1;c2<N;c2++) {
                    if(isValid(r1, c1, r2, c2)) res++;
                }
            }
        }
    }

    cout << res;

    return 0;
}