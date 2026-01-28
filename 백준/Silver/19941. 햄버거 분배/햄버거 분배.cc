#include <vector>
#include <iostream>

using namespace std;

bool vst[20001];

int solution(int n, int k, string str) {
    int answer=0;

    for (int i=0;i<str.length();i++) {
        if (str[i] == 'P') {

            for (int j=-k;j<=k;j++) {
                int idx = i+j;
                if(idx < 0) idx = 0;

                if(idx >= n) continue;
                if(vst[idx]) continue;
                if(str[idx] == 'P') continue;

                vst[idx] = true;
                answer++;

                break;
            }

        }
    }

    return answer;
}

int main() 
{
    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;

    cout << solution(n,k,str);

    return 0;
}
