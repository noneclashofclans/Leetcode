class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        //dont do sort here
        //at 0th index always, 0 is pushed in ans
        unordered_set<int> set_a, set_b;
        int common = 0;

        for (int i = 0; i <n; i++){
            set_a.insert(A[i]);
            set_b.insert(B[i]);

            if (set_b.count(A[i])) common++;

            if (set_a.count(B[i]) && B[i] != A[i]) common++;

            ans[i] = common;
        }

        return ans;
    }
};