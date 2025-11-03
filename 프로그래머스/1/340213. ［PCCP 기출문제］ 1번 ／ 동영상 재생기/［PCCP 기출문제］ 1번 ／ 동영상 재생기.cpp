#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int parse(string str) {
    int m = stoi(str.substr(0,2));
    int s = stoi(str.substr(3,2));
    return m*60 + s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int len = parse(video_len);
    int p = parse(pos);
    int op_s = parse(op_start);
    int op_e = parse(op_end);

    for (auto command : commands) {
        if(op_s <= p && p <= op_e) p = op_e;
        
        if(command == "prev") {
            p -= 10;
            if (p < 0) p = 0;
        } else if (command == "next") {
            p += 10;
            if (p > len) p = len;
        }
    }
    
    if(op_s <= p && p <= op_e) p = op_e;
    string m = to_string(p/60);
    string s = to_string(p%60);
    if (m.length() < 2) m = "0"+m;
    if (s.length() < 2) s = "0"+s;
    
    return m + ":" + s;
}