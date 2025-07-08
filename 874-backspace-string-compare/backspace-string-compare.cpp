class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        // If '#' is present, then delete the previous charecter
        stack<char> x;
        stack<char> y;

         for (char ch : s) {
            if (ch == '#') {
                if (!x.empty()) x.pop();
            } else {
                x.push(ch);
            }
        }

        for (char ch : t) {
            if (ch == '#') {
                if (!y.empty()) y.pop();
            } else {
                y.push(ch);
            }
        }

        string ans1, ans2;

        while (!x.empty()){
            ans1 += x.top();
            x.pop();
        }

        while (!y.empty()){
            ans2 += y.top();
            y.pop();
        }

        return ans1 == ans2;
    }
};