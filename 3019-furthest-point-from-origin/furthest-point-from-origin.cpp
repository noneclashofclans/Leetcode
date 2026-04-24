class Solution {
public:
     // string defaultDirection = "right";
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int dis = 0;

        // for(int i = 0; i < n; i++){
        //     if (moves[i] == 'L'){
        //         defaultDirection = "left";
        //         dis--;
        //     }
        //     else if (moves[i] == '_'){
        //         if (defaultDirection == "right"){
        //             dis++;
        //         }
        //         else{
        //             dis--;
        //         }
        //     }
        //     else{
        //         defaultDirection = "left";
        //         dis--;
        //     }
        // }
        // return abs(dis);

        int left = 0, right = 0, dash = 0;

        for (int x : moves){
            if (x == 'L') left++;
            else if (x == 'R') right++;
            else dash++;
        }

        return abs(left-right)+dash;
    }
};