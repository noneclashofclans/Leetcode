class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;

        /*
            'PARTS'
        
            part = 1,2,3,4...


        */

        for (int x = 1; x * (x + 1) / 2 <= n; x++){
            int v = x * (x + 1) / 2;
            if ((n - v) % x == 0) ++count;
        }
        return count;
    }
};