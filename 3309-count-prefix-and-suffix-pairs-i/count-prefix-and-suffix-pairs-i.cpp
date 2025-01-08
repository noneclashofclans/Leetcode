class Solution {
public:
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        
        for(int i = 0; i < n; i++){
            string s1 = words[i];
            for (int j = i + 1; j < n; j++){
                string s2 = words[j];

                if (s2.length() < s1.length()) continue;

                //finding out the prefix and suffix
                string prefix = s2.substr(0,s1.length());
                string suffix = s2.substr(s2.length() - s1.length());

                if (prefix == s1 and suffix == s1) cnt ++;
            }
        }
       
        return cnt;
    }
};