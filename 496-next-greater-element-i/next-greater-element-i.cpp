class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;

        unordered_map<int,int> map;
        for (int i = 0; i < n2; i++){
            map[nums2[i]] = i;
        }
    
        for (int num : nums1) {
            int startIdx = map[num];
            int nextGreater = -1;

            for (int j = startIdx + 1; j < nums2.size(); j++) {
                if (nums2[j] > num) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            ans.push_back(nextGreater);
        } 
        return ans;
    }
};