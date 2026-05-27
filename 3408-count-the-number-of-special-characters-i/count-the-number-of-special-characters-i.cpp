class Solution {
public:
    int numberOfSpecialChars(string s) {
        set<char> lower, upper;

        for(char c : s) {
            if(c >= 'a' && c <= 'z')
                lower.insert(c);
            else if(c >= 'A' && c <= 'Z')
                upper.insert(c);
        }

        int ans = 0;

        for(char c : lower) {
            if(upper.count(c - 32)) {
                ans++;
            }
        }

        return ans;
    }
};