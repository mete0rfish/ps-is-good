#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool vst[51];
int res = 1e9;

int check(string cur, string target) {
    int cnt = 0;
    for(int i=0;i<cur.length();i++) {
        if(cur[i] != target[i]) cnt++;
    }
    return cnt;
}

void func(int cnt, string cur, string target, vector<string>& words) {
    cout << cur << endl;
    if (cur == target) {
        res = min(res, cnt);
        return;
    }
    
    for(int i=0;i<words.size();i++) {
        string next = words[i];
        
        if (check(cur, next) == 1 && !vst[i]) {
            vst[i] = true;
            func(cnt+1, next, target, words);
            vst[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    func(0, begin, target, words);
    if (res == 1e9) return 0;
    return res;
}