#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int res;
int arr[21][21];
int maps[21][21];
bool vst[21][21];
vector<pair<int,int>> empties;
vector<pair<int,int>> enemy;
int px[4] = {0,1,0,-1};
int py[4] = {1,0,-1,0};

void init() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            maps[i][j] = arr[i][j];
        }
    }
}

void setOne(int a, int b) {
    maps[empties[a].first][empties[a].second] = 1;
    maps[empties[b].first][empties[b].second] = 1;
    // cout << "====setOne====\n";
    // cout << empties[a].first <<", " <<empties[a].second << endl;
    // cout << empties[b].first <<", " <<empties[b].second << endl << endl;
}

int calcTwo(int x, int y) {
    // cout << "=== dfs ===\n";
    // cout << "{ " << x << ", " << y << " }" <<endl;
    
    queue<pair<int, int>> q;
    vector<pair<int, int>> two_group;

    two_group.push_back(make_pair(x, y));
    q.push(make_pair(x, y));
    vst[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = x + px[i];
            int ny = y + py[i];
            
            if(nx < 0 || ny < 0 || nx >=N || ny >= M) continue;
            if(vst[nx][ny]) continue;
            if(maps[nx][ny] == 2) {
                two_group.push_back(make_pair(nx, ny));
                vst[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    // cout << "group size: " << two_group.size() << endl;
    bool isInvalid = false;
    for(auto two : two_group) {
        for(int i=0;i<4;i++) {
            int nx = two.first + px[i];
            int ny = two.second + py[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(maps[nx][ny] == 0) {
                isInvalid = true;
                break;
            }
        }
        if(isInvalid) {
            return 0;
        }
    }
    
    return two_group.size();
}

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) empties.push_back(make_pair(i, j));
            else if(arr[i][j] == 2) enemy.push_back(make_pair(i, j));
        }
    }

    for(int i=0;i<empties.size()-1;i++) {
        for(int j = i+1; j<empties.size();j++) {

            // 1. 초기화
            init();
            fill(&vst[0][0], &vst[20][20], false);

            // 2. 1로 채우기
            setOne(i, j);

            // 3. 먹은 알 계산하기
            int totCnt = 0;
            for(int k=0;k<enemy.size();k++) {
                int enemy_x = enemy[k].first;
                int enemy_y = enemy[k].second;
                if(!vst[enemy_x][enemy_y]) {
                    totCnt += calcTwo(enemy_x, enemy_y);
                }
            }

            // 4. 가장 큰 경우 저장하기
            res = max(res, totCnt);
        }
    }

    cout << res;
    
    return 0;
}