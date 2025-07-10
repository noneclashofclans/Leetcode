class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        // +ve: right, -ve: left
        // speed of all is same
        // 2 asteroids if +ve or -ve then they can never collide
        // big + small = big
        // same + same = both boom!

        stack<int> st;

        for (int curr : asteroids){
            bool boom = false;
            while (!st.empty() && curr < 0 && st.top() > 0){
                if (abs(curr) > st.top()){
                    st.pop();
                    continue;
                }
                else if (abs(curr) == st.top()){
                    st.pop();
                    boom = true;
                    break;
                }
                else{
                    boom = true;
                    break;
                }
                
            }
            if (!boom) st.push(curr);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};