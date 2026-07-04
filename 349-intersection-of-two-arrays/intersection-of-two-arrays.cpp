class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        unordered_set<int> sett1;
        for(int x : nums1){ sett1.insert(x); }
        
        unordered_set<int> sett2;
        for(int x : nums2){ sett2.insert(x); }
        
        for(int x : sett1){
            if (sett2.count(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};