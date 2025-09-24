class Solution {
public:
    void rotate_arr(vector<int>& nums, int s, int e){
        while (s <= e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        rotate_arr(nums, 0, n-1);
        rotate_arr(nums, 0, k-1);
        rotate_arr(nums, k, n-1);
    }
};