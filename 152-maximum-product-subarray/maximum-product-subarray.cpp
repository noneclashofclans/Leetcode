class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long leftProduct = 1;
        long rightProduct = 1;
        long ans = nums[0];

        for(int i = 0; i < n; i++){
            leftProduct = (leftProduct == 0 || leftProduct < LONG_MIN) ? 1 : leftProduct;
            rightProduct = (rightProduct == 0 || rightProduct < LONG_MIN) ? 1 : rightProduct;

            leftProduct *= nums[i];
            rightProduct *= nums[n-1-i];

            ans = max(ans,max(rightProduct,leftProduct));
        }
        return ans;
    }
};