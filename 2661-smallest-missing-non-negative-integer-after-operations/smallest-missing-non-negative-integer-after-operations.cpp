class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // mex is the smallest non-negative integer
        int n = nums.size();

        vector<int> ans(value);
        for (int i = 0; i < n; i++){  
            int v = (nums[i] % value + value)%value;
            ans[v]++;
        }  


        // -3, 3, 0, 6, -1, 1    
        // -4, -5, 2, 8, 1, 3

        int mex = 0;


        while (ans[mex%value] > 0){
            ans[mex%value]--;
            mex++;
        }

        return mex;
    }
};