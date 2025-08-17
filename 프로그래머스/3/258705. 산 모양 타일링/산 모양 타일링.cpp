#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MAX_SIZE;
int MOD = 10007;
int res;
int dp1[100001];
int dp2[100001];

int solution(int n, vector<int> tops) {
    dp1[0]=1;
    dp2[0]=0;
    
    for(int i=1;i<=n;i++) {
        if(tops[i-1] == 1) {
            dp1[i] = (3*dp1[i-1] + 2*dp2[i-1])%MOD;
            dp2[i] = (dp1[i-1] + dp2[i-1])%MOD;
        }
        else {
            dp1[i] = (2*dp1[i-1] + dp2[i-1])%MOD;
            dp2[i] = (dp1[i-1] + dp2[i-1])%MOD;
        }
    }
    
    return (dp1[n]+dp2[n])%MOD;
}