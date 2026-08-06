class Solution {
public:

    int digitProduct(int n){
        int product = 1;
        while (n > 0){
            int last_digit = n % 10;
            if (last_digit == 0) return 0;
            product = product * last_digit;
            n = n / 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        while (true){
            int p = digitProduct(n);
            if (p % t == 0) return n;
            else n++;
        }
    }
};