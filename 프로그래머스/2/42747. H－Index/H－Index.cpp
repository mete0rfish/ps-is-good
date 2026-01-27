#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0 1 3 5 6
// 50 50 50 60
// 4-4

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int h=0;h<=citations.size();h++) {
        int mn_cnt = 0;
        int mx_cnt = 0;
        for (int i=0;i<citations.size();i++) {
            if (citations[i] >= h) mx_cnt++;
            else mn_cnt++;
        }
        
        if (mx_cnt>=h && mn_cnt<=h) {
            answer = max(answer,h);
        }
    }
    
    return answer;
}