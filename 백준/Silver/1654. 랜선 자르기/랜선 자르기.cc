#include <iostream>
#include <algorithm>

using namespace std;

long long k,n;

int main()
{

	cin >> k >> n;
	long long arr[k];
	
	for(int i=0;i<k;i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+k);
	
	long long low = 1;
	long long high = arr[k-1];
	long long mid;
	long long ans=0;
	
	while(high-low>=0){
		long long cnt =0;
		mid = (low + high) / 2;
		
		for(int i=0;i<k;i++){
			cnt += arr[i]/mid;
		}
		if(cnt >= n){
			low = mid + 1;
			if(ans < mid){
				ans = mid;
			}
		}
		else{
			high = mid -1;
		}
		
	}
	
	cout << ans;
    return 0;
}