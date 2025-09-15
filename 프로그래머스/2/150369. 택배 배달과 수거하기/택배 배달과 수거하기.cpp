#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long d_cnt = 0;
    long long p_cnt = 0;
    for(int i=n-1;i>=0;i--) {
        d_cnt += deliveries[i];
        p_cnt += pickups[i];
        
        while(d_cnt > 0 || p_cnt > 0) {
            d_cnt -= cap;
            p_cnt -= cap;
            answer += (i + 1) * 2;
        }
    }
    return answer;
}