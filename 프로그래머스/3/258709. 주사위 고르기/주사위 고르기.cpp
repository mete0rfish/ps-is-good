#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<int> combinations;
int max_wins = -1;

void calc(int cnt, int sum, const vector<int>& dice_indices, const vector<vector<int>>& dice, vector<int>& sums) {
    if(cnt == dice_indices.size()) {
        sums.push_back(sum);
        return;
    }
    
    int cur_idx = dice_indices[cnt];
    for(int d : dice[cur_idx]) {
        calc(cnt+1, sum+d, dice_indices, dice, sums);
    }
}

void generate(int idx, int count, int n, const vector<vector<int>>& dice) {
    if(count == n/2) {
        vector<int> sum_a, sum_b;
        vector<int> b_combinations;
        vector<bool> isA(n, false);
        
        // 1. B 조합 구하기
        for(int i : combinations) {
            isA[i] = true;
        }
        for(int i=0;i<n;i++) {
            if(!isA[i]) b_combinations.push_back(i);
        }
        
        calc(0, 0, combinations, dice, sum_a);
        calc(0, 0, b_combinations, dice, sum_b);
        
        sort(sum_b.begin(), sum_b.end());
        
        int wins = 0;
        for(int a : sum_a) {
            auto it = lower_bound(sum_b.begin(), sum_b.end(), a);
            wins += (it - sum_b.begin());
        }
        
        if(max_wins < wins) {
            max_wins = wins;
            answer = combinations;
            for(int i=0;i<combinations.size();i++) {
                answer[i]++;
            }
        }
        return;
    }
    
    for(int i=idx;i<n;i++) {
        combinations.push_back(i);
        generate(i+1, count+1, n, dice);
        combinations.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    generate(0, 0, dice.size(), dice);
    
    return answer;
}