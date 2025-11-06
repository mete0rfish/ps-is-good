#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int arr[20][20];
bool chk[20]; //chk를 이용하여 1팀이면 true, 2팀이면 false
int mini = 9999;

void dfs(int cnt, int pos){  //cnt = i
  
  if(cnt==N/2){
    int a_team=0, b_team=0; //총 점수
    
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(chk[i]==true && chk[j]==true)
          a_team += arr[i][j];
        if(chk[i]==false && chk[j]==false)
          b_team += arr[i][j];
      }
    }
    //cout << "a_team : " << a_team << " ,b_team : " << b_team << endl; 

    if(abs(a_team - b_team) < mini){
      mini = abs(a_team - b_team);
      return;
    }
  }

  
  for(int i=pos;i<N;i++){
    chk[i] = true;
    dfs(cnt+1, i+1);
    chk[i] = false;
  }
  
}

int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> arr[i][j];
    }
  }
  dfs(0,0);

  cout << mini;
  
  return 0;
}