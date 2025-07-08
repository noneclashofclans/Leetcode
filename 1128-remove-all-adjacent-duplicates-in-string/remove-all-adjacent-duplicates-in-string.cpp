class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();

        stack<char> st;

        for (int i = 0; i < n; i++){
            char ele = s[i];

            if (!st.empty() && st.top() == ele){
                st.pop();
            }
            else st.push(ele);
        }
        
        string ans;

        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse (ans.begin(), ans.end());

        return ans;
    }
};