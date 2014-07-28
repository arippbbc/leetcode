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
    ListNode *deleteDuplicates(ListNode *head) {
        /* head==NULL has to be in front of head->next==NULL */
        if(head==NULL || head->next==NULL) return head;
        ListNode *front = head, *back = head->next;
        while(back){
            while(back && front->val==back->val){
                back=back->next;
            }
            front->next = back;
            front = back;
            if(front){
                back = front->next;
            }
        }
        return head;
    }
};
