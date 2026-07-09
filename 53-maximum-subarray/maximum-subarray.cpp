class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
     

        int maxSum = INT_MIN;
        int csum = 0;

        for(int i = 0; i < n; i++){
            csum = max(csum + nums[i], nums[i]);
            maxSum = max(maxSum, csum);
        }

        return maxSum;
    }
};