class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = 0;
        int maxVal = values[0];

        for (int j = 1; j < n; j++){
            maxScore = max(maxScore,maxVal + values[j] - j);

            maxVal = max(maxVal,values[j] + j);
        }
        return maxScore;
    }
};