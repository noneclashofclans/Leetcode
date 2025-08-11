class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> freq(10,0);
        int tmp = n;
        while(tmp > 0){
            int rem = tmp % 10;
            freq[rem]++;
            tmp = tmp / 10;
        }
        for(int i = 0; i < 31; i++){
            vector<int> freq2(10,0);
            int num = pow(2,i);
            while(num > 0){
                int rem = num % 10;
                freq2[rem]++;
                num = num / 10;
            }

            bool allDigitSame = true;
            for(int i = 0; i < 10; i++){
                if (freq[i] != freq2[i]) allDigitSame = false;
            }

            if (allDigitSame) return true;
        }

        return false;
    }
};