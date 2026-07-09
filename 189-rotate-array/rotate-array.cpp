class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n; // to prevent overflow

        reverse(nums.begin(), nums.end());
        // 7, 6, 5, 4, 3, 2, 1
        reverse(nums.begin(), nums.begin()+k);
        // 5, 6, 7, 4, 3, 2, 1
        reverse(nums.begin()+k, nums.end());
        

        // 5, 6, 7, 1, 2, 3, 4   
    }
};