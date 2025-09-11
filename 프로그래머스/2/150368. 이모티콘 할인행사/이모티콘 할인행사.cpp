#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
[4][4][4][4][4][4]
[i][j]: i개 상품의 할인율이 j일때 최대값

 40  40  40   40
780 900 960 2940 = 5580

 30   30   30   30
910 1050 1120 3430

무조건 가입안하는 사람: 임계값이 가장 싼 한 개를 사더라도 임계값을 못넘는 사람
무조건 가입하는 사람: 임계값이 가장 싼 한 개를 사더라도 임계값을 넘는 사람
임계값이 5580 넘지 않으면 가입자X

(40), (40), 32, 27, 23, 11 5


1. 최소 할인율로 다 사도 임계값을 넘지못하면 무시
2. 최소 할인율로 다 사면 무조건 가입하는 경우
3. 

*/
int N, M;
int discounts[4] = {40, 30, 20, 10};
vector<int> selected;
vector<int> answer;

void calc(const vector<vector<int>>& users, const vector<int>& emoticons) {
    int buy=0;
    int sum=0;
    for(int i=0;i<N;i++) {
        int percent = users[i][0]; int price = users[i][1];
        int total=0;
        for(int j=0;j<M;j++) {
            int discount = discounts[selected[j]];
            if(discount >= percent) {
                total += (emoticons[j]*(100 - discount)/100);
            }
        }
        

        // 임계값 넘으면 buy+1, 안넘으면 sum += total
        if(price <= total) {
            buy++;
        }
        else {
            sum += total;
        }
    }
    
    if(answer[0] < buy) {
        answer[0] = buy; answer[1] = sum;
    }
    else if(answer[0] == buy) {
        if(answer[1] < sum) {
            answer[0] = buy; answer[1] = sum;
        }
    }
}

void choose(int cnt, const vector<vector<int>>& users, const vector<int>& emoticons) {
    if(cnt == M) {
        calc(users, emoticons);
        return;
    }
    
    for(int i=0;i<4;i++) {
        selected.push_back(i);
        choose(cnt+1, users, emoticons);
        selected.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    N = users.size();
    M = emoticons.size();
    answer.push_back(0); answer.push_back(0);
    choose(0, users, emoticons);
    
    return answer;
}