class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 0; //start from the 0th index

        long long  total_sum = 0;
        for (int num : nums){
           total_sum += num; 
        }

        long long s1 = 0, s2 = total_sum;

        while (i < n-1){
            s1 += nums[i];
            s2 -= nums[i];

            if (s1 >= s2){
                count ++; //valid split
            }

            i++;
        }
        return count;
    }
};