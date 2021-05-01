/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *curr;
        curr = headA;
        while(curr){
            lenA++;
            curr = curr->next;
        }
        curr = headB;
        while(curr){
            lenB++;
            curr = curr->next;
        }
        if(lenA > lenB){
            ListNode *currA = headA, *currB = headB;
            for(int i = 0; i < lenA-lenB; i++){
                currA = currA->next;
            }
            for(int i = 0; i < lenB; i++){
                if(currA == currB){
                    return currA;
                }
                else{
                    currA = currA->next;
                    currB = currB->next;
                }
            }
            return nullptr;
        }
        else{
            ListNode *currA = headA, *currB = headB;
            for(int i = 0; i < lenB-lenA; i++){
                currB = currB->next;
            }
            for(int i = 0; i < lenA; i++){
                if(currA == currB){
                    return currA;
                }
                else{
                    currA = currA->next;
                    currB = currB->next;
                }
            }
            return nullptr;
        }
    }
};


