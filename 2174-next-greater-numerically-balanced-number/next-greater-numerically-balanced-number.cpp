class Solution {
public:
    const int range = 1e7;

    bool satisfies(int n){
        map<int, int> freq;
        while (n > 0){
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int digit = it->first;
            int count = it->second;
            if (digit != count) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        /*
            the number is numerically balanced if for every digit 'd', its 
            occurence is exactly 'd'

            the starting point would be 'n'
        */

        for (int i = n + 1; i <= range; i++){
            if (satisfies(i)) return i;
        }
        return -1;
    }
};