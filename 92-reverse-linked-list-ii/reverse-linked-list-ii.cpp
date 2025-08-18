class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        if (!head->next || left == right) return head;

        ListNode* ans = head;
        ListNode* start = head;
        ListNode* end = head;

        // int counter_start = 1; // head pe khada hai
        // int counter_end = 1;
        // bool reached_start = false;
        // bool reached_end = false;
        // while(start && end){
        //     if (!reached_start){
        //         start = start->next;
        //         counter_start++;
            
        //         if (counter_start == left){
        //             // left pahunch gaye hain
        //             reached_start = true;
        //         }  
        //     }

        //     if (!reached_end){
        //         end = end->next;
        //         counter_end++;
            
        //         if (counter_end == right){
        //             // right pahunch gaye hain
        //             reached_end = true;
        //         }  
        //     }
            
        //     if (reached_start && reached_end) break;
        // }

        // while (start < end){
        //     int left_val = start->val;
        //     int right_val = end->val;

        //     swap(left_val, right_val);

        //     start = start->next;
        //     end = end->back;
        // }

        for(int i = 1; i < left; i++){
            start = start->next;
        }

        for (int i = 1; i < right; i++){
            end = end->next;
        }

        while (start != end && end->next != start){
            swap(start->val, end->val);
            start = start->next;
            right--;

            ListNode* temp = head;
            for (int i = 1; i < right; i++){
                temp = temp->next;
            }
            end = temp;
        }

        return ans;
    }
};