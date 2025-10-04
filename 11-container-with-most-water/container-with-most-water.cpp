class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int i = 0, j = n-1;
        int max_area = INT_MIN;

        while (i < j){
            int lh = height[i];
            int rh = height[j];

            if (lh < rh){
                max_area = max(max_area, (min(lh, rh) * (j-i)));
                i++;    
            }
            else if (lh > rh){
                max_area = max(max_area, (min(lh, rh) * (j-i)));
                j--;
            }
            else{
                max_area = max(max_area, (min(lh, rh) * (j-i)));
                i++;
                j--;
            }
        }
        return max_area;
    }
};