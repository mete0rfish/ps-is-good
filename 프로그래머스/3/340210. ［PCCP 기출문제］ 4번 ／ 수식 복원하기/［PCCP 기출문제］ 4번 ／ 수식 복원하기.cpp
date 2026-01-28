#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    string a, b, c;
    char oper;
} node;

vector<node> answers;
vector<node> problems;
int possible[10];
int min_base = 2; // 전역으로 최소 진법 관리

int convert(string str, int jinsu) {
    int res = 0;
    int tmp = 1;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == ' ') continue;
        res += (str[i] - '0') * tmp;
        tmp *= jinsu;
    }
    return res;
}

string unconvert(int num, int jinsu) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res += to_string(num % jinsu);
        num /= jinsu;
    }
    reverse(res.begin(), res.end());
    return res;
}

void analyze_answers() {
    for (int jinsu = min_base; jinsu <= 9; jinsu++) {
        bool is_ok = true;
        for (node answer : answers) {
            int a = convert(answer.a, jinsu);
            int b = convert(answer.b, jinsu);
            int c = convert(answer.c, jinsu);
            
            if (answer.oper == '+') {
                if (a + b != c) { is_ok = false; break; }
            } else {
                if (a - b != c) { is_ok = false; break; }
            }
        }
        if (is_ok) possible[jinsu] = 1;
    }
}

void solve() {
    for (node &problem : problems) {
        string res_val = "";
        for (int i = min_base; i <= 9; i++) {
            if (possible[i] == 0) continue;
            
            int a = convert(problem.a, i);
            int b = convert(problem.b, i);
            string cur_res = (problem.oper == '+') ? unconvert(a + b, i) : unconvert(a - b, i);
            
            if (res_val == "") res_val = cur_res;
            else if (res_val != cur_res) {
                res_val = "?";
                break;
            }
        }
        problem.c = res_val;
    }
}

vector<string> init() {
    vector<string> res;
    for (node problem : problems) {
        res.push_back(problem.a + " " + problem.oper + " " + problem.b + " = " + problem.c);
    }
    return res;
}

vector<string> solution(vector<string> expressions) {
    answers.clear(); problems.clear();
    min_base = 2;
    for (int i = 0; i < 10; i++) possible[i] = 0;

    for (string expression : expressions) {
        int oper_idx = expression.find(" + ");
        if (oper_idx == string::npos) oper_idx = expression.find(" - ");
        
        char oper = expression[oper_idx + 1];
        int equal_idx = expression.find("=");
        
        string a = expression.substr(0, oper_idx); 
        string b = expression.substr(oper_idx + 3, equal_idx - oper_idx - 4);
        string c = expression.substr(equal_idx + 2);
        
        // 등장하는 숫자들 중 최대값을 찾아 최소 진법 갱신
        for (char ch : a + b + (c == "X" ? "" : c)) {
            if (isdigit(ch)) min_base = max(min_base, (ch - '0') + 1);
        }
        
        if (c == "X") problems.push_back({a, b, c, oper});
        else answers.push_back({a, b, c, oper});
    }
    
    analyze_answers();
    solve();
    return init();
}