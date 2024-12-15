class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int s = 0;

        int mn = INT_MAX;

        while (j < n){
            s += nums[j];
            while (s >= target){
                s-=nums[i];
                mn = min(j-i+1,mn);
                i++;
            }
            j++;
        }
        if (mn == INT_MAX){
            return 0;
        }
        return mn;
    }
};