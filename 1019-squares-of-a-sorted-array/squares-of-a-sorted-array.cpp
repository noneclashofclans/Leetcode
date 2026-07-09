class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 1 || nums[i] == 0) continue;
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());
        return nums;
    }
};