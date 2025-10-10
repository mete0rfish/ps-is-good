#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int res = 0;
int px[4]={-1,0,1,0};
int py[4]={0,-1,0,1};

bool removed[51][51];


void dfs(char ch, int option, const vector<string>& storage) {
    bool tmp[51][51];
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            tmp[i][j] = removed[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if (!removed[i][j] && ch == storage[i][j]) {
                if(option == 0) {
                    queue<pair<int ,int>> q;
                    bool vst[51][51] = {false, };
                    bool flag = false;
                    q.push({i, j});
                    vst[i][j] = true;

                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                    
                        
                        for(int k=0;k<4;k++) {
                            int nx = x + px[k];
                            int ny = y + py[k];
                            
                            if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                                tmp[i][j] = true;
                                goto end_loop;
                            }
                            if(vst[nx][ny]) continue;
                            if(!removed[nx][ny]) continue;
                            vst[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                    end_loop:;
                }
                else if (option == 1) {
                    tmp[i][j] = true;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            removed[i][j] = tmp[i][j];
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    N = storage.size();
    M = storage[0].length();
    
    for(int i=0;i<requests.size();i++) {
        
        if(requests[i].length() == 1) {
            dfs(requests[i][0], 0, storage);
        }
        else {
            dfs(requests[i][0], 1, storage);
        }
        
        
    }
    
     for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(!removed[i][j])res++;
        }
    }
    
    return res;
}