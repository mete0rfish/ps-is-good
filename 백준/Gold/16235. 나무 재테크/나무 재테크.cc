#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, y, z;
int N, M, K;
int ground[12][12];
int added[12][12];
vector<int> trees[12][12];

int px[9] = {0,1,0,-1, -1,-1,1,1};
int py[9] = {1,0,-1,0, -1,1,-1,1};


void spring_summber() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(trees[i][j].empty()) continue;
            
            sort(trees[i][j].begin(), trees[i][j].end());
            
            vector<int> alive;
            int dead_age = 0;

            for(int age : trees[i][j]) {
                if(ground[i][j] >= age) {
                    ground[i][j] -= age;
                    alive.push_back(age+1);
                }
                else {
                    dead_age += (age/2);
                }
            }
            trees[i][j] = alive;
            ground[i][j] += dead_age;
        }
    }
}

void fall_winter() {
    for(int x=1;x<=N;x++) {
        for(int y=1;y<=N;y++) {
            for(int age : trees[x][y]) {
                if(age % 5 == 0) {
                    for(int i=0;i<8;i++) {
                        int nx = px[i] + x;
                        int ny = py[i] + y;
        
                        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                        
                        trees[nx][ny].push_back(1);
                    }
                }
            }

            ground[x][y] += added[x][y];
        }
    }       
}

int main() {
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            ground[i][j] = 5;
            cin >> added[i][j];
        }
    }

    for(int i=0;i<M;i++) {
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    for(int i=0;i<K;i++) {
        spring_summber();
        fall_winter();
    }

    int res = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            res += trees[i][j].size();
        }
    }

    cout << res << "\n";
    
    return 0;
}