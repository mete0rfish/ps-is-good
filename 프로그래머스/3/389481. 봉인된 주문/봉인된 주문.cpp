#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

/*
a b c d e ... z
1 2 3 4 5 ... 26
26*(str[0]-'a')+26*(str[1]-'a')+(str[2]-'a'+1)

int cnt = 0;
for(int i=0;i<str.length();i++) {
    cnt += pow(26, str.length()-i-1) * (str[i]-'a'+1);
}

int cnt = 1;
int res = 0;
while(t >= 26) {
    int a = t/26;
    int b = t%26;
    
    v.push_back('a'+b-1);
    
    t = a;
}

27 -> 26*(27/26) + (27-26)
703 -> 26*(703/26=27)
(26*26*1)+(26*1)+1
703/26 = 27 ... 1
27/26 = 1 ... 1

1 -> 1/26 = 0 ... 1

729/26 = 28 ... 2

a
1

aa   
(26*1)+1 
ab
26*1+2
ba
26*2+1
za
26*26+1
zz
26*26+26
aaa
(26*26*1)+(26*1)+1
aab
(26*26*1)+(26*1)+2
aaz
(26*26*1)+(26*1)+26
aba
(26*26*1)+(26*2)+1

jxk
26*26*10+
aaaa
(26*26*26)+(26*26)+26+1 = 18279
18279/26=703 ... 1 -> sqrt(703) = 26
703/26=27 ... 2
27/26=1 ... 3
*/
bool cmp(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

long long convert(string target) {
    long long cnt = 0;
    long long power_of_26 = 1;
    for (int i = target.length() - 1; i >= 0; i--) {
        cnt += (target[i] - 'a' + 1) * power_of_26;
        power_of_26 *= 26;
    }
    return cnt;
}

string solution(long long n, vector<string> bans) {
    sort(bans.begin(), bans.end(),cmp);
    
    int cnt = 0;
    int tmp = n;
    for(int j=0;j<bans.size();j++){
        long long target = convert(bans[j]);
        if(target <= n)  {
            n++;
        }
    }

    
    string res = "";
    long long t = n;
    while(t > 0) {
        int b = t % 26;

        if (b == 0) {
            res += 'z';
            t = (t / 26) - 1;
        } else {
            res += char('a' + b - 1);
            t = t / 26;
        }
    }
    
    reverse(res.begin(), res.end());
    return res;
}