class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        
        // stack<int> numbers;
        // numbers.push(0);

        // if (n % 2 == 1) numbers.push(0);

        // for (int i = 1; i <= n/2; i++){
        //     numbers.push(i);
        //     numbers.push(-i);
        // }

        // while (!numbers.empty()){
        //     int top = numbers.top();
        //     ans.push_back(top);
        //     numbers.pop();
        // }

        int pairs = n/2;
        for (int i = 1; i <= pairs; i++){
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) ans.push_back(0);
        
        return ans;
    }
};