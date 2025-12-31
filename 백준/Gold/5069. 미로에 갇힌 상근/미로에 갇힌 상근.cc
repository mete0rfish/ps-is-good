#include <vector>
#include <iostream>

using namespace std;

// dp[i][x][y]
// dp[1][]


long long dp[16][100][100];
int px[6] = {0,1,1,0,-1,-1};
int py[6] = {1,0,-1, -1,0,1};

int sx = 20;
int sy = 20;

void func() {
    dp[0][sx][sy] = 1;

    for (int i=1;i<=14;i++) {
        for (int x=0;x<100;x++) {
            for (int y=0;y<100;y++) {
                if (dp[i-1][x][y] == 0) continue;

                for (int dir = 0; dir<6; dir++) {
                    int nx = x + px[dir];
                    int ny = y + py[dir];

                    if (nx <0 || ny<0|| nx>=100 || ny>=100) continue;

                    dp[i][nx][ny] += dp[i-1][x][y];
                }
            }
        }
    }
}

int solution(int t, int n, vector<int> arr) {
    int answer = 0;

    
    return answer;
}

int main() {
    int t, n;
    cin >> t;

    func();

    for (int i=0;i<t;i++) {
        cin >> n;
        cout << dp[n][sx][sy] << "\n";
    }


    return 0;
}
