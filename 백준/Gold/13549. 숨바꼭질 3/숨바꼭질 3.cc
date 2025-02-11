#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int n, k;
int res;
bool visited[100001];

void bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, n });

    while(!pq.empty()) {
        int time = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if(visited[pos])    continue;
        visited[pos] = true;
        //cout << pos << endl;
        if(pos == k) {
            res = time;
            break;
        }

        if(pos +1 >= 0 && pos +1 <=100000) {
            pq.push({time+1, pos+1});

        }
        if(pos -1 >= 0 && pos -1 <=100000) {
            pq.push({time+1, pos-1});

        }
        if(pos *2 >= 0 && pos *2 <=100000) {
            pq.push({time, pos*2});
            
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    bfs();
    cout << res;

    return 0;
}
