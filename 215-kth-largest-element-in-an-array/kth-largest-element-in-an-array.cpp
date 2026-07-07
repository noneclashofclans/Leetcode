class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // convert the array to max heap
        // find the kth largest value
        priority_queue<int> pq;

        for(auto x : nums){
            pq.push(x);
        }

        for (int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top();
    }
};