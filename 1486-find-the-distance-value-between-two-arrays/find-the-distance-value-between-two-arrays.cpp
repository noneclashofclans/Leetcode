class Solution {
private:
    bool isAValidElement(vector<int>& arr2, int x, int d){

        int left = 0, right = arr2.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;

            if (abs(arr2[mid] - x) <= d){
                return false;
            }
            else if (arr2[mid] + d < x) left = mid + 1;
            else right = mid - 1;
        }

        return true;
    }   
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int resultDistance = 0;
        sort(arr2.begin(), arr2.end());

        for (int i = 0; i < arr1.size(); i++){
            bool valid = isAValidElement(arr2, arr1[i], d);
            if (valid) resultDistance++;
        }

        return resultDistance;
    }
};