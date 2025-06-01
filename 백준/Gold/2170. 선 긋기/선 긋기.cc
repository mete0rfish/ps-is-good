#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 길이, 주소
vector<pair<long long, long long>> pairSet;
vector<pair<long long, long long>> resVector;
long long smallest = 1000000001;
long long biggest = -1000000001;
// long long occupied[1000000001]; 너무 커서 안됨.
long long sum = 0;

long long n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;

		pairSet.push_back({ a,b });
	}

	sort(pairSet.begin(), pairSet.end());

	// setting

	long long prevA = pairSet[0].first;
	long long prevB = pairSet[0].second;

	for (int i = 1; i < n; i++) {
		pair<long long, long long> currPos = pairSet[i];
		long long currA = currPos.first;
		long long currB = currPos.second;

		if (prevB < currA) {
			resVector.push_back({ prevA, prevB });
		}
		else {
			currA = min(currA, prevA);
			currB = max(currB, prevB);
		}

		if (i == n - 1) {
			
		}

		prevA = currA;
		prevB = currB;
	}

	resVector.push_back({ prevA, prevB });

	for (int i = 0; i < resVector.size(); i++) {
		//printf("%lld %lld : %lld\n", resVector[i].first, resVector[i].second, (resVector[i].second - resVector[i].first));
		sum += (resVector[i].second - resVector[i].first);
	}
	cout << sum;
}