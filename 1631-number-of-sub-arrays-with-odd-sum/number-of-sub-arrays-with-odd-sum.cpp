class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long count = 0;
        long long even = 1, odd = 0;
        const int mod = 1e9 + 7;
        long long sum = 0;

        for (int i = 0; i < n; i++){
            sum += arr[i];

            if (sum % 2 == 0){
                count += odd;
                even++;
            }   
            else{
                count += even;
                odd++;
            }
            count %= mod; 
        }

        return count;
    }
};