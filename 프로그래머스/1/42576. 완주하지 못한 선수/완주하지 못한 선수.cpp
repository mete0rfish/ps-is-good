#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    
    for(string p: participant)
        m[p]++;
    
    for(string p: completion)
        m[p]--;
    
    for(auto tmp : m) {
        if(tmp.second != 0)
            return tmp.first;
    }
}