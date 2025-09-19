#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

//  5 24 28 30 45 50 52 60 98
//  5 28 24 45 30 60 52 98 50

// 24 < 28 : stk.top() < num 일 동안 빼기 

// 전위 -> 중위 : 3까지 쌓고, 탑보다 작으면 그냥 출력, 탑보다 크면 탑 빼고 넣고

int N, M;
vector<int> preorders;

void to_postorders(int st, int ed) {
    if(st >= ed) return;

    // 리프 노드이면 출력
    if(st == ed -1) {
        cout << preorders[st] << "\n";
        return;
    }

    // 루트 노드가 먼저나오는 전위 순회 이므로, 순차 접근하다가 루트 노드보다 커지는 순가니 오른쪽 노드의 루트 노드임. 
    int idx = st + 1;
    while(idx < ed) {
        if(preorders[st] < preorders[idx]) break;
        idx++;
    }
    to_postorders(st+1, idx);
    to_postorders(idx, ed);
    cout << preorders[st] << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int num;
    while(scanf("%d", &num) != EOF) {
        preorders.push_back(num);
    }

    to_postorders(0, preorders.size());

    return 0;
}