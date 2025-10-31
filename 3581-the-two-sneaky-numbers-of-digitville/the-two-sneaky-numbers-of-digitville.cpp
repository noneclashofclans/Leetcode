class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;

        map<int,int> freq;
        for (int x : nums){
            freq[x]++;
        }

        for (const auto& p : freq){
            int ele = p.first;
            int count = p.second;

            if (count > 1){
                ans.push_back(ele);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};