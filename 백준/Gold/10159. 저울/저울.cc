#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[101][101];
vector<int> edge[101];
int N, M;

int main() {
    cin >> N >> M;

    fill(&d[0][0], &d[100][100], 1e9);
    
    int a, b;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        d[a][b] = 1;
    }

    for(int k = 1; k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }


    // for(int i = 1; i<=N;i++) {
    //     for(int j=1;j<=N;j++) {
    //         if(d[i][j] == 1e9) cout << "0 ";
    //         else cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    for(int i=1;i<=N;i++) {
        int cnt = 0;
        for(int j=1;j<=N;j++) {
            if(i==j) continue;
            if(d[i][j] != 1e9) cnt++;
            if(d[j][i] != 1e9) cnt++;
        }

        cout << N - cnt - 1 << "\n";
    }

    return 0;
}