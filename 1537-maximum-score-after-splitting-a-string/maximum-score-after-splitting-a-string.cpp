class Solution {
public:
    int maxScore(string s) {
        int maxScore =0;
        int n = s.size();

        if (n == 0)return maxScore;

        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < n; i++){
            if (s[i] == '1') ones ++;
        }

        for (int i = 0; i < n -1; i++){ //move only till the second last digit
            if (s[i] == '0') zeros ++;
            else ones--;

            maxScore = max(maxScore,ones+zeros);
        }
        return maxScore;
    }
};