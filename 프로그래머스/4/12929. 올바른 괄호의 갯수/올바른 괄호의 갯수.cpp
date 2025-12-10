#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int N;
int res;

void func(int left_cnt, int right_cnt, string str) {
    if (left_cnt == N && right_cnt == N) {
        res++;
        return;
    }
    
    if(left_cnt + 1 <= N) func(left_cnt+1, right_cnt, str+"(");
    if(right_cnt < left_cnt)  func(left_cnt, right_cnt+1, str+")");
}

int solution(int n) {
    N = n;
    
    func(0,0,"");
    
    return res;
}