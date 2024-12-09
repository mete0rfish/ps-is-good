#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int N, M;
map<string, vector<string>> teamToMember;
map<string, string> memberToTeam;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string team, member;
    int cnt;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> team;
        cin >> cnt;
        for(int j=0;j<cnt;j++) {
            cin >> member;
            teamToMember[team].push_back(member);
            memberToTeam[member] = team;
        }
    }

    string que;
    int type;
    for(int i=0;i<M;i++) {
        cin >> que;
        cin >> type;

        if(type == 1) {
            cout << memberToTeam[que] << endl;
        }
        else {
            vector<string> members = teamToMember[que];
            sort(members.begin(), members.end());
            for(int j=0;j<members.size();j++) {
                cout << members[j] << endl;
            }
        }
    }

    return 0;
}
