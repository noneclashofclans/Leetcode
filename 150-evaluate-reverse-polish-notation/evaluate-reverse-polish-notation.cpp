class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> st;

        for (const string& s : tokens){
            int top1, top2;
            // in reverse polish notation, the operation is top2 op top1
            if (s == "+"){
                if (!st.empty()){
                    top1 = (st.top()); st.pop(); 
                    top2 = (st.top()); st.pop();
                }
                ans = top1 + top2;
                st.push(ans);
            }
            else if (s == "-"){
                if (!st.empty()){
                     top1 = (st.top()); st.pop(); 
                     top2 = (st.top()); st.pop();
                }
                ans = top2 - top1;
                st.push(ans);
            }
            else if (s == "*"){
                if (!st.empty()){
                     top1 = (st.top()); st.pop(); 
                     top2 = (st.top()); st.pop();
                }
                ans = top1 * top2;
                st.push(ans);
            }
            else if (s == "/"){
                if (!st.empty()){
                     top1 = (st.top()); st.pop(); 
                     top2 = (st.top()); st.pop();
                }
                ans = top2 / top1;
                st.push(ans);
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};