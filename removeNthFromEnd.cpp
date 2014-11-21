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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n<=0 || !head) return head;
        /* special case */
        if(n==1 && !head->next) return NULL;
        ListNode *t1 = head, *t2 = head;
        
        int i=0;
        while(t2->next && i<n){
            ++i;
            t2 = t2->next;
        }
        
        if(i==n-1) return head->next;
        
        while(t2->next){
            t1=t1->next;
            t2=t2->next;
        }
        
        t1->next = t1->next->next;
        return head;
    }
};
