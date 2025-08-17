#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int res_win = -1;
vector<int> res;
vector<int> a_dice;

void calc(int cnt, int sum, const vector<int>& t_dice, const vector<vector<int>>& dice, vector<int>& t_sum) {
    if(cnt == t_dice.size()) {
        t_sum.push_back(sum);
        return;
    }
    
    int cur_idx = t_dice[cnt]; // 현재 돌릴 주사위 번호
    for(int i=0;i<dice[cur_idx].size();i++) {
        calc(cnt+1, sum+dice[cur_idx][i], t_dice, dice, t_sum);
    }
}

void choose_dice(int cnt, int idx, const vector<vector<int>> dice) {
    if(cnt == N/2) {
        vector<int> b_dice;
        vector<int> a_sum, b_sum;
        vector<bool> isUsed(N, false);
        for(int i=0;i<a_dice.size();i++) {
            isUsed[a_dice[i]] = true;
        }
        for(int i=0;i<N;i++) {
            if(!isUsed[i]){
                b_dice.push_back(i);
            }
        }
        
        calc(0, 0, a_dice, dice, a_sum);
        calc(0, 0, b_dice, dice, b_sum);
        
        sort(b_sum.begin(), b_sum.end());
        
        int win = 0;
        for(int i=0;i<a_sum.size();i++) {
            auto it = lower_bound(b_sum.begin(), b_sum.end(), a_sum[i]);
            win += it - b_sum.begin();
        }
        
        if(res_win < win) {
            res_win = win;
            res = a_dice;
        }
    }
    
    for(int i=idx;i<N;i++) {
        a_dice.push_back(i);
        choose_dice(cnt+1, i+1, dice);
        a_dice.pop_back();
    }   
}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    choose_dice(0, 0, dice);
    
    for(int i=0;i<res.size();i++) {
        res[i]++;
    }
    return res;
}