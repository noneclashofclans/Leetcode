class Solution {
public:
   
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        ans[0].push_back({1});

        for (int start = 1; start < numRows; start++){
            ans[start].resize(start+1);
            ans[start][0] = 1;
            for (int j = 1; j < start; j++){        
                ans[start][j] = (ans[start-1][j-1] + ans[start-1][j]);
            }
            ans[start][start] = 1;
        }

        return ans;
    }
};