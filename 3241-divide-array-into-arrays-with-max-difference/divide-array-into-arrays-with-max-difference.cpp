class Solution {
public:
    // int diff(int a, int b){
    //     return abs(a - b);
    // }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        // [1,3,4,8,7,9,3,5,1] (on sort) -> [1,1,3,3,4,5,7,8,9]
        // int i = 0;
        // while (i < n){
        //     vector<int> temp;
        //     for (int j = 1; j <= n/3; j++){
        //         if (nums[i] == nums[j]) i++;
        //         if(diff(nums[i], nums[j]) <= k){
        //             temp.push_back(nums[i]);
        //             temp.push_back(nums[j]);   
        //         }
        //     }
        //     ans.push_back(temp);
        //     i++;

        for (int i = 0; i < n; i+=3){
            if (nums[i+2] - nums[i] > k){
                return {};
            }
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};