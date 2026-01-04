class Solution {
public:
    pair<int, int> find_factors(int& a){
        int count = 0;
        int sum = 0;
        for (int i = 1; i * i <= a; i++){
            if (a % i == 0){
                count++;
                sum += i;
                if (i * i != a){
                    sum += a / i;
                    count++;
                }
            }
        }
        return {count, sum};
    }

    int sumFourDivisors(vector<int>& nums) {
        // we have to choose the divisor such that the remainder is 0
        int n = nums.size();
        int totalsum = 0;

        for (int x : nums){
           auto [cnt, s] = find_factors(x);
           if (cnt == 4) totalsum += s;
        }        
        return  totalsum;
    }
};