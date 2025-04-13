class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9 + 7;
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        //edge cases;
        if (n == 0) return 0; 
        if (n == 1) return 5;
        
        long long pow5 = power(5, even, mod);
        long long pow4 = power(4, odd, mod);
        
        return (int)((pow5 * pow4) % mod);
    }

private:
    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};