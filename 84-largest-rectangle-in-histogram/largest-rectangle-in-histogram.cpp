class Solution {
public:
    pair<int,int> someInfo(vector<int>& heights){
         int n = heights.size();
        // find the breakpoint, or the index, where no more greater element is present
        int max = INT_MIN, idx = -1;
        for (int i = 0; i < n; i++){
            if (heights[i] > max){
                max = heights[i];
                idx = i;
            }
        }
        return {max, idx};
    }
    int largestRectangleArea(vector<int>& heights) {
        // array has height given and breadth is 1
        int n = heights.size();
        int ans = 0;

        stack<int> st;
        pair<int,int> p = someInfo(heights); // 6, 3

        for (int i = 0; i <= n; i++){
            int curr = (i == n ? 0 : heights[i]);

            while (!st.empty() && curr < heights[st.top()]){
                // get the top height of the stack
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }  
        return ans;  
    }
};