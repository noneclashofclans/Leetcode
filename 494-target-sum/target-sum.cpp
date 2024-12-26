class Solution {
public:
    int countways (vector<int> &nums, int idx, int target){
        if (idx == nums.size()){
            return target == 0 ? 1 : 0;
        }
        int add = countways (nums, idx + 1, target+nums[idx]);
        int sub = countways(nums, idx + 1, target-nums[idx]);

        return add + sub;
    } 
    int findTargetSumWays(vector<int>& nums, int target) {
       return countways(nums,0,target);
    }
};