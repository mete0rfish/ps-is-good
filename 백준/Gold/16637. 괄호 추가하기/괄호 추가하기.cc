#include <ios>
#include <iostream>
#include <queue>

using namespace std;

int N;
long long mx_value=-999999999;
string expr;
vector<int> ops;
vector<int> nums;

long long calc(long long num_a, char op, long long num_b) {
    if (op == '+') return num_a + num_b;
    else if (op == '-') return num_a - num_b;
    else return num_a * num_b;
}

void dfs(int ops_idx, long long cur_value) {
    if (ops_idx >= ops.size()) {
        mx_value = max(mx_value, cur_value);
        return;
    }

    // 1. 자신과 다음꺼 계산
    long long a = calc(cur_value, ops[ops_idx], nums[ops_idx+1]);
    dfs(ops_idx+1, a);

    // 2. 내 앞에 계산
    if (ops_idx + 1 < ops.size()) {
        long long tmp = calc(nums[ops_idx+1], ops[ops_idx+1], nums[ops_idx+2]);
        long long b = calc(cur_value, ops[ops_idx], tmp);
        dfs(ops_idx+2, b);
    }
}

int main() {
    cin >> N;
    cin >> expr;

    for (int i=0;i<expr.length();i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            ops.push_back(expr[i]);
        }
        else {
            nums.push_back(expr[i]- '0');
        }
    }

    dfs(0, nums[0]);

    cout << mx_value;
    
    return 0;
}
