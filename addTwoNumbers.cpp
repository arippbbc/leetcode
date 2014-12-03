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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x = 0, inc = 0;
        ListNode *res = new ListNode(0); 
        ListNode *c = res;
        bool once = true;
        
        while(l1 && l2){
            x = l1->val + l2->val + inc;
            inc = x>=10?1:0;
            
            x = x%10;
            if(once){
                c->val = x;
                once = false;
            }
            
            else {
                ListNode *l = new ListNode(x); 
                c->next = l;
                c = l;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            x = l1->val + inc;
            inc = x>=10?1:0;
            
            x = x%10;
            ListNode *l = new ListNode(x); 
            c->next = l;
            c = l;

            l1 = l1->next;
        }
        
        while(l2){
            x = l2->val + inc;
            inc = x>=10?1:0;
            
            x = x%10;
            ListNode *l = new ListNode(x); 
            c->next = l;
            c = l;

            l2 = l2->next;
        }
        
        if(inc){
            ListNode *l = new ListNode(inc); 
            c->next = l;
        }
        return res;
    }
};
