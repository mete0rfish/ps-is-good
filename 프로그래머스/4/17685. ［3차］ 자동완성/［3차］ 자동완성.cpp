#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int finds(string a, string b) {
    int mn = a.length() > b.length() ? b.length() : a.length();
    int cnt = 0;
    for (int i=0;i<mn;i++) {
        if(a[i] != b[i]) break;
        cnt++;
    }
    
    return cnt;
}

int solution(vector<string> words) {
    int answer = 0;
    
    sort(words.begin(), words.end());
    
    for (int i=0;i<words.size();i++) {
        int common = 0;
        if (i > 0) {
            common = max(common, finds(words[i-1], words[i])+1);
        }
        if (i < words.size()-1) {
            common = max(common, finds(words[i+1], words[i])+1);
        }
        
        if (common > words[i].length()) common = words[i].length();
        
        answer += common;
    }
    return answer;
}