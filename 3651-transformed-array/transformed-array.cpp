class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);

        int i = 0;
        while (i < n){
            if (nums[i] == 0){
                res[i] = 0;
            }
            else{
                int jump = nums[i] % n;
                int newIdx = (i + jump + n) % n;
                res[i] = nums[newIdx];
            }
            i++;
        }
        return res;
    }
};