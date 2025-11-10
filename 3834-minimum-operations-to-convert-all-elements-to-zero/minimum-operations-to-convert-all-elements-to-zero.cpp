class Solution {
public:
    int minOperations(vector<int>& nums) {
        // int n = nums.size();
        // // we need to operate in min to max order wise
        // int maxops = INT_MIN;
        // int ops = 0;
        // int i = 0;
        // for (int j = i; j < n && i < n;){
        //     if (nums[j] == 0) continue;
        //     int ele = nums[j];
        //     if (j + 1 < n && nums[j+1] == ele) {
        //         continue; 
        //     } 
        //     else {
        //         i++;
        //         for (int k = i; k <= j; k++) {
        //             nums[k] = 0;
        //         }
        //         ops++;
        //         maxops = max(maxops, ops);
        //     }
        // }
        // return maxops - 1;

        int ans = 0;
        stack<int> st;
        st.push(0);
        for (int num : nums) {
            while (!st.empty() && st.top() > num) {
                st.pop();
            }
            if (st.empty() || st.top() < num) {
                ans++;
                st.push(num);
            }
        }
        return ans;
    }
};