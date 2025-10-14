/*
    이동하려는 곳이 직선 상인지 확인
    6,3  7,7
    6,3 6,4 6,5 6,6
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool dot[51][51];
bool cel[51][51];
bool vst[51][51];

int dist[51][51];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

queue<pair<int, int>> q;
int res=1e9;

void init(const vector<vector<int>>& rectangle) {
    for(auto rec : rectangle) {
        int x1 = rec[0]; int y1 = rec[1];
        int x2 = rec[2]; int y2 = rec[3];
        
        for(int i=x1;i<x2;i++) {
            for(int j=y1;j<y2;j++) {
                cel[i][j] = true;
            }
        }
        
        // x1,y1 -> x1,y2 -> x2,y2
        for(int j=y1;j<=y2;j++) {
            dot[x1][j] = true;
        }
        for(int i=x1;i<=x2;i++) {
            dot[i][y2] = true;
        }
        
        // x1,y1 -> x2,y1 -> x2,y2
        for(int i=x1;i<=x2;i++) {
            dot[i][y1] = true;
        }
        for(int j=y1;j<=y2;j++) {
            dot[x2][j] = true;
        }
    }
}

void print() {
    for(int i=0;i<11;i++) {
        for(int j=0;j<11;j++) {
            cout << dot[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<11;i++) {
        for(int j=0;j<11;j++) {
            cout << cel[i][j] << " ";
        }
        cout << endl;
    }
}

// 모두 벽이거나 모두 빈칸이면 false
bool isCel(int x, int y, int dir) {
    // cout << x << ", " << y << ": " << dir << endl;
    if(dir == 0) { // 위 4,6->3,6 == 3,5 3,6
        return (cel[x][y-1] && cel[x][y]) || (!cel[x][y-1] && !cel[x][y]);
    }
    else if(dir == 1) { // 왼 6,9->6,8 == 58 68
        return (cel[x-1][y] && cel[x][y]) || (!cel[x-1][y] && !cel[x][y]);
    }
    else if(dir == 2) {//아래 2,4 -> 3,4 == 2,3 2,4
        cout << x <<", " << y << endl;
        cout << x-1 <<", " << y-1 << "   "<<x-1 <<", "<<y << endl;
        cout << cel[x-1][y-1] << ", " << cel[x-1][y] << endl;
        return (cel[x-1][y-1] && cel[x-1][y]) || (!cel[x-1][y-1] && !cel[x-1][y]);
    }
    else { // 오  1,3 -> 1,4  == 0,3 1,3
        
        return (cel[x-1][y-1] && cel[x][y-1]) || (!cel[x][y-1] && !cel[x-1][y-1]);
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    init(rectangle);
    print();
    q.push({characterX, characterY});
    vst[characterX][characterY] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == itemX && y == itemY) {
            res = min(res, dist[x][y]);
            break;
        }

        
        for(int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];
            
            if(nx<0 || ny<0||nx>50||ny>50) continue;
            if(!dot[nx][ny]) continue;
            cout << nx << ", " << ny <<": " << i << endl;
            if(vst[nx][ny]) continue;
            if(isCel(nx,ny, i)) continue;
            
            
            vst[nx][ny] = true;
            dist[nx][ny] = dist[x][y]+1;
            q.push({nx, ny});
        }
    }
    
    return res;
}