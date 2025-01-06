class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n,0);
        if (n == 0) return ans;

         int leftBalls = 0, leftOps = 0;
    for (int i = 0; i < n; ++i) {
        ans[i] += leftOps;
        leftBalls += (boxes[i] == '1');
        leftOps += leftBalls;
    }

    int rightBalls = 0, rightOps = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] += rightOps;
        rightBalls += (boxes[i] == '1');
        rightOps += rightBalls;
    }

    return ans;
    }
};