/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int magic = 666666;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        for(ListNode *curr = head; curr != nullptr; curr = curr->next){
            if(curr->val == magic){
                return true;
            }
            curr->val = magic;
        }
        return false;
    }
};