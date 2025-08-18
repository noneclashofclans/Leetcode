class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        // vector<int> cashe_reserve(3, 0);
        int five = 0, ten = 0;

        for (int i = 0; i < n; i++){
            if (bills[i] == 5){
                five++;
            }
            else if (bills[i] == 10){
                if (five == 0) return false;
                ten++;
                five--;
            }
            else{
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;

    }
};