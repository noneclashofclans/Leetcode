class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int count = 0;
        int n = differences.size();

        vector<int> prefix_sum = {0};
        long long  curr_sum = 0;
        for (int diff : differences){
            curr_sum += diff;
            prefix_sum.push_back(curr_sum);
        }
        //Finding the min and max values in the prefix sum array
        long long min_val = *min_element(prefix_sum.begin(),prefix_sum.end());
        long long max_val = *max_element(prefix_sum.begin(),prefix_sum.end());

        long long min_startPoint = lower - min_val;
        long long max_startPoint = upper - max_val;

        long long result = max_startPoint - min_startPoint + 1;
        return result < 0 ? 0 : (int)result;

    }
};