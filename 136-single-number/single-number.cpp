class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans = 0;
       for (int n : nums){
         ans = ans ^ n;
       }
       return ans;
    }
};