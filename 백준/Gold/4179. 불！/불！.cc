#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int R,C;
char arr[1001][1001];
int j_dis[1001][1001];
int f_dis[1001][1001];
bool j_chk[1001][1001];
bool f_chk[1001][1001];
queue<pair<int,int>> fire;
queue<pair<int,int>> jihun;

bool faced =false;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void f_bfs(){
  pair<int, int> cur_fire;

  
  
  while(!fire.empty()){
    cur_fire = fire.front();
    fire.pop();

    for(int i=0;i<4;i++){
      int f_nx = dx[i] +  cur_fire.first;
      int f_ny = dy[i] +  cur_fire.second;
      
      if(f_nx<0 || f_ny<0 || f_nx>=R || f_ny >= C) continue;
      if(f_chk[f_nx][f_ny] || f_dis[f_nx][f_ny]==-1)  continue;
      
      f_chk[f_nx][f_ny] =true;
      fire.push({f_nx,f_ny});
      f_dis[f_nx][f_ny] = f_dis[cur_fire.first][cur_fire.second]+1;
    }
  }
}

void j_bfs(){

  pair<int, int> cur_jihun;


  while(!jihun.empty()){
    cur_jihun = jihun.front();
    jihun.pop();
    if(cur_jihun.first==0 || cur_jihun.second==0 || cur_jihun.first==R-1 || cur_jihun.second == C-1){
      cout << j_dis[cur_jihun.first][cur_jihun.second]+1;
      faced = true;
      return;
    }

    for(int i=0;i<4;i++){
      int j_nx = dx[i] +  cur_jihun.first;
      int j_ny = dy[i] +  cur_jihun.second;

      if(j_nx<0 || j_ny<0 || j_nx>=R || j_ny >= C) continue;
      if(j_chk[j_nx][j_ny] || j_dis[j_nx][j_ny]==-1)  continue;
      //추가 조건 : 불의 시간과 같을때는 제외
      j_dis[j_nx][j_ny] = j_dis[cur_jihun.first][cur_jihun.second]+1;

      //cout << j_dis[j_nx][j_ny] << " , " << f_dis[j_nx][j_ny] << endl;
      
      if(j_dis[j_nx][j_ny] >= f_dis[j_nx][j_ny] && f_chk[j_nx][j_ny]==true){
        j_dis[j_nx][j_ny] = 0;
        
        continue;
      }

      //조건 부적합 시 통과
      j_chk[j_nx][j_ny] =true;
      jihun.push({j_nx,j_ny});
    }
  }
}

int main() {
  cin >>R >> C;
  int f_x,f_y,j_x,j_y;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin >> arr[i][j];
      if(arr[i][j]=='#'){
        j_dis[i][j]=-1;
        f_dis[i][j]=-1;
      }
      if(arr[i][j]=='J'){
        j_chk[i][j] = true;
        
      }
      if(arr[i][j]=='F'){
        f_chk[i][j] = true;
      }
    }
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]=='J'){
        jihun.push({i,j});
        j_dis[i][j] = 0;
      }
      if(arr[i][j]=='F'){
        fire.push({i,j});
        f_dis[i][j] = 0;
      }
    }
  }

  f_bfs();
  j_bfs();

  /*
  cout << "지훈이" <<endl;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout << j_dis[i][j] << ' ';
    }
    cout << endl;
  }

  
  cout << endl << endl <<"불" << endl;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout << f_dis[i][j] << ' ';
    }
    cout << endl;
  }
  
*/
  
  int ans=10000;
  if(!faced){
    for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(j_dis[i][j] > f_dis[i][j]){
        cout << "IMPOSSIBLE";
        return 0;
      }
      else if(j_dis[i][j] == 0 && j_chk[i][j] == false){
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }
  }
  
  
  //cout << ans+1;
  
}