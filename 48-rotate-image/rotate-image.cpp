class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
        for (int i=0;i<(n+1)/2;i++){
            for(int j =0;j<n/2;j++){
                //start the 4 way swaps
                //pick up the bottom left variable and assign it to temp
                //temp = bottom left
                int temp = matrix[n-1-j][i];

                //bottom left = bottom right
                matrix[n-1-j][i] = matrix[n-1-i][n-j-1];

                //bottom right = top right
                matrix[n-1-i][n-j-1] = matrix[j][n-1-i];

                //top right = top left
                matrix[j][n-1-i] = matrix[i][j];

                //top left = temp
                matrix[i][j] = temp;
            }
        }
    }
};