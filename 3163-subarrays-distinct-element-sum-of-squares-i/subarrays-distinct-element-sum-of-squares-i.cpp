class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                set<int> sett;
                for (int k = i; k <= j; k++){
                    sett.insert(nums[k]);
                }
                ans += sett.size() * sett.size();
            }
        }
        return ans;
    }
};