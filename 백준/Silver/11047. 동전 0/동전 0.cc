#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int N,K;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  for(int i=0;i<N;i++){
    int tmp; cin >> tmp;
    if(tmp<=K)
      v.push_back(tmp);
  }
  
  int sum=0;
  int cnt=0;
  int len = v.size()-1;
  while(1){
    if(sum==K)  break;
    
    if(K-sum>=v[len]){
      sum += v[len];
      cnt++;
    }
    else{
      len--;
    }
  }
  cout << cnt;
  
}