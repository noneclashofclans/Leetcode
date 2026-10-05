class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        
        stack<int> st;
        st.push(0);

        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                st.push(0);
            }
            
            else{
                int inner_score = st.top();
                st.pop();

                int current_score =0;
                if (inner_score == 0){
                    current_score = 1;
                }
                else{
                    current_score = 2 * inner_score;
                }
                st.top() += current_score;
            }
        }
        return st.top();
    }
};