class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, down = 0, right = 0, left = 0;

        for (int i = 0; i < moves.size(); i++){
            if (moves[i] == 'U'){
                up++;
            }
            else if (moves[i] == 'D'){
                down++;
            }
            else if (moves[i] == 'R'){
                right++;
            }
            else left++;
        }

        return (up - down == 0 && right - left == 0);
    }
};