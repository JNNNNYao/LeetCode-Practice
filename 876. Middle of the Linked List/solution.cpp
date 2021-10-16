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
    ListNode* middleNode(ListNode* head) {
        ListNode *arr[100];
        ListNode *curr;
        int i = -1;
        for(curr=head; curr!=nullptr; curr=curr->next){
            i++;
            arr[i] = curr;
        }
        if(i == -1){
            return nullptr;
        }
        else if((i+1) % 2 == 0){   // even
            return arr[(i+1)/2];
        }
        else{   // odd
            return arr[i/2];
        }
    }
};