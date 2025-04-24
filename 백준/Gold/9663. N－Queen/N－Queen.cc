#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[16]; //한줋에 하나씩 둔다고 가정
int cnt=0;

//같은 줄 : i==tmp
//같은 세로 : arr[i] == arr[tmp]
//대각선 : i + arr[i] == tmp + arr[tmp]
//대각선2 : i - arr[i] == 0

bool chk(int tmp){ 
  for(int i=0;i<tmp;i++){
    if(arr[i] == arr[tmp] || i==tmp || i+arr[i] == tmp+arr[tmp] ||i-arr[i] == tmp-arr[tmp]){ //겹칠때
      return false;
    }
  }
  return true;
}

void dfs(int tmp){
  if(tmp == N){ //체스를 N개만큼 둠. 
    cnt++; //경우의 수+1
    return;
  }
  else{
    for(int i=0;i<N;i++){
      arr[tmp] = i;
      if(chk(tmp)){
        dfs(tmp+1);
      }
    }
  }
}

int main() {
  cin >> N;
  dfs(0);
  cout << cnt;
  return 0;
}