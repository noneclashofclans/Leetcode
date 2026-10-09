class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int n = s.size();   

        stack<char> st;

        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                st.push('(');
            }
            else{
                if (i + 1 < n && s[i+1] == ')'){
                    if (st.empty()){
                        ans++;
                    }
                    else{
                        st.pop();
                    }
                    i++;
                }
                else{
                    ans++;
                    if (st.empty()) ans++;
                    else st.pop();
                }
            }
        }

        ans += 2 * st.size();

        return ans;
    }
};