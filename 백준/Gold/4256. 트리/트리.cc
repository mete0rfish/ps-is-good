#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int T, N, tmp;
vector<int> pre;
vector<int> in;
vector<int> post;

void func(int pre_start, int pre_end, int in_start, int in_end) {
    
    if(pre_start > pre_end) {
        return;
    }

    int root = pre[pre_start];
    int root_idx = 0;

    for(int i=in_start;i<=in_end;i++) {
        if (in[i] == root) {
            root_idx = i;
            break;
        }
    } 

    int len = root_idx - in_start;

    // 왼쪽 서브트리
    func(pre_start+1, pre_start + len, in_start, root_idx-1);

    // 오른쪽 서브트리
    func(pre_start + len+1, pre_end, root_idx+1, in_end);

    post.push_back(root);
}

int main() {
    cin >> T;
    while(T--) {
        cin >> N;

        pre.clear(); in.clear(), post.clear();

        for(int i=0;i<N;i++) {
            cin >> tmp;
            pre.push_back(tmp);
        }

        for(int i=0;i<N;i++) {
            cin >> tmp;
            in.push_back(tmp);
        }
        func(0, N-1, 0, N-1);

        for(auto p : post) cout << p << " ";
        cout << "\n";
    }

    return 0;
}
