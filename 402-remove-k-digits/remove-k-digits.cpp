class Solution {
public:
    string removeKdigits(string num, int k) {
        // vector<int> ans;
        // int number = stoi(num);
        // vector<int> a;
        // while (number != 0){
        //     int ld = number % 10;
        //     a.push_back(ld);
        //     number /= 10;
        // }
        // // base case:
        // if (a.size() == k) return "0";
        // // "1432219"
        // reverse(num.begin(), num.end());
        // // "9122341"
        
        //     stack<int> st;

        // for (int i = 0; i < a.size(); i++) st.push(num[i]);
        // // [9 1 2 2 3 4 1] -> stack
        // int count = 0;
        // while (!st.empty()){
        //     int top = st.top();
        //     st.pop(); // [9 1 2 2 3 4], top = 1
        //     int newTop = st.top();
        //     if (top < newTop){
        //         st.pop(); 
        //         count++;
        //         if (count > k) break;
        //         st.push(top); // [9 1 2 2 3 1]       
        //     }
        // }
        // while (!st.empty()){
        //     int tp = st.top();
        //     st.pop();
        //     ans.push_back(tp);
        // }
        // string res = "";
        // for(int n : ans){
        //     res += n;
        // }
        // return res;

        int n = num.size();
        string ans = "";
        int count = 0;
        stack<char> st;
        for (int i = 0; i < n; i++){
            char current_char = num[i];

            while (!st.empty() && k > 0 && current_char < st.top()){
                st.pop();
                k--;
            }
            st.push(current_char);
        }

        // removing the remaining digits
        while (k-- > 0 && !st.empty()) {
            st.pop();
        }

        while (!st.empty()){
            char top_char = st.top();
            st.pop();
            ans += top_char;
        }
        reverse(ans.begin(), ans.end());
        
        // removing leading 0's
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};