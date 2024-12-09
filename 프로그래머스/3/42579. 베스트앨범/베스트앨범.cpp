#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

bool cmp2(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, vector<pair<int,int>>> m; // genres : {play_count, index}
    map<string, int> count_m;
    int len = genres.size();
    
    for(int i=0;i<len;i++) {
        string genre = genres[i];
        int play_count = plays[i];
        m[genre].push_back({play_count, i});
        count_m[genre]+=play_count;
    }
    
    vector<pair<string, int>> count_v(count_m.begin(), count_m.end());
    sort(count_v.begin(), count_v.end(), cmp2);
    
    vector<int> ans;
    
    len = count_v.size();
    for(int i=0;i<len;i++) {
        string genre = count_v[i].first;
        sort(m[genre].begin(), m[genre].end(), cmp);
        
        for(int j=0;j<m[genre].size() && j < 2;j++) {
            ans.push_back(m[genre][j].second);
        }
    }
    return ans;
}