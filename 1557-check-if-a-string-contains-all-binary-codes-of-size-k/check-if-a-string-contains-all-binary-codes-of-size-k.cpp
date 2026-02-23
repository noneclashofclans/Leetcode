class Solution {
public:
    bool hasAllCodes(string s, int k) {

         int n = s.size();
        if (k > n) return false;

        unordered_set<string> sett;

        int max_possible = 1 << k;    

        for (int i = 0; i <= n - k; i++){
            string str = s.substr(i, k);
            sett.insert(str);

            if (sett.size() == max_possible)
                return true;
        }

        return sett.size() == max_possible;
    }
};