class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       int n = nums.size();

       // finding the subarray whose size is between l and r (inclusive) and 
       // we need to find the min sum of the subarrays from all possible subarrays

       int min_s = INT_MAX;
       vector<int> prefix(n + 1, 0);
       for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
       }

        for (int i = l; i <= r; i++){
            for (int j = 0; j + i <= n; j++){
                int sum = prefix[i + j] - prefix[j];
                if (sum > 0 && sum < min_s) min_s = sum;
            }
        }

        return min_s == INT_MAX ? -1 : min_s;
    }
};