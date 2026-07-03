class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> freq;

        int stop_idx = 0;

        while (stop_idx + 10 <= (int)s.size()) {
            string temp = "";

            for (int i = stop_idx; i < stop_idx + 10; i++) {
                temp += s[i];
            }

            freq[temp]++;
            stop_idx++;
        }

        for (auto &p : freq) {
            if (p.second > 1) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};