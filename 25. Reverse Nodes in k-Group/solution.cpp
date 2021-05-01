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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        ListNode *new_head = head;
        for(int i = 1; i < k; i++){     // after for loop curr will be the new head
            if(new_head->next == NULL){ // k > length of list
                return head;
            }
            new_head = new_head->next;
        }
        ListNode *curr = head->next;
        ListNode *prev = head;
        ListNode *temp;
        for(int i = 1; i < k; i++){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(curr){
            head->next = reverseKGroup(curr, k);
        }
        else{
            head->next = NULL;
        }
        return new_head;
    }
};