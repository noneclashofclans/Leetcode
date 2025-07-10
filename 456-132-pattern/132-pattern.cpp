class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 132 pattern: 
        // i < j < k and nums[i] < nums[k] < nums[j]
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;
        int j = INT_MIN;
        for (int i = n-1; i >= 0; i--){
            if (nums[i] < j) return true;
            while (!st.empty() && st.top() < nums[i]){
                j = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }
        return false;
    }
};