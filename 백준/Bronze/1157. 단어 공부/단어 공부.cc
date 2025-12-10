#include <iostream>
#include <string>

using namespace std;

int arr[27];
int res = 0;
int res_ch;

int main() 
{
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++) {
        int idx=0;
        if (str[i] >= 'A' && str[i]<='Z') idx = str[i] - 'A';
        else idx = str[i] - 'a';

        arr[idx]++;
    }
    
    for(int i=0;i<26;i++) {
        if (res <= arr[i]) {
            res =  arr[i];
            res_ch = i;
        }
    }
    
    int cnt = 0;
    for(int i=0;i<26;i++) {
        if (arr[i] == res) cnt++;
    }
    
    if (cnt > 1) cout << "?";
    else cout << (char)(res_ch + 'A');
}
