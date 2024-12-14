class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> freq(0);
        vector<int> ans;

        for (int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        for(auto el : freq){
            int element = el.first;
            int cnt = el.second;

            if(cnt > n/3){
                ans.push_back(element);
            }
        }
        return ans;
    }
};