class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> idx;

        for (int i = 0; i < n; i++){
            idx.push_back({nums[i], i});
        }
        // sort with descending values
        sort(idx.begin(), idx.end(), [&](auto a, auto b){
            return a.first > b.first;
        });

        vector<pair<int,int>> topK(idx.begin(), idx.begin()+k);
        // sort topK elements to preserve original order
        sort(topK.begin(), topK.end(), [&](auto a, auto b){
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &[val, idx] : topK) {
            ans.push_back(val);
        }

        return ans;
    }
};