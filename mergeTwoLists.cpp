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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode *res, *a, *b, *c;
        
        if(l1->val<=l2->val){
            res=l1; a=l1; b=l1->next; c=l2;
        }
        else{
            res=l2; a=l2; b=l2->next; c=l1;
        }
        
        while(b && c){
            if(b->val<=c->val){
                a->next = b;
                b = b->next;
                a = a->next;
            }
            else{
                a->next = c;
                c = c->next;
                a = a->next;
            }
        }
        
        if(b) a->next = b;
        if(c) a->next = c;
        
        return res;
    }
};
