#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
[1,4][2,1][2,2][3,2][3,4]
max_a = [3,2] 
max_b = [1,4]

[4,1],[3,4],[3,2][3,2][2,2][2,1][1,4]
max_a = [4,1]
max_b = [3,4]
*/

vector<int> correct;
vector<int> target;

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    target = scores[0];
    sort(scores.begin(), scores.end(), cmp);
    int n = scores.size();
    
    int max_score = 0;
    for(auto s : scores) {
        if(s[1] < max_score) {
            if(s[0] == target[0] && s[1] == target[1]) {
                return -1;
            }
        }
        else {
            max_score = max(max_score, s[1]);
            correct.push_back(s[0] + s[1]);
        }
    }
    
    int rank = 1;
    for(long long sum : correct) {
        if(sum > target[0] + target[1]) {
            rank++;
        }
    }
    
    return rank;
}