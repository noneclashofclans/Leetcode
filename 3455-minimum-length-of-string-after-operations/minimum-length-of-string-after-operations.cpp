class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if (n < 3) return n;
        int len = 0;
        vector<int> freq(26);

        for (char c: s){
            freq[c - 'a']++;
        }
        
        for (int f : freq){
            if (f == 0) continue;
            if (f % 2 == 0) len += 2;
            else len ++;
        }
        return len;   
    }
};