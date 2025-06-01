#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxA, maxB;

int solution(vector<vector<int>> sizes) {
    
    for(int i=0; i < sizes.size(); i++) {
        int a = sizes[i][0];
        int b = sizes[i][1];
        
        if(a > b) {
            maxA = max(maxA, a);
            maxB = max(maxB, b);
        }
        else {
            maxA = max(maxA, b);
            maxB = max(maxB, a);
        }
    }
    
    return maxA * maxB;
}