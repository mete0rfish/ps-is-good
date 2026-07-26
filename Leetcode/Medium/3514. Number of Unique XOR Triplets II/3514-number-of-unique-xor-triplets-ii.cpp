class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        int limit  =1;
        while (limit <= mx) {
            limit <<= 1;
        }

        vector<bool> pairs(limit, false);
        for (int a : nums) {
            for (int b : nums) {
                pairs[a^b] = true;
            }
        }

        vector<bool> tuples(limit, false);
        for (int i=0;i<limit;i++) {
            if (!pairs[i]) continue;

            for (int c : nums) {
                tuples[i ^ c] = true;
            }
        }

        int cnt = 0;
        for (int i=0; i<limit;i++) {
            if (!tuples[i]) continue;

            cnt++;
        }

        return cnt;
    }
};