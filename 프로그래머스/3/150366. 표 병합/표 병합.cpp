#include <string>
#include <vector>
#include <sstream>
#include <tuple>
#include <iostream>

using namespace std;

string arr[51][51];
pair<int, int> parent[51][51];

pair<int, int> finds(int x, int y) {
    if(parent[x][y] == make_pair(x, y)) return make_pair(x, y);
    return parent[x][y] = finds(parent[x][y].first, parent[x][y].second);
}

void merge_child(int pr, int pc, int tr, int tc) {
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=50;j++) {
            if(parent[i][j] == make_pair(pr, pc)) parent[i][j] = make_pair(tr, tc);
        }
    }
}

void unions(int r1, int r2, int c1, int c2) {
    tie(r1, c1) = finds(r1, c1);
    tie(r2, c2) = finds(r2, c2);
    
    if(r1 == r2 && c1 == c2) return;

    // 둘 다 가지고 있는 경우, a 값 가짐
    if(!arr[r1][c1].empty() && !arr[r2][c2].empty()) {
        parent[r2][c2] = make_pair(r1, c1);
        merge_child(r2, c2, r1, c1);
    }
        
    // a만 가지는 경우,
    else if(!arr[r1][c1].empty()) {
        parent[r2][c2] = make_pair(r1, c1);
        merge_child(r2, c2, r1, c1);
    }
    else {
        parent[r1][c1] = make_pair(r2, c2);
        merge_child(r1, c1, r2, c2);
    }
}

void update(int r, int c, string value) {
    tie(r,c) = finds(r, c);
    arr[r][c] = value;
}

void unmerge(int r, int c) {
    int orir = r;
    int oric = c;
    
    tie(r, c) = finds(r, c);
    string value = arr[r][c];
    
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=50;j++) {
            if(parent[i][j] == make_pair(r, c)) {
                parent[i][j] = make_pair(i, j);
                arr[i][j].clear();
            }
        }
    }
    
    arr[orir][oric] = value;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            parent[i][j] = make_pair(i, j);
        }
    }
    
    for(string command : commands) {
        stringstream ss(command);
        vector<string> tmp;
        string str;
        while(ss >> str) tmp.push_back(str);
        
        if(tmp[0] == "UPDATE") {
            if(tmp.size() == 4) { // r c value
                int r = stoi(tmp[1]);
                int c = stoi(tmp[2]);
                string value = tmp[3];
                
                update(r, c, value);
            }
            else { // value1 value2
                string value1 = tmp[1]; string value2 = tmp[2];
                for(int i=1; i<=50; i++) {
                    for(int j=1; j<=50; j++) {
                        pair<int, int> root = finds(i, j);
                        if(arr[root.first][root.second] == value1) {
                            arr[root.first][root.second] = value2;
                        }
                    }
                }
            }
        }
        else if(tmp[0] == "MERGE") {
            int r1 = stoi(tmp[1]); int c1 = stoi(tmp[2]);
            int r2 = stoi(tmp[3]); int c2 = stoi(tmp[4]);
            unions(r1, r2, c1, c2);
        }
        else if(tmp[0] == "UNMERGE") {
            int r = stoi(tmp[1]);
            int c = stoi(tmp[2]);
            
            unmerge(r, c);
        }
        else if(tmp[0] == "PRINT") {
            int r = stoi(tmp[1]);
            int c = stoi(tmp[2]);
            
            tie(r, c) = finds(r, c);
            if (arr[r][c].empty()) {
                answer.push_back("EMPTY");
            } else {
                answer.push_back(arr[r][c]);
            }
        }
    }
    
    return answer;
}