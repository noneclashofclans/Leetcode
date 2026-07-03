class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool neg = (dividend < 0) ^ (divisor < 0);

        long long dvd = llabs((long long) dividend);
        long long dvs = llabs((long long) divisor);
        long long q = 0;

        while (dvd >= dvs){
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvd){
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            q += multiple;
        }

        return (neg) ? -q : q;
    }
};