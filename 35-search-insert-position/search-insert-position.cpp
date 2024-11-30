class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n;
        if (target > nums[hi -1]) return hi;
        while (lo <= hi){
            // log(n)
            int mid = (hi+lo)/2;
            if (nums[mid] == target) return mid;
            if (target > nums[mid]) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};