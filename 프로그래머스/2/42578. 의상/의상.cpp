#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    
    for(int i=0;i<clothes.size();i++) {
        m[clothes[i][1]]++;
    }
    
    int sum = 1;
    for(auto a : m) {
        sum *= (a.second + 1);
    }
    
    
    return sum-1;
}