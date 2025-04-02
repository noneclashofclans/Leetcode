class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        int left = nums[0];
        long long res = 0;
        int maxDiff = INT_MIN;

        if (n < 3) return 0;

        for (int j = 1; j < n-1; j++){
            if (nums[j] > left) left = nums[j];
            maxDiff = max(maxDiff, left - nums[j]);
            res = max(res, (long long)maxDiff * nums[j+1]);
        }
        return res;
    }
};