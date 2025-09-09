#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;

string to_binary(long long num) {
    if (num == 0) {
        return "0";
    }
    string binary_str = "";
    while (num > 0) {
        binary_str += (num % 2) ? '1' : '0';
        num /= 2;
    }
    reverse(binary_str.begin(), binary_str.end());
    return binary_str;
}

string add_zero(string str) {
    int current_len = str.length();
    int target_len = 0;
    int n = 0;

    while (pow(2, n) - 1 < current_len) {
        n++;
    }
    
    target_len = pow(2, n) - 1;
    
    string padding(target_len - current_len, '0');
    
    padding += str;
    return padding;
}

bool check(string& str, int start, int end) {
    if (start > end) {
        return true;
    }

    int idx = start + (end - start) / 2;
    
    if (str[idx] == '0') {
        int left_mid_idx = start + (idx - 1 - start) / 2;
        int right_mid_idx = (idx + 1) + (end - (idx + 1)) / 2;
        
        if (left_mid_idx >= start && str[left_mid_idx] == '1') {
            return false;
        }
        if (right_mid_idx <= end && str[right_mid_idx] == '1') {
            return false;
        }
    }
    
    return check(str, start, idx-1) && check(str, idx+1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(auto number : numbers) {
        string binary = to_binary(number);
        binary = add_zero(binary);
        bool flag= check(binary,0, binary.length()-1);
            
        if(flag) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    
    return answer;
}