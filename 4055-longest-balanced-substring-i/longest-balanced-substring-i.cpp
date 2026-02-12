class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        //  "abbac" 
        //  "zzabccy"

        int ans = 0;

        for (int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            int distinct_char = 0;
            int max_frequency = 0;

            for (int j = i; j < n; j++){
                int idx = s[j]-'a';
                
                if (freq[idx] == 0) distinct_char++;

                freq[idx]++;
                max_frequency = max(max_frequency, freq[idx]);

                int subarr_length = j-i+1;

                if (subarr_length == distinct_char*max_frequency)
                    ans = max(ans, subarr_length);
            }
        }
        return ans;
    }
};