class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> st;  
        int n = s.size();
        unordered_set<int> trash;

        for (int i = 0; i < n; i++){
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')'){
                if (!st.empty()){
                   st.pop(); 
                }
                else trash.insert(i);
            }
        }
        // remaining '(' that haven't been able to match
        while (!st.empty()){
            int top = st.top();
            trash.insert(top);
            st.pop();
        }

        for (int i = 0; i < n; i++){
            if (trash.find(i) == trash.end()){
                ans += s[i];
            }
        }
        return ans;
    }
};