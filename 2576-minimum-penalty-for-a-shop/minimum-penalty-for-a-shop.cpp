class Solution {
public:
    int bestClosingTime(string customers) {
        // If the shop is open, and no cust come, then pen += 1
        // If shop = closed and cust come, then pen += 1

        // 'Y' = cust come
        // Else not come

        // 0 <= j <= n

        int n = customers.size();

        int cur_pen = 0;

        for (int x : customers){
            if (x == 'Y'){
                cur_pen++; 
            }
            else cur_pen += 0;
        }

        int min_pen = cur_pen;
        int ans = 0;

        for (int j = 1; j <= n; j++){
            if (customers[j - 1] == 'Y'){
                cur_pen--;
            }
            else cur_pen += 1;

            if (cur_pen < min_pen){
                min_pen = cur_pen;
                ans = j;
            }
        }
        return ans;
    }   
};