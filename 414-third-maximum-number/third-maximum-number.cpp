class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //to return the third distinct max. number
        int n = nums.size();
        unordered_map<int,int> freq;

        if (n <= 2) return *max_element(nums.begin(),nums.end());

        unordered_set<int> set;

        for (int num : nums) set.insert(num);//distinct elements are added

        if (set.size() < 3) return *max_element(nums.begin(),nums.end());

        vector<int> ans(set.begin(),set.end()); //store set values

        sort(ans.begin(),ans.end(),greater<int>());

        return ans[2];
    }
};