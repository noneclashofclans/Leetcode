class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        long long sum = 0, ans = 0;

        int l = 0;
        for (int i = 0; i < n; i++){
            freq[nums[i]]++;
            sum += nums[i];

            if (i - l + 1 > k){
                freq[nums[l]]--;

                if (freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }

                sum -= nums[l];
                l++;
            }

            if (i - l + 1 == k && freq.size() == k){
                ans = max(ans, sum);
            }
        }
        return ans;


    }
};