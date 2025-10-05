class Solution {
public:
    int solve(vector<int>& nums, int target, int i, vector<unordered_map<int,int>>&memo){
        int n = nums.size();
        int count = 0;

        if (i == n){
            return (target == 0) ? 1 : 0;
        } 

        if (memo[i].find(target) != memo[i].end()) return memo[i][target];
        
        count += solve(nums, target-nums[i], i+1, memo);
        count += solve(nums, target+nums[i], i+1, memo);

        return memo[i][target] = count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> memo(nums.size());
        return solve(nums, target, 0, memo);
    }
};