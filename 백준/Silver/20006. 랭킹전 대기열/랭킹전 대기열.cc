#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool vst[20001];

typedef struct {
    int level;
    vector<pair<int, string>> players;
} room;

bool cmp(pair<int, string>& a, pair<int, string>& b) {
    return a.second < b.second;
}

void solution(vector<pair<int, string>>& list, int m) {
    vector<room> rooms;

    for (auto player : list) {
        if (rooms.empty()) {
            rooms.push_back({player.first, {player}});
            continue;
        }

        bool joined = false;
        for (auto& room : rooms) {
            if (room.players.size() == m) continue;

            if (room.level - 10 <= player.first && player.first <= room.level + 10) {
                room.players.push_back(player);
                joined = true;
                break;
            }
        }
        if (!joined) {
            rooms.push_back({player.first, {player}});
        }
    }

    for (auto room : rooms) {
        if (room.players.size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";

        sort(room.players.begin(), room.players.end(), cmp);

        for (auto player : room.players) {
            cout << player.first << " " << player.second << "\n";
        }
    }
}

int main() 
{
    int p, m, l;
    string n;

    cin >> p >> m;
    cin.ignore();

    vector<pair<int, string>> list;
    for(int i=0;i<p;i++) {
        cin >> l >> n;
        list.push_back({l, n});
    }

    solution(list, m);

    return 0;
}
