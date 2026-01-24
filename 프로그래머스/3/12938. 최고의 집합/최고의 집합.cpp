#include <string>
#include <vector>

using namespace std;
// 10 -> 10/3 = 3
// 7 -> 7/2 = 3
// 4 -> 4/1 = 4
vector<int> solution(int n, int s) {
    vector<int> answer;
    
    for (int i = n;i>=1;i--) {
        int num = s/i;
        if (num == 0) {
            answer = {-1};
            break;
        }
        answer.push_back(num);
        s-=num;
    }
    
    return answer;
}