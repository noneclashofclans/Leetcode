class Solution {
public:
    int find_gcd (int a, int b){
        while (b){
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // vector<int> test (n - 1, 0);

        // for(int i = 0; i < n - 1; i++){
        //     int res = find_gcd(nums[i], nums[i + 1]);
        //     test[i] = res;
        // }

        // bool found = false;
        // int idx = -1;
        // for (int i = 0; i < n - 1; i++){
        //     if (i >= n - 1 && found == false) return -1;
        //     else{
        //         found = true;
        //         idx = i;
        //         break;
        //     }
        // }

        // int ops = 0;

        int total_gcd = nums[0];
        for(int i = 1; i < n; i++){
            total_gcd = find_gcd(total_gcd, nums[i]);
        }
        if(total_gcd != 1) return -1;

        int ones = 0;
        for(int x : nums) if(x == 1) ones++;
        if(ones > 0){
            return n - ones; 
        }

        int best = INT_MAX;
        for(int i = 0; i < n; i++){
            int g = nums[i];
            for(int j = i + 1; j < n; j++){
                g = find_gcd(g, nums[j]);
                if(g == 1){
                    best = min(best, j - i + 1);
                    break; 
                }
            }
        }

        return (best - 1) + (n - 1);

    }
};