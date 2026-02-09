#include <iostream>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int R, C, Q;
int r1, c1, r2, c2;

int main() 
{
    cin >> R >> C >> Q;
    for(int i=1;i<=R;i++) {
        for (int j=1;j<=C;j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
        }
    }
    
    for(int i=0;i<Q;i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        int div = (r2 - r1 + 1) * (c2 - c1 + 1);
        cout << (dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1]) / div << "\n";
    }
    return 0;
}
