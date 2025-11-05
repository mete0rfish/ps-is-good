#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int areas[502][502];
bool vst[502][502];
int cnts[1250002];
set<int> idxs[502];
int px[4] = {-1,0,1,0};
int py[4] = {0,-1,0,1};
int N;
int M;
int cnt = 0;

void dfs(int x, int y, int idx, vector<vector<int>>& land) {
    cnt++;
    idxs[y].insert(idx);
    for(int i=0;i<4;i++) {
        int nx = x + px[i];
        int ny = y + py[i];

        if (nx <0||ny<0||nx>=N || ny>=M) continue;
        if(areas[nx][ny] > 0) continue;
        if(land[nx][ny] == 0) continue;
        
        areas[nx][ny] = idx;
        dfs(nx, ny, idx, land);
    } 
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    N = land.size();
    M = land[0].size();
    
    int idx = 1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(land[i][j] == 1 && areas[i][j] == 0) {
                cnt = 0;
                
                vst[i][j] = true;
                areas[i][j] = idx;
                dfs(i,j,idx,land);
                cnts[idx] = cnt;
                idx = idx+1;
            }
        }
    }
    
    for(int y=0;y<M;y++){
        int sum = 0;
        for(auto i : idxs[y]) {
            sum += cnts[i];
        }
        answer = max(answer, sum);
    }
    
    return answer;
}