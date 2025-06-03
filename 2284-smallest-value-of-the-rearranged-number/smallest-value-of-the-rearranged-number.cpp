class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> digits;
        
        long long n = abs(num);

        while(n != 0){
            digits.push_back(n % 10);
            n /= 10;
        }

        if (num > 0){
            sort(digits.begin(), digits.end());

            if (digits[0] == 0){
                for (int i = 1; i < digits.size(); i++){
                    if(digits[i] != 0){
                        swap(digits[i], digits[0]);
                        break;
                    }
                }
            }
        }
        else sort(digits.begin(), digits.end(), greater<int>());

        long long res = 0;

        for (int d : digits){
            res = res * 10 + d;
        }
        
        return num > 0 ? res : -res;

        // case1: for +ve numbers, make the modified number as small as possible
        // case2: for -ve numbers make the modified number as large as u can


    }
};