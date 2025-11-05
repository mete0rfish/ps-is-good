#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool func1(int x, int y, int r1) {
    return (x*x) + (y*y) >= (r1*r1);
}

bool func2(int x, int y, int r2) {
    return (x*x) + (y*y) <= (r2*r2);
}

long long solution(int r1, int r2) {
    long long answer=0;
    for(int i=1;i<=r2;i++) {
		// int minY = ceil(sqrt((long long)r1 * r1 - (long long)i * i));
		// int maxY = floor(sqrt((long long)r2 * r2 - (long long)i * i));

        int minY = ceil(sqrt((long long)r1*r1 -(long long)i*i));
        int maxY = floor(sqrt((long long)r2*r2 -(long long)i*i));
        if(r1 < i) minY = 0;
        answer += (maxY - minY+1);
    }
    answer *=4;
    return answer;
}