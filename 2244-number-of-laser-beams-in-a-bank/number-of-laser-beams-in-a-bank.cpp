class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // int n = bank.size(); int m = bank[0].size();
        // vector<vector<char>>mat(n,vector<char>(m));
        
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++){
        //         mat[i][j] = bank[i][j];
        //     }
        // }
    
        // int cnt = 0;
        // int col = 0;
        // while (col < m){
        //     for (int i = 0; i < n; i++){
        //         if (mat[i][col] == '1'){
        //             cnt++;
        //         }
        //     }
        //     col++;
        // }
        // return cnt;

        int prev = 0, res = 0;
        for(const string& row : bank){
            int curr = count(row.begin(), row.end(), '1');

            if (curr > 0){
                res += prev * curr;
                prev = curr;
            }
        }
        return res;
    }
};