class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        // vector<int> org(n, 0);
        // int minVal = *min_element(target.begin(), target.end());

        // for (int x : org){
        //     x += minVal;
        // }

        // // 1, 1, 1, 1, 1
        // int ops = 1;
        // bool completed = false;

        // int i = 0;
        // for (; i < n; i++){
        //     if (target[i] == org[i]) continue;
        //     else{
        //         int diff = target[i] - org[i];
        //         if (diff == 1){
        //             org[i]++;
        //             ops++;
        //         }
        //         else if ((diff == 1) && i == n-1){
        //             org[i]++;
        //             ops++;
        //             i = 0;
        //         }
        //     }   
        // }
        // return ops;

        int ops = target[0];
        for (int i = 1; i < n; i++){
            if (target[i] > target[i-1]) ops += target[i] - target[i-1];
        }
        return ops;
    }
};