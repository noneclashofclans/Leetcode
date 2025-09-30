class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> new_nums(n-1);

        for (int i = 0; i < n-1; i++){
            new_nums[i] = ((nums[i] + nums[i+1])%10);
        }

        return solve(new_nums);

    }
    
    int triangularSum(vector<int>& nums) {
        return solve(nums);
    }
};