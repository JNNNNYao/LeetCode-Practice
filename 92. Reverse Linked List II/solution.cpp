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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *left_node;
        ListNode *right_node;
        ListNode *before = NULL;
        ListNode *after = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *temp; // store curr->next
        int idx = 1;
        while(curr){
            temp = curr->next;
            if(idx == left-1){
                before = curr;
            }
            if(idx == left){
                left_node = curr;
            }
            if(idx > left && idx < right){
                curr->next = prev;
            }
            if(idx == right){
                right_node = curr;
                right_node->next = prev;
            }
            if(idx == right+1){
                after = curr;
            }
            prev = curr;
            curr = temp;
            idx++;
        }
        if(before){
            before->next = right_node;
            left_node->next = after;
            return head;
        }
        else{
            left_node->next = after;
            return right_node;
        }
    }
};