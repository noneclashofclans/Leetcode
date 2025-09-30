class Solution {
public:
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>& dp){
        if (i == 0) return nums[j];

        if (dp[i][j] != -1) return dp[i][j];

        int left = solve(i-1, j, nums, dp);
        int right = solve(i-1, j+1, nums, dp);

        return dp[i][j] = (left + right) % 10;

    }

    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(n-1, 0, nums, dp);
    }
};