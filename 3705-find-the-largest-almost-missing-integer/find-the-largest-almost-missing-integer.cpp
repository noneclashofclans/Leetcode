class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> count;

        for (int i = 0; i < n - k + 1; i++){
            set<int> sett;
            int j = i;
            while (j < k+i){
                sett.insert(nums[j]);
                j++;
            }

            for (int x : sett){
                count[x]++;
            }
        }

        int ans = -1;
        for (auto x : count) {
            if (x.second == 1) {
                ans = max(ans, x.first);
            }
        }

        return ans;
    }
};