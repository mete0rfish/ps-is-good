#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
    int cost, x, y;
}info;

struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.cost > b.cost;
    }
};

bool vst[126][126];
int dist[126][126];
int N;


int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx = 1;
    while(1) {
        priority_queue<info, vector<info>, cmp> pq; 
        int arr[126][126];
        fill(&vst[0][0], &vst[125][125], false);
        fill(&dist[0][0], &dist[125][125], 1e9);
        
        cin >> N;
        if(N == 0) break;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin >> arr[i][j];
            }
        }

        pq.push({arr[0][0], 0, 0});
        dist[0][0] = arr[0][0];
        while(!pq.empty()) {
            int cost = pq.top().cost;
            int x = pq.top().x;
            int y = pq.top().y;
            pq.pop();
            
            if(vst[x][y]) continue;
            vst[x][y] = true;

            for(int i=0;i<4;i++) {
                int nx = px[i] + x;
                int ny = py[i] + y;

                if(nx < 0 || ny < 0 || nx>=N || ny >=N) continue;
                
                int next_cost = arr[nx][ny];
                if(dist[nx][ny] > dist[x][y] + next_cost) {
                    dist[nx][ny] = dist[x][y] + next_cost;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }

        cout <<"Problem " << idx++ <<": "<< dist[N-1][N-1] << "\n";
    }
    
    
    
    return 0;
}