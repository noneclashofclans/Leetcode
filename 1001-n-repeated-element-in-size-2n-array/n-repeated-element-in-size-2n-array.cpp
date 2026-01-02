class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mapp;

        for (auto x : nums){
            mapp[x]++;
        }

        int ans = 0;
        for (const auto [key, val] : mapp){
            if (val == n/2){
                ans = key;
                break;
            }
        }
        return ans;
    }
};