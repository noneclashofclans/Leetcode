class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_length = board.size();
        int column_length = board[0].size();

        vector<unordered_set<char>> rows(9), columns(9), box(9);

        for (int i = 0; i < row_length; i++){
            for (int j = 0; j < column_length; j++){
                if (board[i][j] == '.') continue; //skip all the blank boxes
                int box_idx = (i/3)*3 + (j/3);
        
                if (rows[i].count(board[i][j]) || columns[j].count(board[i][j]) || box[box_idx].count(board[i][j])) {
                return false;
                }

                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                box[box_idx].insert(board[i][j]);
            }
        }
        return true;
    }
};