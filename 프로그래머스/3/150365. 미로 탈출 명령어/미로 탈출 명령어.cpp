#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

string answer = "";
bool vst[51][51];
int px[4] = {1,0,0,-1}; // d, l, r, u
int py[4] = {0,-1,1,0};
string pc[4] = {"d", "l", "r", "u"}; 
int K, R, C, N, M;

int get_dist(int x, int y) {
    return abs(x-R) + abs(y-C);
}

void dfs(int cnt, int x, int y, string command) {
    if (!answer.empty()) {
        return;
    }

    int dist = abs(x - R) + abs(y - C);
    if (dist > K - cnt) return;
    if ((K - cnt - dist) % 2 != 0) return;

    if (cnt == K) {
        if (x == R && y == C) {
            answer = command;
        }
        return;
    }
    
    for(int i=0;i<4;i++) {
        int nx = px[i] + x;
        int ny = py[i] + y;
        
        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
        
        dfs(cnt + 1, nx, ny, command + pc[i]);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N =n; M=m; R=r; C=c;K=k;
    
    
    fill(&vst[0][0], &vst[50][50], false);
    
    dfs(0, x, y, "");
    if(answer == "")
        answer = "impossible";
    
    return answer;
}