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
        if(!headA || !headB) return NULL;
        
        int a=0, b=0;
        ListNode *tmpA = headA, *tmpB = headB;
        while(tmpA) { ++a; tmpA = tmpA->next; }
        while(tmpB) { ++b; tmpB = tmpB->next; }
        
        tmpA = headA; 
        tmpB = headB;
        if(a>b){
            for(int i=0; i!=a-b; ++i) tmpA = tmpA->next;
        }
        else {
            for(int i=0; i!=b-a; ++i) tmpB = tmpB->next;
        }
        
        while(tmpA){
            if(tmpA == tmpB) return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return NULL;
    }
};
