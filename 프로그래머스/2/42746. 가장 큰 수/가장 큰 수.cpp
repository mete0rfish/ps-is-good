#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_str;
    for (int num : numbers) {
        num_str.push_back(to_string(num));
    }
    
    sort(num_str.begin(), num_str.end(), cmp);
    
    for (string str : num_str) {
        answer += str;
    }
    
    if (answer[0] == '0') return "0";
    
    return answer;
}