class Solution {
public:
    bool check(vector<int>& nums){
        int n = nums.size();
        bool is_increasing = true;
        bool is_decreasing = true;
        for(int i = 0; i < n-1; i++){
            if(nums[i] >= nums[i+1])
                is_increasing = false;

            if(nums[i] <= nums[i+1])
                is_decreasing = false;
        }
        return is_increasing || is_decreasing;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = INT_MIN;
        for (int i = 0; i < n; i++){
            vector<int> temp;
            for (int j = i; j < n; j++){
                temp.push_back(nums[j]);
                if(check(temp)) maxLen=max(maxLen,(int)temp.size());
            }
        }
        return maxLen;
    }
};