#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 51000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> sums(MAX_SIZE, 0);
    vector<int> starts(MAX_SIZE, 0);
    vector<int> ends(MAX_SIZE, 0);

    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        sums[s]++;
        sums[e + 1]--;
        
        starts[s]++;
        ends[e]++;
    }

    for (int i = 1; i < MAX_SIZE; ++i) {
        sums[i] += sums[i - 1];
    }

    long long max_area = 0;
    long long tapes = 0;
    int min_s = 1e9;

    for (int s = 1; s < 50001; ++s) {
        if (s + (n * 7) >= MAX_SIZE) {
            break;
        }

        long long area = 0;
        long long t = 0;

        for (int i = 0; i < n; ++i) {
            int idx = s + (i * 7);
            for (int j = 0; j < 7; ++j) {
                area += sums[idx + j];
                t += ends[idx + j];

                if (j == 6) {
                    t += sums[idx + j + 1] - starts[idx + j + 1];
                }
            }
        }
        
        if (area > max_area) {
            max_area = area;
            min_s = s;
            tapes = t;
        } else if (area == max_area) {
            if (min_s > s) {
                min_s = s;
                tapes = t;
            }
        }
    }

    cout << tapes;

    return 0;
}