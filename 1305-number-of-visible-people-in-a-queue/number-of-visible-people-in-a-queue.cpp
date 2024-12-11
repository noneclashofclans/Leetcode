class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n , 0);

        stack<int> st;
        st.push(arr[n-1]);
        arr[n-1] = 0;

        for (int i = n-2; i >= 0; i--){
            int cnt = 0;
            while (st.size() > 0 && arr[i] > st.top()){
                st.pop();
                cnt++;
            }
            if (st.size() > 0) cnt++; // v.imp
            ans[i] = cnt;
            st.push(arr[i]);
        }
        return ans;
    }
};