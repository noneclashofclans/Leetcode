class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int count_of_subsequences = 1; // atleast one group in mandatory
        // 3,6,1,2,5

        sort (nums.begin(), nums.end());
        int start = nums[0];
        // 1,2,3,5,6
        
        for(int i = 1; i < n; i++){
            if (nums[i] - start > k){
                count_of_subsequences++;
                start = nums[i];
            }
        }
                                    
        return count_of_subsequences;
    }
};