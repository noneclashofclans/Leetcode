class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int maxGap = 0;
        if (n <= 1) return maxGap;

        sort(nums.begin(),nums.end());

        int current_gap = 0;

        for(int i = 1; i < n; i++){
            current_gap = nums[i] - nums[i-1];
            maxGap = max(current_gap,maxGap);
        }
        return maxGap;
    }
};