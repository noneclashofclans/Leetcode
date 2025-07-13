class Solution {
public:
    // int mismatch_idx(vector<int>& pushed, vector<int>& popped){
    //     reverse(pushed.begin(), pushed.end());
    //     int n1 = pushed.size();
    //     int idex = -1;
    //     for (int i = n1-1; i >= 0; i--){
    //         if (pushed[i] != popped[i]){
    //             idex = i;
    //             break;
    //         }
    //     }
    //     return idex;
    // }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // find the mismatch-idx
        // int idx = mismatch_idx(pushed, popped);
        // int n = pushed.size();  
        // bool flag = false;

        // for (int i = idx; i >= 0; i--){
        //     int curr = idx, next = idx-1;
        //     int current_val = popped[curr];
        //     int next_val = pushed[next];
        //     if (current_val == next_val){
        //         curr--;
        //         next++;
        //         if (current_val == next_val){
        //             next -= 2;
        //             curr--;
        //             if (curr == 0){
        //                 flag = true;
        //                 break;
        //             }
        //         }
        //         else flag = false;
        //     }
        // }
        // return (flag == false ? false : true);

        stack<int> st;
        int j = 0;

        for (int element : pushed){
            st.push(element);
            while (!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};