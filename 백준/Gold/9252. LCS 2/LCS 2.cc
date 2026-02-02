#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int dp[1001][1001];

void solution(string a, string b) {
    int n = a.length();
    int m = b.length();

    for (int i=1; i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i=n,j=m;
    string answer = "";
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            answer += a[i-1];
            i--;
            j--;
        }
    }

    reverse(answer.begin(), answer.end());

    cout << dp[n][m] << "\n";
    if (dp[n][m] > 0) cout << answer;
}

int main() 
{
    string a, b;
    cin >> a >> b;
    solution(a, b);

    return 0;
}

