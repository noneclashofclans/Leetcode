class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int opens= 0, close = 0; //stars = 0;

        for (int i = 0; i < n; i++){
            if (s[i] == '(') {opens++; close++; }
            else if (s[i] == ')') {close--; opens--; }
            else{
                opens--;
                close++;
            }


            if (opens < 0) opens = 0;
            if (close < 0) return false;
        }

        // if (opens - close == 0) return true;
        // else if (opens < close){
        //     if (stars > 0){
        //         opens += (close - stars);
        //     }

        //     if (opens - close == 0) return true;
        //     else return false;
        // }
        // else {
        //     if (stars > 0){
        //         close += (opens - stars);
        //     }

        //     if (abs(opens - close) == 0) return true;
        //     else return false;
        // }

        // return true;

        return opens == 0;
    }
};