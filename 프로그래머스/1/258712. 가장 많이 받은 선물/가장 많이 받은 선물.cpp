#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int jisu[51];
map<string, int> m;
int arr[51][51];
int recv[51];
int send[51];
int ress[51];

int solution(vector<string> friends, vector<string> gifts) {
    int N = friends.size();
    for(int i=0;i<friends.size();i++) {
        m[friends[i]] = i;
    }
    
    for(auto gift : gifts) {
        int split = gift.find(" ");
        string from = gift.substr(0,split);
        string to = gift.substr(split+1);

        arr[m[from]][m[to]]++;
        send[m[from]]++;
        recv[m[to]]++;
    }
    
    for(int i=0;i<N;i++) {
        jisu[i] = send[i] - recv[i];
        cout << i << ": " << jisu[i] << "\n";
    }
    
    
    for(int from=0;from<N-1;from++) {
        for(int to=from+1;to<N;to++) {
            // 주고 받은 기록이 없다.
            if(!arr[from][to] && !arr[to][from]) {
                if(jisu[from] > jisu[to]) {
                    ress[from]++;
                }   
                else if(jisu[from] < jisu[to]) {
                    ress[to]++;
                }
            }
            // 주고 받은 기록이 있다.
            else {
                if(arr[from][to] == arr[to][from]) {
                    if(jisu[from] > jisu[to]) {
                        ress[from]++;
                    }   
                    else if(jisu[from] < jisu[to]) {
                        ress[to]++;
                    }
                }
                else {
                    (arr[from][to] > arr[to][from]) ? ress[from]++ : ress[to]++; 
                }
            }
        }
    }
    
    int res = 0;
    for(int i=0;i<N;i++) {
        res = max(res, ress[i]);
    }
    return res;
}