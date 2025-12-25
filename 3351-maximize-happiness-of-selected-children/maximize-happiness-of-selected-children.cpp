class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long n = happiness.size();

        sort (happiness.begin(), happiness.end(), greater<int>());

        // 5 4 3 2 
        long long sum = 0;
        int t = 0;
        // while (i < n - 1 && k > 0){
        //     int chose = happiness[i];
        //     sum += chose;

        //     for (int idx = i + 1; idx < n; idx++){
        //         if (happiness[idx] == 0) continue;
        //         else happiness[idx]--;
        //     }

        //     i++;
        //     k--;
        // }

        for (int i = 0; i < k; i++){
            sum += max (happiness[i] - t , 0);

            t++;
        }
        return sum;
    }
};