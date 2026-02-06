class Solution {
public:
    #define ll long long
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxlen = 0;
        int l = 0;
        // max_element <= k * min_element
        // stack<int> st;

        for (int r = 0; r < n; r++){
            // while (!st.empty() && (ll)nums[r] > (ll)k*st.top()){
            //     st.pop();
            //     l++;
            // }
            while (l <= r && (ll)nums[r] > k * (ll)nums[l]) l++;
            // st.push(nums[r]);
            maxlen = max(maxlen, r - l + 1);
        }
        return n - maxlen;
    }
};