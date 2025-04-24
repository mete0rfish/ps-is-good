#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

int N, K;
int A,B,C,D;

typedef struct country {
    int id;
    int gold;
    int silver;
    int bronze;

    country(int a, int b, int c, int d) {
        id = a;
        gold = b;
        silver = c;
        bronze = d;
    }
}country;

vector<country> v;

bool cmp(country a, country b) {
    if(a.gold == b.gold) {
        if(a.silver == b.silver) {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> A >> B >> C >> D;
        v.push_back(country(A, B, C ,D));
    }

    sort(v.begin(), v.end(), cmp);

    int rank = 1;
    int same = 0;
    for(int i=0;i<v.size();i++) {
        if(i > 0 && (v[i].gold != v[i-1].gold || v[i].silver != v[i-1].silver || v[i].bronze != v[i-1].bronze)) {
            rank+=same;
            same = 0;
        }

        if(K == v[i].id) {
            cout << rank;
            break;
        }

        same++;
    }
}
