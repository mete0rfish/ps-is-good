#include <iostream>
#include <algorithm>

using namespace std;

/*
1. 미세먼지 확산, /5
for(int i)
    for(int j)
        tmp[i][j] = - (arr[i][j]/5 * 빈칸 수)
        for(i : 4)
            tmp[nx][ny] += i
        

2. 공청기
gong {a, 0} -> a = gong[0].first
gong {b, 0} -> b = gong[1].first;

for(int x=a-1;x>=0;x--)
    if(arr[x+1][0] != -1)
        arr[x+1][0] = arr[x][0];

for(int y=1; y<M;y++)
    arr[y+1][0] = arr[y][0];

for(int x=1;x<=a;i++)
    arr[x-1][M-1] = arr[x][M-1];

for(int y=M-2;y>=1;y--)
    arr[y+1][a] = arr[y][a];

*/
int N, M, T;
int arr[51][51];
int tmp[51][51];
vector<pair<int,int>> gong;
int px[4] = {0,-1,0,1};
int py[4] = {1,0,-1,0};

void phase1() {
    fill(&tmp[0][0], &tmp[50][50], 0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] <= 0) continue;

            int value = arr[i][j]/5;
            int num = 0;
            for(int k=0;k<4;k++) {
                int nx = px[k] + i;
                int ny = py[k] + j;
                if(nx < 0 || ny < 0 || nx>=N || ny>=M) continue;
                if(arr[nx][ny] == -1) continue;

                tmp[nx][ny] += value;
                num++;
            }
            tmp[i][j] += -(value*num);
        }
    }

    // for(int i=0;i<N;i++) {
    //         for(int j=0;j<M;j++) {
    //             cout << tmp[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            arr[i][j] += tmp[i][j];
        }
    }
}

void phase2() {
    int a = gong[0].first;
    int b = gong[1].first;
    for(int x=a-2;x>=0;x--) {
        arr[x+1][0] = arr[x][0];
    }
    for(int y=1; y<M;y++) {
        arr[0][y-1] = arr[0][y];
    }
    for(int x=1;x<=a;x++) {
        arr[x-1][M-1] = arr[x][M-1];
    }
    for(int y=M-2;y>=1;y--) {
        arr[a][y+1] = arr[a][y];
    }
    arr[a][1] = 0;


    for(int x=b+2;x<N;x++) {
        arr[x-1][0] = arr[x][0];
    }
    
    for(int y=1; y<=M;y++) {
        arr[N-1][y-1] = arr[N-1][y];
    }
    
    for(int x=N-2;x>=b;x--){
        arr[x+1][M-1] = arr[x][M-1];
    }
    
    for(int y=M-2;y>=1;y--) {
        arr[b][y+1] = arr[b][y];
    }
    arr[b][1] = 0;

    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main() {
    cin >> N >> M >> T;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -1) {
                gong.push_back(make_pair(i, j));
            }
        }
    }

    while(T--) {
        phase1();
        phase2();
    }

    int res = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] != -1) 
                res += arr[i][j];
        }
    }
    cout << res;
    
    return 0;
}