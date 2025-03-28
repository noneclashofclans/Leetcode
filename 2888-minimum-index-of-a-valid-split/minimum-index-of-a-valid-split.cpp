class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> freq;

        vector<int> split1, split2;

        int idx = -1;

        //edge case
        if (n == 0) return idx;

        // finding the max occuring element using Boyer-Moore Voting Algorithm
        int candidate = -1; int count = 0;

        for (int num : nums){
            if (count == 0) candidate = num;
            if (num == candidate){
                count += 1; // increase count value
            }
            else count -= 1; // Decrease count value
        }

        // finding the frequency of the max occuring element in nums

        int total_times = 0;

        for (int n : nums){
            if (n == candidate) total_times++;
            freq[n]++;
        }

        int leftCount = 0;

        for (int i = 0; i < n-1; i++){
            if (nums[i] == candidate) leftCount ++;

            freq[nums[i]]--;

            if (freq[nums[i]] == 0){
                freq.erase(nums[i]);
            }

            int rightCount = total_times - leftCount;

            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n-i-1)){
                return i;
            }
        }

        return idx; 
    }
};