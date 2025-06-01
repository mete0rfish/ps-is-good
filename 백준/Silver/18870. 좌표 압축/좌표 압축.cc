#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N;
  cin >> N;
  vector<long long> v;
  
  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  vector<long long> ans(v);

  sort(ans.begin(), ans.end());

  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  for(int i=0;i<N;i++){
    auto tmp = lower_bound(ans.begin(), ans.end(), v[i]);
    cout << tmp - ans.begin() <<' ';
  }

  
  
}