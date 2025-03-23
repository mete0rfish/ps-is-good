#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, M, L;
int p[51];
vector<int> knower;
vector<int> v[51];

int find_parent(int x) {
    if (p[x] == x) return x;
    return p[x] = find_parent(p[x]);
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if (x < y) {
        p[y] = x;
    } else {
        p[x] = y;
    }
}

bool compare_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return true;
    return false;
}

void init() {
    for(int i=1;i<=N;i++) {
        p[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cin >> L;
    init();
    for (int i = 0; i < L; i++) {
        int tmp; cin >> tmp;
        knower.push_back(tmp);
    }
    sort(knower.begin(), knower.end());

    int num, a;
    for (int i = 0; i < M; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> a;
            v[i].push_back(a);
        }
        sort(v[i].begin(), v[i].end());
    }

    // 각 파티의 유니온 파인드
    for (int i = 0; i < M; i++) {
        int n1 = v[i][0];
        for (int j = 1; j < v[i].size(); j++) {
            int n2 = v[i][j];
            union_parent(n1, n2);
        }
    }

    int cnt = M;
    for(int i=0;i<M;i++) {
        bool isInvalid = false;
        for(int j=0;j<v[i].size();j++) {
            if(isInvalid)   break;
            int n1 = v[i][j];
            for(int k=0;k<L;k++) {
                int n2 = knower[k];
                if(compare_parent(n1, n2)) {
                    isInvalid = true;
                    break;
                }
            }
        }
        if(isInvalid) {
            cnt--;
        }
    }

    cout << cnt;
}
