#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
/*
5+5+5/5+5/5
5/5=1
55/5=11
555/5=111
5555/5 =1111
5555/55 = 101
55555/5 = 11111

5

5+5, 5/5, 5-5, 5*5, 55
dp[2] (사칙) 5  
dp[3]


+ - * / (+5)

dp[2] = dp[1] + dp[1];
*/

using namespace std;
vector<int> dp[9];

int solution(int N, int number) {
    int answer = 0;
    dp[0].push_back(0);
    dp[1].push_back(N);
    if (number == N) return 1;
    
    for(int idx=2;idx<9;idx++) {
        vector<int> v;
        int sum = 0; int temp = 0;
        for(int i=0;i<idx;i++) {
            sum += pow(10, temp++) * N;
        }
        v.push_back(sum);
        //
        for(int i=1;i<idx;i++) {
            for(auto a: dp[i]) {
                for(auto b: dp[idx-i]) {
                    v.push_back(a + b);
                    v.push_back(a - b);
                    v.push_back(a * b);
                    if (b!=0) v.push_back(a / b);
                }
            }
            
            for(auto t : v) {
                if(t == number) return idx;
            }
            dp[idx] = v;
        }
    }
    return -1;
}