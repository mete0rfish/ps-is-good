#include <string>
#include <vector>
#include <sstream>
#include <tuple>
#include <iostream>

using namespace std;

pair<int, int> parents[52][52];
string arr[52][52];

void after_unions(int from_r, int from_c, int to_r, int to_c) {
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=50;j++) {
            if(parents[i][j] == make_pair(from_r, from_c)) {
                parents[i][j] = make_pair(to_r, to_c);
            }
        }
    }
}

pair<int, int> finds(int r, int c) {
    if(parents[r][c] == make_pair(r, c)) return make_pair(r, c);
    return parents[r][c] = finds(parents[r][c].first, parents[r][c].second);
}

void unions(int r1, int r2, int c1, int c2) {
    tie(r1, c1) = finds(r1, c1);
    tie(r2, c2) = finds(r2, c2);
    
    if(!arr[r1][c1].empty() && !arr[r2][c2].empty()) {
        parents[r2][c2] = make_pair(r1, c1);
        after_unions(r2, c2, r1, c1);
    }
    else if(!arr[r1][c1].empty()) {
        parents[r2][c2] = make_pair(r1, c1);
        after_unions(r2, c2, r1, c1);
    }
    else {
        parents[r1][c1] = make_pair(r2, c2);
        after_unions(r1, c1, r2, c2);
    }
}

void updates(int R, int C, string VALUE) {
    tie(R, C) = finds(R, C);
    arr[R][C] = VALUE;
}

void updates_with_value(string VALUE1, string VALUE2) {
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=50;j++) {
            int pi, pj;
            tie(pi, pj) = finds(i, j);
            if(arr[pi][pj] == VALUE1) updates(i, j, VALUE2);
        }
    }
}

void unmerges(int R, int C) {
    int ori_R = R; int ori_C = C;
    tie(R, C) = finds(R, C);
    string VALUE = arr[R][C];
    
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=50;j++) {
            if(parents[i][j] == make_pair(R, C)) {
                parents[i][j] = make_pair(i, j);
                arr[i][j].clear();
            }
        }
    }
    
    arr[ori_R][ori_C] = VALUE;
}

void print(vector<string>& answer, int R, int C) {
    tie(R, C) = finds(R, C);
    
    if(arr[R][C] == "") {
        answer.push_back("EMPTY");
    }
    else {
        answer.push_back(arr[R][C]);
    }
}

void slices(vector<string>& params, string command) {
    stringstream ss(command);
    string str;
    while(ss >> str) {
        params.push_back(str);
    }
}

void init() {
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            parents[i][j] = make_pair(i, j);
        }
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    init();
    for(auto command : commands) {
        vector<string> params;
        slices(params, command);
        
        if(params[0] == "UPDATE") {
            if(params.size() == 4) {
                int R = stoi(params[1]);
                int C = stoi(params[2]);
                string VALUE = params[3];
                
                updates(R, C, VALUE);
            }   
            else {
                string VALUE1 = params[1];
                string VALUE2 = params[2];
                
                updates_with_value(VALUE1, VALUE2);
            }
        }
        else if(params[0] == "MERGE") {
            int R1 = stoi(params[1]); int C1 = stoi(params[2]);
            int R2 = stoi(params[3]); int C2 = stoi(params[4]);
            
            unions(R1, R2, C1, C2);
        }
        else if(params[0] == "UNMERGE") {
            int R = stoi(params[1]);
            int C = stoi(params[2]);
            
            unmerges(R, C);
        }
        else if(params[0] == "PRINT") {
            int R = stoi(params[1]);
            int C = stoi(params[2]);
            
            print(answer, R, C);
        }
    }
    
    return answer;
}