class Solution {
public:
    bool check (int mid, vector<int>& nums, int ops){
        for (int i = 0; i < nums.size(); i++){
            ops -= (nums[i]/mid);
            if(nums[i] % mid == 0) ops++;
        }
        return ops >= 0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;
        int end = INT_MAX;
        int ans = 0;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (check(mid,nums,maxOperations)){
                ans = mid;
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};