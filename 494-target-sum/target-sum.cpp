class Solution {
public:
    int solve(vector<int>& nums, int target, int i){
        int n = nums.size();
        int count = 0;

        if (i == n){
            return (target == 0) ? 1 : 0;
        } 
        
        count += solve(nums, target-nums[i], i+1);
        count += solve(nums, target+nums[i], i+1);

        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        return solve(nums, target, 0);
    }
};