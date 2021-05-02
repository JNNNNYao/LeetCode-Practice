/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *low = NULL;
        ListNode *low_pos;
        ListNode *high = NULL;
        ListNode *high_pos;
        ListNode *curr = head;
        while(curr){
            if(curr->val < x){
                if(low == NULL){
                    low = curr;
                    low_pos = curr;
                }
                else{
                    low_pos->next = curr;
                    low_pos = curr;
                }
            }
            else{
                if(high == NULL){
                    high = curr;
                    high_pos = curr;
                }
                else{
                    high_pos->next = curr;
                    high_pos = curr;
                }
            }
            curr = curr->next;
        }
        if(low == NULL){
            return high;
        }
        else{
            low_pos->next = high;
            if(high){
                high_pos->next = NULL;
            }
            return low;
        }
    }
};