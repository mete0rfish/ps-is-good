#include <string>
#include <vector>
#include <cmath>

using namespace std;

int in[1000001];
int out[1000001];

vector<int> solution(vector<vector<int>> edges) {
    int tot_graph = 0;
    int added=0, eight=0, stick=0;
    int node_size = 0;
    for(auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        node_size = max(node_size, max(a, b));
        
        out[a]++;
        in[b]++;
    }
    
    for(int i=1;i<=node_size;i++) {
        if(in[i] == 0 && out[i] >= 2) {
            added = i;
            tot_graph = out[i];
        }
        else if(in[i] >= 1 && out[i] == 0) {
            stick++;
        }
        else if(in[i] >= 2 && out[i] == 2) {
            eight++;
        }
    }
    
    vector<int> answer;
    answer.push_back(added);
    answer.push_back(tot_graph - eight - stick);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}