#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

void printIp(uint32_t ip) {

    cout << to_string((ip >> 24) & 0xFF) << ".";
    cout << to_string((ip >> 16) & 0xFF) << ".";
    cout << to_string((ip >> 8) & 0xFF) << ".";
    cout << to_string(ip & 0xFF) << endl;

}

int main() 
{
    
    cin >>N;
    
    vector<uint32_t> ips(N);

    for(int i=0;i<N;i++) {
        uint32_t ip = 0;
        string tmp_str;

        cin >> tmp_str;
        tmp_str += ".";

        int s_idx = 0;
        for (int idx=0; idx<tmp_str.length(); idx++) {
            if (tmp_str[idx] == '.') {
                string sub_str = tmp_str.substr(s_idx, idx - s_idx);
                int tmp_num = stoi(sub_str);
                ip = (ip << 8);
                ip += tmp_num;
                s_idx = idx+1;
            }
        }

        ips[i] = ip;
    }

    uint32_t mn = *min_element(ips.begin(), ips.end());
    uint32_t mx = *max_element(ips.begin(), ips.end());
    uint32_t diff = mx ^ mn; // XOR 연산으로 같으면 0, 다르면 1

    int same_idx = -1;
    for (int i=31;i>=0;i--) {
        if ((diff >> i) & 1) {
            same_idx = i;
            break;
        }
    }

    if (same_idx >= 31) {
        uint32_t network_mask = 0x00000000;
        uint32_t network_ip = mn & network_mask;
        printIp(network_ip);
        printIp(network_mask);
    }
    else {
        uint32_t network_mask = (same_idx == -1) ? 0xFFFFFFFF : ((0xFFFFFFFF) << (same_idx+1));
        uint32_t network_ip = mn & network_mask;

        printIp(network_ip);
        printIp(network_mask);
    }
    
    
    return 0;
}
