#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
    1. 양방향 탐색
    2. arr[i] < arr[i-1] 끝
    3. cnt로 연속된 지대 개수 세기
*/

int N, L;
int arr1[101][101];
int arr2[101][101];
int res;

bool isValid(int arr[][101], int x, int y, bool isInstalled[][101]) {
    int prev = arr[x][y];
    for(int i=x;i<x+L;i++) {
        if(i < 0 || i >= N) return false;
        if(isInstalled[i][y]) return false;
        if(arr[i][y] != prev) return false;
    }
    return true;
}

void move(int arr[][101]) {
    for(int y=0;y<N;y++) {
        bool isInstalled[101][101] = {false, };
        int prev = arr[0][y];
        bool flag = true;
        for(int x=0;x<N;x++) {
            if(abs(prev - arr[x][y]) > 1) {
                flag = false;
            }
            else if(prev - arr[x][y] == 1) {
                if(!isValid(arr, x, y, isInstalled)) flag = false;
                else {
                    for(int i=x;i<x+L;i++)isInstalled[i][y] = true;
                }
            }
            else if(prev - arr[x][y] == -1) {
                if(!isValid(arr, x-L, y, isInstalled)) flag = false;
                else {
                    for(int i=x-L;i<x;i++)isInstalled[i][y] = true;
                }
            }

            prev = arr[x][y];
        }
        if(flag) {
            res++;
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }

    move(arr1);
    move(arr2);
    
    cout << res;
    return 0;
}