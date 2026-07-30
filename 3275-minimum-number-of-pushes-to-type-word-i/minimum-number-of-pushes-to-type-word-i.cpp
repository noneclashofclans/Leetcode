class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int cnt = 0;

        for (int i = 0; i < n; i++){
            cnt += i/8 + 1;
        }

        return cnt;
    }
};