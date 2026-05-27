class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, 1e9);

        int n = word.size();

        for (int i = 0; i < n; i++) {
            char c = word[i];

            if (c >= 'a' && c <= 'z') {
                lastLower[c - 'a'] = i;
            }
            else {
                firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != 1e9 &&
                lastLower[i] < firstUpper[i]) {
                ans++;
            }
        }

        return ans;
    }
};