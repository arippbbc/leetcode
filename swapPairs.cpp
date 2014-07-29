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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *res = head->next;
        ListNode *cur=head, *pre=NULL, *next;
        // have to separate into two statements
        while(cur && cur->next){
            next = cur->next->next;
            cur->next->next = cur;
            if(pre) pre->next = cur->next;
            cur->next = next;
            pre = cur;
            cur = next;
        }
        return res;
    }
};
