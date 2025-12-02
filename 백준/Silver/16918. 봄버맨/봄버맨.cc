#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// 0: 설치1
// 1: 
// 2: 남은곳 설치2
// 3: 설치1 터짐
// 4: 남은곳 설치1
// 5: 설치2 터짐
// 6: 남은곳 설치2
// 7. 설치1 터짐



int R, C, N;
char arr[201][201];
bool tmp[201][201];
vector<pair<int ,int>> bombs;
vector<pair<int ,int>> bombs2;

int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

// 1단계 폭발 후
void calc2() {
    for(auto bomb : bombs) {
        int x = bomb.first; int y = bomb.second;
        tmp[x][y] = true;

        for(int i=0;i<4;i++) {
            int nx = px[i] + x;
            int ny = py[i] + y;

            if(nx < 0 || ny <0 || nx >= R || ny >= C) continue;

            tmp[nx][ny] = true;
        }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if (tmp[i][j]) {
                arr[i][j] = '.';
            }
            else {
                bombs2.push_back({i, j});
                arr[i][j] = 'O';
            }
        }
    }
}

// 2단계 폭파 후
void calc1() {
    memset(tmp, false, sizeof(tmp));

    for(auto bomb : bombs2) {
        int x = bomb.first; int y = bomb.second;
        tmp[x][y] = true;

        for(int i=0;i<4;i++) {
            int nx = px[i] + x;
            int ny = py[i] + y;

            if(nx < 0 || ny <0 || nx >= R || ny >= C) continue;

            tmp[nx][ny] = true;
        }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if (tmp[i][j]) {
                arr[i][j] = '.';
            }
            else {
                arr[i][j] = 'O';
            }
        }
    }
}

void calc3() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout << 'O';
        }
        cout << endl;
    }
}

void calc0() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    
    cin >> R >> C >> N;
    for (int i=0;i<R;i++) {
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++) {
            if (str[j] == 'O') {
                bombs.push_back({i, j});
            }
            arr[i][j] = str[j];
        }
    }

// 설치1: 1, 5, 9 (0 || 1+4*N)
// 설치2: 3, 7, 11 (3+4*N)
// 모두 : 2, 4, 6, 8, 10 ... (2의 배수)

    if(N==1) {
        calc0();
    }
    else if((N-1)%4 == 0) {
        calc2(); calc1(); calc0();
    }
    else if (N%2==0) {
        calc3();
    }
    else if((N-3)%4 == 0) {
        calc2(); calc0();
    } 

    return 0;
}
