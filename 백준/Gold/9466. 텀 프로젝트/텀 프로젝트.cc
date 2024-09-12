#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int t;
int arr[100001], n, res;
bool visited[100001];
bool done[100001];
queue<int> q;

void findCycle(int front, int back) {
    for(int i = back; i!= front; i = arr[i]) {
        res++;
    }
    res++;
}

void dfs(int idx) {

    q.push(idx);
    visited[idx] = true;
    int next = arr[idx];
    //cout <<"idx: " << idx << ", next : " << next << endl;
    if(!visited[next]) {
        dfs(next);
    }
    else if(!done[next]) {
        findCycle(idx, next);
    }

    done[idx] = true;
}

void func() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            while(!q.empty()) q.pop();
            dfs(i);
        }
    }
    cout << n - res << "\n";
    res = 0;
    memset(visited, false, sizeof(visited));
    memset(done, false, size(done));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        func();
    }

    return 0;
}
