#include <iostream>

using namespace std;

int N, K, A, B;

int main() {
    cin >> N >> K;

    long long sum_a = 0, sum_b = 0;
    for (int i=1;i<=N;i++) {
        long long cur_a, cur_b;
        cin >> cur_a >> cur_b;

        long long next_a = sum_a + cur_a;
        long long next_b = sum_b + cur_b;

        long long op_a = sum_a + (cur_a * 3 / 2);

        
        bool win_op_a = (op_a >= K);
        bool win_a = (next_a >= K);
        bool win_b = (next_b >= K);
        bool gap_op_a = (op_a - next_b >= 50);
        bool gap_a = (next_a - next_b >= 50);
        
        // OP 써서 1
        if ((win_op_a && !win_b) || gap_op_a) {
            cout << 1;
            return 0;
        }

        // OP 안쓰고 게임 끝
        if (win_a && win_b) {
            cout << 1;
            return 0;
        }
        if (win_a || gap_a) {
            cout << 1;
            return 0;
        }
        if (win_b) {
            cout << -1;
            return 0;
        }

        sum_a = next_a;
        sum_b = next_b;
    }
    cout << 0;
    
    return 0;
}