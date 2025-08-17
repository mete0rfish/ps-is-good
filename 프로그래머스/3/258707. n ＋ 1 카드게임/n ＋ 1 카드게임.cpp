#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx, N, SUM, coins;
vector<int> hands;
vector<int> drawn;
int a, b, res= 1;


int solution(int coin, vector<int> cards) {
    N = cards.size();
    SUM = N + 1;
    
    for(int i=0;i<N/3;i++) {
        hands.push_back(cards[i]);
    }
    
    a = N/3;
    b = N/3 + 1;
    
    while(a < N) {
        bool isPassed = false;
        
        drawn.push_back(cards[a]);
        drawn.push_back(cards[b]);
        
        // 0코인 소모
        for(int i=0;i<hands.size();i++) {
            for(int j=i+1;j<hands.size();j++) {
                if(hands[i] + hands[j] == SUM) {
                    hands.erase(hands.begin() + j);
                    hands.erase(hands.begin() + i);
                    isPassed = true;
                    break;
                }
            }
            if(isPassed) break;
        }
        
        // 1코인 소모
        if(!isPassed && coin >= 1) {
            for(int i=0;i<hands.size();i++) {
                int target = SUM - hands[i];
                auto it = find(drawn.begin(), drawn.end(), target);
                if(it != drawn.end()) {
                    coin--;
                    hands.erase(hands.begin() + i);
                    drawn.erase(it);
                    isPassed = true;
                    break;
                }
            }
        }
        
        
        // 2코인 소모
        if(!isPassed && coin >= 2) {
            for(int i=0;i<drawn.size();i++) {
                for(int j=i+1;j<drawn.size();j++) {
                    if(drawn[i] + drawn[j] == SUM) {
                        coin -= 2;
                        drawn.erase(drawn.begin()+j);
                        drawn.erase(drawn.begin()+i);
                        isPassed = true;
                        break;
                    }
                }
                if(isPassed) break;
            }
        }
    
        // 라운드 종료 시
        if(isPassed) {
            res++;
            a += 2;
            b += 2;
        } else {
            break;
        }
    }
    return res;
}