class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 2) return nums;
        vector<int> even;
        vector<int> odd;

        for (int i = 0; i < n; i++){
            if(i % 2 == 0){// an even idx
                even.push_back(nums[i]);
            }
            else odd.push_back(nums[i]);
        }

        // sorting based on the condition
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());

        // merging back in the original array
        int evenIdx = 0, oddIdx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                nums[i] = even[evenIdx++];
            } else {
                nums[i] = odd[oddIdx++];
            }
        }
        return nums;
    }
};