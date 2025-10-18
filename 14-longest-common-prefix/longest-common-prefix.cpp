class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        stack<string> st;
        for (string s : strs){
            st.push(s);
        }

        // string top = "";
        // bool flag = true;

        // while (!st.empty()){
        //     top = st.top();
        //     st.pop();
            
        //     string next = st.top();
        //     st.pop();

        //     int n = top.size();
        //     int m = next.size();

        //     int i = 0, j = 0;

        //     while(i < n && j < m){
        //         if (top[i] != next[j]){
        //             flag = false;
        //             break;
        //         }
        //         else {
        //             ans += top[i];
        //             i++; j++;
        //         }
        //     }

        //     if (flag == false) break;
        // }

        string ans = st.top();
        st.top();

        while (!st.empty()){
            string curr = st.top();
            st.pop();

            int len = min(ans.size(), curr.size());
            int i = 0;
            while (i < len && ans[i] == curr[i]) i++;

            ans = ans.substr(0, i);
            if (ans.empty()) return "";
        }

        return ans;
    }
};