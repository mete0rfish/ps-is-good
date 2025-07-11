#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
string str;

int main() {
    cin >> T;
    while(T--) {
        vector<string> arr;

        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> str;
            arr.push_back(str);
        }

        sort(arr.begin(), arr.end());

        map<string, int> m;
        bool flag = false;
        for(int i=0;i<N;i++) {
            string tmp = "";
            for(int j=0;j<arr[i].length();j++) {
                tmp += arr[i][j];
                if(m[tmp]!=0) {
                    flag = true;
                    break;
                }
            }
            
            if(flag) break;
            m[tmp]++;
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}