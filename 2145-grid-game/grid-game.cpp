class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long res = LLONG_MAX;
        long long top_row_sum = 0;
        for (int i = 0; i < grid[0].size(); i++){
            top_row_sum += grid[0][i];
        }
        long long bottom_row_sum = 0;

        for (int i = 0; i < grid[0].size(); i++){
            top_row_sum -= grid[0][i];
            res = min(res,max(top_row_sum,bottom_row_sum));
            bottom_row_sum += grid[1][i];
        }
        return res;
    }
};