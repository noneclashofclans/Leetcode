class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l = *max_element(nums.begin(), nums.end());
        int s = *min_element(nums.begin(), nums.end());

        vector<int> ans;

        unordered_set<int> mp(nums.begin(), nums.end());
        
        for (int i = s; i <= l; i++){
            if (mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};