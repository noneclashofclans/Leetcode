class Solution {
public:

    long long square(int a){
        return a*a;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // we can get max value, if the smaller number will be at the odd index and 
        // larger number will be at the even index

        vector<long long> squares(n, 0);
        for (int i = 0; i < n; i++){
            squares[i] = square(nums[i]);
        }

        sort(squares.begin(), squares.end());

    
        long long sum = 0;

        for (int i = n/2; i < n; i++){
            sum += squares[i];
        }

        for (int j = 0; j < n/2; j++){
            sum -= squares[j];
        }

        return sum;
    }
};